#pragma once
#include <conio.h>
#include "CombatSystem.h"
#include "Level.h"
#include "Map.h"

using namespace std;

// Global Variables
string PlayerName;
string PlayerStringInput;
int PlayerNumberInput;
bool InTown = false;
bool Moving = true;
bool InTavern = true;
bool GameOver = false;
bool InLevel = true;
bool isDone;
bool FinishedShopping = false;
bool ChoosingToStay = true;
bool choosingSkill;
int LevelNumber = 1;

// In Shop Senarios
void BuyItems(Shop& shop, Player& player) {
	int ItemSelector;
	int ItemCount;
	int ItemTotalCost;
	cout << "What would you like to buy? (0 - " << shop.getNumberOfItems(shop) << ")" << endl;
	shop.PrintShop(shop);
	cout << shop.getNumberOfItems(shop) << ". Nevermind" << endl;
	cin >> PlayerNumberInput;
	system("CLS");
	ItemSelector = PlayerNumberInput;
	if (ItemSelector < shop.getNumberOfItems(shop)) {
		shop.PrintItemDescription(shop, ItemSelector);
		cout << "How many would you like to buy?" << endl;
		cin >> PlayerNumberInput;
		system("CLS");
		ItemCount = PlayerNumberInput;
		ItemTotalCost = (shop.getItem(shop, ItemSelector).getValue()) * ItemCount;
		if (player.getGold() >= ItemTotalCost) {
			bool ConfirmingPurchase = true;
			while (ConfirmingPurchase == true) {
				cout << "Are you sure you want to make this purchase? (y/n)" << endl;
				shop.PrintItemDescription(shop, ItemSelector);
				cin >> PlayerStringInput;
				system("CLS");
				if (PlayerStringInput == "y") {
					player.setGold(player.getGold() - ItemTotalCost);
					shop.BuyItem(ItemSelector, ItemCount);
					while (ItemCount > 0) {
						player.AddItemToPlayerInventory(shop, ItemSelector);
						ItemCount--;
					}
					player.PrintStatus();
					player.PrintInventory();
					ConfirmingPurchase = false;
				}
				else if (PlayerStringInput == "n") {
					ConfirmingPurchase = false;
				}
				else {
					cout << "Invalid Input, Try Again..." << endl;
					ConfirmingPurchase = true;
				}
			}
		}
		else if (player.getGold() < ItemTotalCost) {
			cout << "Sorry, you do not have enough gold to buy that item." << endl;
		}
	}
	else if (ItemSelector > shop.getNumberOfItems(shop)) {
		cout << "Invalid Input, Try Again..." << endl;
	}
}
void SellItems(Shop& shop, Player& player) {
	int ItemSelector;
	int ItemCount;
	if (player.getInventorySize() > 0) {
		cout << "What would you like to sell? (0 - " << player.getInventorySize() << ")" << endl;
		player.PrintInventory();
		cout << player.getInventorySize() << ". Nevermind" << endl;
		cin >> PlayerNumberInput;
		system("CLS");
		ItemSelector = PlayerNumberInput;
		if (ItemSelector < player.getInventorySize()) {
			cout << "How many would you like to sell? " << endl;
			player.PrintItemDescription(ItemSelector);
			cin >> PlayerNumberInput;
			system("CLS");
			ItemCount = PlayerNumberInput;
			if (ItemCount <= player.getItem(ItemSelector).getCount() && player.getItem(ItemSelector).getIsEquipped() == false) {
				bool ConfirmingSell = true;
				while (ConfirmingSell == true) {
					player.PrintItemDescription(ItemSelector);
					cout << "Are you sure you want to sell this? (y/n)" << endl;
					cin >> PlayerStringInput;
					system("CLS");
					if (PlayerStringInput == "y") {
						player.setGold(player.getGold() + (player.getItem(ItemSelector).getValue() * ItemCount));
						if (ItemCount > player.getItem(ItemSelector).getCount()) {
							cout << "You do not have that many items to sell!" << endl;
							ConfirmingSell = false;
						}
						else {
							while (ItemCount > 0) {
								player.RemoveItemFromPlayerInventory(player, ItemSelector);
								ItemCount--;
							}
							player.PrintStatus();
							player.PrintInventory();
							ConfirmingSell = false;
						}
					}
					else if (PlayerStringInput == "n") {
						ConfirmingSell = false;
					}
					else {
						cout << "Invalid Input, Try Again" << endl;
						ConfirmingSell = true;
					}
				}
			}
			else if (ItemCount > player.getItem(ItemSelector).getCount()) {
				cout << "Sorry, you do not have enough items in your inventory." << endl;
			}
			else if (player.getItem(ItemSelector).getIsEquipped() == true) {
				cout << "Sorry, you cannot sell equipped items, please unequip before selling." << endl;
			}
		}
		else if (ItemSelector > player.getInventorySize()) {
			cout << "Invalid Input, Try Again..." << endl;
		}
	}
	else if (player.getInventorySize() == 0) {
		cout << "You have nothing to sell..." << endl;
	}
}
void OpenShop(Shop& shop, Player& player) {
	FinishedShopping = false;
	while (FinishedShopping == false) {
		cout << "====================" << endl;
		cout << "Welcome to " << shop.getName() << endl;
		cout << "====================" << endl;
		cout << "What would you like to do?\n1. Buy Items\n2. Sell Items\n3. Leave" << endl;
		cin >> PlayerNumberInput;
		switch (PlayerNumberInput) {
		case 1:
			BuyItems(shop, player);
			break;
		case 2:
			SellItems(shop, player);
			break;
		case 3:
			FinishedShopping = true;
			break;
		default:
			cout << "Invalid Input, Try Again..." << endl;
			break;
		}
	}
}
// Inventory Senario
void OpenInventory(Player& player) {
	int SkillSelector;
	int ItemSelector;
	system("CLS");
	cout << "====================\nInventory\n====================" << endl;
	cout << "1. Skills\n2. Items\n3. Stats\n4. Exit Inventory\n";
	cin >> PlayerNumberInput;
	switch (PlayerNumberInput) {
	case 1:
	{
		bool choosingSkill = true;
		while (choosingSkill == true) {
			cout << "You can choose a skill or exit your inventory. (0 - " << player.getNumberOfSkills() << ")" << endl;
			player.PrintEquippedSkills();
			player.PrintSkillPool();
			cout << player.getNumberOfSkills() << ". Exit Inventory" << endl;
			cin >> PlayerNumberInput;
			SkillSelector = PlayerNumberInput;
			if (PlayerNumberInput == player.getNumberOfSkills()) {
				cout << "Exiting Inventory..." << endl;
				choosingSkill = false;
				break;
			}
			else if (player.getSkill(SkillSelector).getIsUnlocked() == false) {
				cout << "That Skill is Locked!" << endl;
				cout << "Enter any letter to continue...";
				char input = _getch();
			}
			else {
				if (player.getSkill(SkillSelector).getIsUnlocked() == true && player.getSkill(SkillSelector).getIsEquipped() == false) {
					cout << player.getSkill(SkillSelector).getDiscription() << endl;
					cout << "Would you like to equip this skill? (y/n)" << endl;
					cin >> PlayerStringInput;
					if (PlayerStringInput == "y") {
						player.EquipSkill(SkillSelector);
						player.PrintEquippedSkills();
					}
					cout << "Enter any letter to continue...";
					char input = _getch();
				}
				else if (player.getSkill(SkillSelector).getIsUnlocked() == true && player.getSkill(SkillSelector).getIsEquipped() == true) {
					cout << player.getSkill(SkillSelector).getDiscription() << endl;
					cout << "Would you like to unequip this skill? (y/n)" << endl;
					cin >> PlayerStringInput;
					if (PlayerStringInput == "y") {
						player.UnequipSkill(SkillSelector);
						player.PrintEquippedSkills();
					}
					cout << "Enter any letter to continue...";
					char input = _getch();
				}
				else {
					cout << "Invalid Input, Try Again... " << endl;
					cout << "Enter any letter to continue...";
					char input = _getch();
				}
			}
		}
		break;
	}
	case 2:
	{
		cout << "You may choose an item or exit your inventory. (0 - " << player.getInventorySize() << ")" << endl;
		player.PrintEquippedItems();
		player.PrintInventory();
		cout << player.getInventorySize() << ". Exit Inventory" << endl;
		cin >> PlayerNumberInput;
		ItemSelector = PlayerNumberInput;
		if (ItemSelector < player.getInventorySize()) {
			player.PrintItemDescription(ItemSelector);
			if (player.getItem(ItemSelector).getType() == "Consumable") {
				cout << "Would you like to use this item? (y/n)" << endl;
				cout << player.getItem(ItemSelector).getDescription();
				cin >> PlayerStringInput;
				if (PlayerStringInput == "y") {
					player.RemoveItemFromPlayerInventory(player, ItemSelector);
					player.setUpdatingHealth(player.getUpdatingHealth() + player.getItem(ItemSelector).getHealth());
					if (player.getUpdatingHealth() > player.getHealth()) {
						player.setUpdatingHealth(player.getHealth());
					}
					player.setUpdatingMana(player.getUpdatingMana() + player.getItem(ItemSelector).getMana());
					if (player.getUpdatingMana() > player.getMana()) {
						player.setUpdatingMana(player.getMana());
					}
					player.setUpdatingSpeed(player.getUpdatingSpeed() + player.getItem(ItemSelector).getSpeed());
					if (player.getUpdatingSpeed() > player.getSpeed()) {
						player.setUpdatingSpeed(player.getSpeed());
					}
					player.setUpdatingStrength(player.getUpdatingStrength() + player.getItem(ItemSelector).getStrength());
					if (player.getUpdatingStrength() > player.getStrength()) {
						player.setUpdatingStrength(player.getStrength());
					}
				}
			}
			else if (player.getItem(ItemSelector).getType() == "Weapon" || player.getItem(ItemSelector).getType() == "Helmet" || player.getItem(ItemSelector).getType() == "Chestplate" || player.getItem(ItemSelector).getType() == "Leggings" || player.getItem(ItemSelector).getType() == "Boots") {
				if (player.getItem(ItemSelector).getIsEquipped() == false) {
					bool ChoosingEquip = true;
					while (ChoosingEquip == true) {
						cout << "Would you like to equip this item? (y/n)" << endl;
						cin >> PlayerStringInput;
						if (PlayerStringInput == "y") {
							player.EquipItem(ItemSelector);
							player.PrintEquippedItems();
							ChoosingEquip = false;
						}
						else if (PlayerStringInput == "n") {
							ChoosingEquip = false;
						}
						else {
							cout << "Invalid Input, Try Again..." << endl;
							cout << "Enter any letter to continue...";
							char input = _getch();
							ChoosingEquip = true;
						}
					}
				}
				else if (player.getItem(ItemSelector).getIsEquipped() == true) {
					bool ChoosingEquip = true;
					while (ChoosingEquip == true) {
						cout << "Would you like to unequip this item? (y/n)" << endl;
						cin >> PlayerStringInput;
						if (PlayerStringInput == "y") {
							player.UnequipItem(ItemSelector);
							player.PrintEquippedItems();
							ChoosingEquip = false;
						}
						else if (PlayerStringInput == "n") {
							ChoosingEquip = false;
						}
						else {
							cout << "Invalid Input, Try Again..." << endl;
							cout << "Enter any letter to continue...";
							char input = _getch();
							ChoosingEquip = true;
						}
					}
				}
			}
		}
		else if (ItemSelector > player.getInventorySize()) {
			cout << "Invalid Input, Try Again..." << endl;
			cout << "Enter any letter to continue...";
			char input = _getch();
		}
		break;
	}
	case 3:
	{
		choosingSkill = true;
		while (choosingSkill == true) {
			player.PrintStats();
			cout << "1. Assign Skill Points\n2. Reset Stat Points\n3. Exit\n";
			cin >> PlayerNumberInput;
			switch (PlayerNumberInput) {
			case 1:
			{
				cout << "Choose the stat you would like to assign a stat point to.\n1. Health\n2. Mana\n3. Speed\n4. Strength" << endl;
				cin >> PlayerNumberInput;
				if (PlayerNumberInput == 1) {
					cout << "How many stat points would you like to assign to health?" << endl;
					cin >> PlayerNumberInput;
					if (PlayerNumberInput <= player.getStatPoints()) {
						player.addHealthPoint(PlayerNumberInput);
						player.subStatPoint(PlayerNumberInput);
						player.setHealth(player.getHealth() + (PlayerNumberInput * 5));
					}
					else {
						cout << "You do not have that many stat points to assign." << endl;

					}
				}
				else if (PlayerNumberInput == 2) {
					cout << "How many stat points would you like to assign to mana?" << endl;
					cin >> PlayerNumberInput;
					if (PlayerNumberInput <= player.getStatPoints()) {
						player.addManaPoint(PlayerNumberInput);
						player.subStatPoint(PlayerNumberInput);
						player.setMana(player.getMana() + (PlayerNumberInput * 5));
					}
					else {
						cout << "You do not have that many stat points to assign." << endl;
					}
				}
				else if (PlayerNumberInput == 3) {
					cout << "How many stat points would you like to assign to speed?" << endl;
					cin >> PlayerNumberInput;
					if (PlayerNumberInput <= player.getStatPoints()) {
						player.addSpeedPoint(PlayerNumberInput);
						player.subStatPoint(PlayerNumberInput);
						player.setSpeed(player.getSpeed() + (PlayerNumberInput * 2));
					}
					else {
						cout << "You do not have that many stat points to assign." << endl;
					}
				}
				else if (PlayerNumberInput == 4) {
					cout << "How many stat points would you like to assign to strength?" << endl;
					cin >> PlayerNumberInput;
					if (PlayerNumberInput <= player.getStatPoints()) {
						player.addStrengthPoint(PlayerNumberInput);
						player.subStatPoint(PlayerNumberInput);
						player.setStrength(player.getStrength() + (PlayerNumberInput * 2));
					}
					else {
						cout << "You do not have that many stat points to assign." << endl;
					}
				}
				break;
			}
			case 2:
			{
				cout << "Are you sure you want to reset all your stat points? (y/n)" << endl;
				cin >> PlayerStringInput;
				if (PlayerStringInput == "y") {
					int numberofpoints = player.getHealthPoints() + player.getManaPoints() + player.getSpeedPoints() + player.getStrengthPoints();
					player.addStatPoint(numberofpoints);
					player.setHealth(player.getHealth() - (player.getHealthPoints() * 10));
					player.setMana(player.getMana() - (player.getManaPoints() * 10));
					player.setSpeed(player.getSpeed() - (player.getSpeedPoints() * 10));
					player.setStrength(player.getStrength() - (player.getStrengthPoints() * 10));
					player.setHealthPoint(0);
					player.setManaPoint(0);
					player.setSpeedPoint(0);
					player.setStrengthPoint(0);
				}
				break;
			}
			case 3:
			{
				choosingSkill = false;
				break;
			}
			default:
			{
				cout << "Invalid Input..." << endl;
				cout << "Enter any letter to continue...";
				char input = _getch();
				break;
			}
			}
		}
		
	}
	case 4:
	{
		cout << "Exiting Inventory..." << endl;
		cout << "Enter any letter to continue...";
		char input = _getch();
		break;
	}
	default:
	{
		cout << "Invalid Input, Try Again... " << endl;
		cout << "Enter any letter to continue...";
		char input = _getch();
		break;
	}
	}
}
// Quit Game
void QuitGame() {
	bool ChoosingCase5 = true;
	while (ChoosingCase5 == true) {
		cout << "Are you sure you want to quit the game? (y/n)" << endl;
		cin >> PlayerStringInput;
		if (PlayerStringInput == "y") {
			cout << "Closing Game... " << endl;
			InTown = false;
			InLevel = false;
			GameOver = true;
			ChoosingCase5 = false;
		}
		else if (PlayerStringInput == "n") {
			ChoosingCase5 = false;
		}
		else {
			cout << "Invalid Input, Try Again..." << endl;
			ChoosingCase5 = true;
		}
	}
}
// Switching from moving to the different senarios
void Senarios(Player& player, Level& level, CombatSystem& combat, string check, int x, int y) {
	if (check == "dot") {
		if (player.getUpdatingHealth() > 0) {
			int chance = rand() % 100;
			if (chance <= 10) {
				InCombat(combat, level, player);
			}
		}
	}
	if (check == "space" || check == "dot") {
		system("CLS");
		player.setPlayerLocation(x, y);
	}
	else if (check == "town") {
		system("CLS");
		InTown = true;
		Moving = false;
	}
	else if (check == "boss") {
		if (player.getUpdatingHealth() > 0) {
			if (player.getLevel() >= level.getEnemy(level, 3).getLevel()) {
				system("CLS");
				BossBattle(combat, level, player);
			}
			else {
				cout << "Your level needs to be equal to or higher than " << level.getEnemy(level, 3).getLevel() << " to fight the boss." << endl;
				cout << "Enter any letter to continue...";
				char input = _getch();
			}
		}
	}
	else if (check == "level") {
		if (LevelNumber != 0) {
			cout << "Would you like to enter the next level or go to the previous level? (1 or 2)\n1. Enter the next level.\n2. Go to the previous level." << endl;
			cin >> PlayerNumberInput;
		}
		else {
			cout << "Would you like to enter the next level? (enter 1)" << endl;
			cin >> PlayerNumberInput;
		}
		if (PlayerNumberInput == 1) {
			if (level.getIsBossDefeated() == true) {
				if (LevelNumber != 5) {
					cout << "Are you sure you want to enter the next level? (y/n)" << endl;
					cin >> PlayerStringInput;
					if (PlayerStringInput == "y") {
						Moving = false;
						InLevel = false;
						LevelNumber = LevelNumber + 1;
					}
				}
			}
			else {
				cout << "You need to defeat the boss before going to the next level. " << endl;
				cout << "Enter any letter to continue...";
				char input = _getch();
			}
		}
		else if (PlayerNumberInput == 2 && LevelNumber != 0) {
			cout << "Are you sure you want to enter the previous level? (y/n)" << endl;
			cin >> PlayerStringInput;
			if (PlayerStringInput == "y") {
				Moving = false;
				InLevel = false;
				LevelNumber = LevelNumber - 1;
			}
		}
	}
	if (check == "level" && LevelNumber == 5 && level.getIsBossDefeated() == true) {
		cout << " Congratulations you beat the game!" << endl;
		exit(1);
	}
}
// When Moving
void Move(Player& player, Map& map, Level& level, CombatSystem& combat) {
	string check;
	cout << "Level: " << level.getLevelNumber() << "\tLevel Name: " << level.getLevelName() << endl;
	cout << "INFO: Press I to open inventory, Q to quit game, WASD to move." << endl;
	player.PrintStatus();
	map.DisplayMap(player);
	char PlayerMovementInput;
	switch (_getch()) {
	case 'w':
		check = map.CheckTile(player.getPlayerX(), player.getPlayerY() - 1);
		Senarios(player, level, combat, check, player.getPlayerX(), player.getPlayerY() - 1);
		system("CLS");
		break;
	case 'a':
		check = map.CheckTile(player.getPlayerX() - 1, player.getPlayerY());
		Senarios(player, level, combat, check, player.getPlayerX() - 1, player.getPlayerY());
		system("CLS");
		break;
	case 's':
		check = map.CheckTile(player.getPlayerX(), player.getPlayerY() + 1);
		Senarios(player, level, combat, check, player.getPlayerX(), player.getPlayerY() + 1);
		system("CLS");
		break;
	case 'd':
		check = map.CheckTile(player.getPlayerX() + 1, player.getPlayerY());
		Senarios(player, level, combat, check, player.getPlayerX() + 1, player.getPlayerY());
		system("CLS");
		break;
	case 'i':
		OpenInventory(player);
		system("CLS");
		break;
	case 'q':
		cout << "Quiting game... " << endl;
		exit(1);
	default:
		system("CLS");
	}
}
// In Town
void Town(Player& player, Level& levelnumber) {
	Shop Weaponary = levelnumber.getShop(levelnumber, 0);
	Shop Armory = levelnumber.getShop(levelnumber, 1);
	Shop Tavern = levelnumber.getShop(levelnumber, 2);
	cout << "====================" << endl;
	cout << "Welcome to " << levelnumber.getTownName() << endl;
	cout << "====================" << endl;
	cout << "What will you do?" << endl;
	cout << "1. Go to " << Weaponary.getName() << "\n2. Go to " << Armory.getName() << "\n3. Go to " << Tavern.getName() << "\n4.Open Inventory\n5.Exit Town\n6.Quit Game" << endl;
	cin >> PlayerNumberInput;
	switch (PlayerNumberInput) {
	case 1:
		OpenShop(Weaponary, player);
		break;
	case 2:
		OpenShop(Armory, player);
		break;
	case 3:
		InTavern = true;
		while (InTavern == true) {
			cout << "====================" << endl;
			cout << "Welcome to " << levelnumber.getShop(levelnumber, 2).getName() << endl;
			cout << "====================" << endl;
			cout << "What will you like to do?\n1. Rest\n2. Buy Items\n3. Leave" << endl;
			cin >> PlayerNumberInput;
			system("CLS");
			switch (PlayerNumberInput) {
			case 1:
				cout << "You got a good nights rest and restored all your health and mana." << endl;
				player.setUpdatingHealth(player.getHealth());
				player.setUpdatingMana(player.getMana());
				break;
			case 2:
				BuyItems(Tavern, player);
				InTavern = true;
				break;
			case 3:
				InTavern = false;
				break;
			default:
				cout << "Invalid Input, Try Again..." << endl;
				InTavern = true;
				break;
			}
		}
		break;
	case 4:
		if (player.getInventorySize() > 0) {
			OpenInventory(player);
		}
		else {
			player.PrintInventory();
		}
		break;
	case 5:
		cout << "Exiting Town... " << endl;
		system("CLS");
		InTown = false;
		Moving = true;
		break;
	case 6:
		QuitGame();
		break;
	default:
		cout << "Invalid Input, Try Again..." << endl;
		break;
	}
}
// Main Loop
void RunGame(Player& player, Level& levelnumber, Map& map, CombatSystem& combat) {
	map.FindTile(player);
	while (InLevel == true) {
		Moving = true;
		while (Moving == true) {
			Move(player, map, levelnumber, combat);
		}
		while (InTown == true) {
			Town(player, levelnumber);
		}
	}
}