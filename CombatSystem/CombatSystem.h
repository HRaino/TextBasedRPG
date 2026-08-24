#pragma once
#include <iostream>
#include <string>

#include "Player.h"
#include "Enemy.h"
#include "Level.h"

using namespace std;

// Global Variables
int enemyindex = 0;
int hploss = 0;
string playerinput;
int playernumberinput;
int itemselector;

class CombatSystem {
public:
	void PrintStatus(Player& player, int enemyindex);
	void EnemyDefaultAttack(Player& player, int enemyindex);
	void PlayerDefaultAttack(Player& player, int enemyindex);
	void InCombat(Level& levelnumber, Player& player);
	void BossBattle(Level& levelnumber, Player& player);
	void AddEnemyToBattle(Level& levelnumber, int i);
	void RollEnemy(Level& levelnumber, Player& player, int enemyindex);
	void CalculateResults(Player& player, int enemyindex);
	void PlayerUseSkill(Player& player, Skill skill, int enemyindex);
	void EnemyUseSkill(Player& player, int enemyindex);
	void EnemyTurn(Player& player, int enemyindex);
	// Setters
	void setInCombat(bool InCombat) { inCombat = InCombat; }
	void setIsPlayerTurn(bool IsPlayerTurn) { isPlayerTurn = IsPlayerTurn; }
	// Getters
	bool getInCombat() { return inCombat; }
private:
	bool isPlayerTurn;
	bool inCombat;
	vector<Enemy> battle;
};
void CombatSystem::RollEnemy(Level& levelnumber, Player& player, int enemyindex) { // Rolls a random enemy from the given level and makes sure that the enemy is equal to or less than the player's level
	bool ChooseEnemy = false;
	int SelectEnemy = rand() % levelnumber.getNumberOfEnemies(levelnumber);
	AddEnemyToBattle(levelnumber, SelectEnemy);
	while (ChooseEnemy == false) {
		if ((battle.at(enemyindex).getLevel() > player.getLevel() + 5) || (battle.at(enemyindex).getType() == "boss")) {
			battle.pop_back();
			int SelectEnemy = rand() % levelnumber.getNumberOfEnemies(levelnumber);
			AddEnemyToBattle(levelnumber, SelectEnemy);
		}
		else if (battle.at(enemyindex).getLevel() <= player.getLevel() + 5) {
			ChooseEnemy = true;
		}
	}
}
void CombatSystem::AddEnemyToBattle(Level& levelnumber, int i) { // Adds an Enemy from the given level to the Battle
	Enemy ChosenEnemy = levelnumber.getEnemy(levelnumber, i);
	battle.push_back(ChosenEnemy);
}
void CombatSystem::PrintStatus(Player& player, int enemyindex) { // Prints Player and Enemy Information
	cout << "==================================================" << endl;
	cout << "Player: " << player.getName() << "\t\t\tEnemy: " << battle.at(enemyindex).getName() << endl;
	cout << "Health: " << player.getUpdatingHealth() << " / " << player.getHealth() << "\t\t\tHealth: " << battle.at(enemyindex).getUpdatingHealth() << " / " << battle.at(enemyindex).getHealth() << endl;
	cout << "Mana: " << player.getUpdatingMana() << " / " << player.getMana() << "\t\t\tMana: " << battle.at(enemyindex).getUpdatingMana() << " / " << battle.at(enemyindex).getMana() << endl;
	cout << "==================================================" << endl;
}
void CombatSystem::EnemyDefaultAttack(Player& player, int enemyindex) { // Calculates Enemy Attack Damage and decreases player health
	int minDamage = battle.at(enemyindex).getMinDmg();
	int maxDamage = battle.at(enemyindex).getMaxDmg();
	int DamageDone = minDamage + (rand() % (maxDamage - minDamage + 1));
	int result = rand() % 6;
	if (result <= 3) {
		cout << endl << battle.at(enemyindex).getName() << battle.at(enemyindex).getAdjective() << " you for " << DamageDone << " damage." << endl;
		player.setUpdatingHealth(player.getUpdatingHealth() - DamageDone);
	}
	else if (result == 5) {
		DamageDone = DamageDone * 2;
		cout << "\nCRITICAL HIT! " << battle.at(enemyindex).getName() << battle.at(enemyindex).getAdjective() << " " << player.getName() << " for " << DamageDone << " damage." << endl;
		player.setUpdatingHealth(player.getUpdatingHealth() - DamageDone);
	}
	else if (result > 3) {
		cout << endl << battle.at(enemyindex).getName() << " attempts to" << battle.at(enemyindex).getAdjective() << " " << player.getName() << " and misses..." << endl;
	}
}
void CombatSystem::PlayerDefaultAttack(Player& player, int enemyindex) { // Calculates Player Attack Damage and decreases enemy health
	int result = rand() % 6;
	int Damage = rand() % player.getUpdatingStrength() + (player.getUpdatingStrength() - 10);
	if (result <= 3) {
		int DamageDone = player.getUpdatingStrength();
		cout << "\nYou attack the " << battle.at(enemyindex).getName() << " for " << DamageDone << " damage." << endl;
		battle.at(enemyindex).setUpdatingHealth(battle.at(enemyindex).getUpdatingHealth() - DamageDone);
	}
	else if (result == 5) {
		int DamageDone = player.getUpdatingStrength() * 2;
		cout << "\nCRITICAL HIT! You attack the " << battle.at(enemyindex).getName() << " for " << DamageDone << " damage." << endl;
		battle.at(enemyindex).setUpdatingHealth(battle.at(enemyindex).getUpdatingHealth() - DamageDone);
	}
	else if (result > 3) {
		cout << "\nYou missed..." << endl;
	}
}
void CombatSystem::PlayerUseSkill(Player& player, Skill skill, int enemyindex) {
	if (skill == player.getSkill(0)) {
		cout << "Basic Heal was used and has restored 10 health points to the user." << endl;
		player.setUpdatingHealth(player.getUpdatingHealth() + player.getSkill(0).getHealth());
		player.setUpdatingMana(player.getUpdatingMana() - player.getSkill(0).getManaCost());
		if (player.getUpdatingMana() > player.getHealth()) {
			player.setUpdatingMana(player.getHealth());
		}
	}
	else if (skill == player.getSkill(1)) {
		cout << "Ensnare was used on the target and their speed has been set to 0." << endl;
		battle.at(enemyindex).setSpeed(1);
		player.setUpdatingMana(player.getUpdatingMana() - player.getSkill(1).getManaCost());
	}
	else if (skill == player.getSkill(2)) {
		int healthrestored = player.getHealth() / player.getSkill(2).getHealth();
		cout << "Advanced Heal was used and has restored " << healthrestored << " health." << endl;
		player.setUpdatingHealth(player.getUpdatingHealth() + healthrestored);
		player.setUpdatingMana(player.getUpdatingMana() - player.getSkill(2).getManaCost());
	}
	else if (skill == player.getSkill(3)) {
		int damage = player.getUpdatingStrength() * 2;
		cout << "Fireball was used and has dealt " << damage << " damage." << endl;
		battle.at(enemyindex).setUpdatingHealth(battle.at(enemyindex).getUpdatingHealth() - damage);
		player.setUpdatingMana(player.getUpdatingMana() - player.getSkill(3).getManaCost());
	}
	else if (skill == player.getSkill(4)) {
		int damage = player.getUpdatingStrength() * 5;
		cout << "Shadow Slash was used and has dealt " << damage << " damage." << endl;
		battle.at(enemyindex).setUpdatingHealth(battle.at(enemyindex).getUpdatingHealth() - damage);
		player.setUpdatingMana(player.getUpdatingMana() - player.getSkill(4).getManaCost());
	}
	else if (skill == player.getSkill(5)) {
		int damage = player.getUpdatingStrength() * 10;
		cout << "Destruction was used and has dealt " << damage << " damage." << endl;
		battle.at(enemyindex).setUpdatingHealth(battle.at(enemyindex).getUpdatingHealth() - damage);
		player.setUpdatingMana(player.getUpdatingMana() - player.getSkill(5).getManaCost());
	}
}
void CombatSystem::EnemyUseSkill(Player& player, int enemyindex) {
	if (battle.at(enemyindex).getStage() == 0) {
		cout << battle.at(enemyindex).getName() << " uses " << player.getSkill(0).getName() << " restoring " << player.getSkill(0).getHealth() << " health points." << endl;
		battle.at(enemyindex).setUpdatingHealth(battle.at(enemyindex).getUpdatingHealth() + player.getSkill(0).getHealth());
		battle.at(enemyindex).setUpdatingMana(battle.at(enemyindex).getUpdatingMana() - player.getSkill(0).getManaCost());
		if (battle.at(enemyindex).getUpdatingHealth() > battle.at(enemyindex).getHealth()) {
			battle.at(enemyindex).setUpdatingHealth(battle.at(enemyindex).getHealth());
		}
	}
	else if (battle.at(enemyindex).getStage() == 1) {
		cout << battle.at(enemyindex).getName() << " uses " << player.getSkill(1).getName() << " reducing your speed to 0 for the rest of the battle." << endl;
		player.setUpdatingSpeed(1);
		battle.at(enemyindex).setUpdatingMana(battle.at(enemyindex).getUpdatingMana() - player.getSkill(1).getManaCost());
	}
	else if (battle.at(enemyindex).getStage() == 2) {
		int healthrestored = battle.at(enemyindex).getHealth() / player.getSkill(2).getHealth();
		cout << battle.at(enemyindex).getName() << " uses " << player.getSkill(2).getName() << " restoring " << healthrestored << " health points." << endl;
		battle.at(enemyindex).setUpdatingHealth(battle.at(enemyindex).getUpdatingHealth() + healthrestored);
		battle.at(enemyindex).setUpdatingMana(battle.at(enemyindex).getUpdatingMana() - player.getSkill(2).getManaCost());
		if (battle.at(enemyindex).getUpdatingHealth() > battle.at(enemyindex).getHealth()) {
			battle.at(enemyindex).setUpdatingHealth(battle.at(enemyindex).getHealth());
		}
	}
	else if (battle.at(enemyindex).getStage() == 3) {
		int damage = battle.at(enemyindex).getMaxDmg() * 2;
		cout << battle.at(enemyindex).getName() << " uses " << player.getSkill(3).getName() << " dealing " << damage << " damage." << endl;
		battle.at(enemyindex).setUpdatingMana(battle.at(enemyindex).getUpdatingMana() - player.getSkill(3).getManaCost());
		player.setUpdatingHealth(player.getUpdatingHealth() - damage);
	}
	else if (battle.at(enemyindex).getStage() == 4) {
		int damage = battle.at(enemyindex).getMaxDmg() * 5;
		cout << battle.at(enemyindex).getName() << " uses " << player.getSkill(4).getName() << " dealing " << damage << " damage." << endl;
		battle.at(enemyindex).setUpdatingMana(battle.at(enemyindex).getUpdatingMana() - player.getSkill(4).getManaCost());
		player.setUpdatingHealth(player.getUpdatingHealth() - damage);
	}
	else if (battle.at(enemyindex).getStage() == 5) {
		int damage = battle.at(enemyindex).getMaxDmg() * 10;
		cout << battle.at(enemyindex).getName() << " uses " << player.getSkill(5).getName() << " dealing " << damage << " damage." << endl;
		battle.at(enemyindex).setUpdatingMana(battle.at(enemyindex).getUpdatingMana() - player.getSkill(5).getManaCost());
		player.setUpdatingHealth(player.getUpdatingHealth() - damage);
	}
}
void CombatSystem::EnemyTurn(Player& player, int enemyindex) {
	if (battle.at(enemyindex).getType() == "boss") {
		int random = rand() % 101;
		if (random > 80) {
			if (battle.at(enemyindex).getUpdatingMana() > player.getSkill(battle.at(enemyindex).getStage()).getManaCost()) {
				EnemyUseSkill(player, enemyindex);
			}
			else {
				EnemyDefaultAttack(player, enemyindex);
			}
		}
		else {
			EnemyDefaultAttack(player, enemyindex);
		}
	}
	else if (battle.at(enemyindex).getType() == "normal") {
		EnemyDefaultAttack(player, enemyindex);
	}
}
void CombatSystem::CalculateResults(Player& player, int enemyindex) {
	int totalexp = 0;
	int totalgold = 0;
	cout << "========================================\nResults:\n========================================" << endl;
	for (int i = 0; i <= enemyindex; i++) {
		int exp = battle.at(i).getLevel() * 2;
		int gold = rand() % battle.at(i).getLevel();
		totalgold = totalgold + gold;
		totalexp = totalexp + exp;
		cout << "Defeated " << battle.at(i).getName() << " (+" << exp << " experience points)" << endl;
		if (battle.at(i).getType() == "boss") {
			cout << "Unlocked next level and skill." << endl;
		}
	}
	cout << "Total Experience Points Gained: " << totalexp << endl;
	cout << "Total Gold Gained: " << totalgold << endl;
	cout << "========================================" << endl;
	player.setGold(player.getGold() + totalgold);
	player.SetExperiencePoints(player.getExperiencePoints() + totalexp);
	cout << "Enter any letter to continue...";
	char input = _getch();
}
void CombatSystem::BossBattle(Level& levelnumber, Player& player) {
	inCombat = true;
	enemyindex = 0;
	battle.push_back(levelnumber.getEnemy(levelnumber, 3));
	while (inCombat == true) {
		PrintStatus(player, enemyindex);
		int input;
		cout << "==================================================\nYou are in a Boss Battle, what will you do?\n\n1. Attack\n2. Skill 1\n3. Skill 2\n4. Run Away\n==================================================" << endl;
		cin >> input;
		system("CLS");
		switch (input) {
		case 1:
		{
			if (player.getUpdatingSpeed() >= battle.at(enemyindex).getSpeed()) {
				PlayerDefaultAttack(player, enemyindex);
				if (battle.at(enemyindex).getUpdatingHealth() > 0) {
					EnemyTurn(player, enemyindex);
				}
			}
			else {
				EnemyTurn(player, enemyindex);
				if (player.getUpdatingHealth() > 0) {
					PlayerDefaultAttack(player, enemyindex);
				}
			}
			break;
		}
		case 2:
		{
			if (player.getUpdatingSpeed() >= battle.at(enemyindex).getSpeed()) {
				if (player.getEquippedSkill(0).getIsUnlocked() == true) {
					cout << "You Choose to use " << player.getEquippedSkill(0).getName() << endl;
					PlayerUseSkill(player, player.getEquippedSkill(0), enemyindex);
					EnemyTurn(player, enemyindex);
				}
				else {
					cout << "You do not have an equipped skill in slot 1! " << endl;
				}
			}
			else {
				if (player.getEquippedSkill(0).getIsUnlocked() == true) {
					EnemyTurn(player, enemyindex);
					cout << "You Choose to use " << player.getEquippedSkill(0).getName() << endl;
					PlayerUseSkill(player, player.getEquippedSkill(0), enemyindex);
				}
				else {
					cout << "You do not have an equipped skill in slot 1! " << endl;
				}
			}
			break;
		}
		case 3:
		{
			if (player.getUpdatingSpeed() >= battle.at(enemyindex).getSpeed()) {
				if (player.getEquippedSkill(1).getIsUnlocked() == true) {
					cout << "You Choose to use " << player.getEquippedSkill(1).getName() << endl;
					PlayerUseSkill(player, player.getEquippedSkill(1), enemyindex);
				}
				else {
					cout << "You do not have an equipped skill in slot 2! " << endl;
				}
			}
			else {
				if (player.getEquippedSkill(1).getIsUnlocked() == true) {
					cout << "You Choose to use " << player.getEquippedSkill(1).getName() << endl;
					PlayerUseSkill(player, player.getEquippedSkill(1), enemyindex);
				}
				else {
					cout << "You do not have an equipped skill in slot 2! " << endl;
				}
			}
			break;
		}
		case 4:
		{
			cout << "You ran away..." << endl;
			inCombat = false;
			battle.clear();
			player.setUpdatingSpeed(player.getSpeed());
			player.setUpdatingStrength(player.getStrength());
			break;
		}
		default:
		{
			cout << "That is not an option..." << endl;
			break;
		}
		}
		if (battle.at(enemyindex).getUpdatingHealth() <= 0) {
			inCombat = false;
			CalculateResults(player, enemyindex);
			player.UnlockSkill(battle.at(enemyindex).getStage());
			levelnumber.setIsBossDefeated(true);
			battle.clear();
			player.setUpdatingSpeed(player.getSpeed());
			player.setUpdatingStrength(player.getStrength());
		}
		if (player.getUpdatingHealth() <= 0) {
			inCombat = false;
			battle.clear();
			player.setUpdatingHealth(0);
			int playergold = player.getGold() - (player.getGold() / 10);
			player.setGold(playergold);
			player.setUpdatingSpeed(player.getSpeed());
			player.setUpdatingStrength(player.getStrength());
			cout << "You have run out of health! Use potions or go to a tavern and rest to restore your health. " << endl;
		}
	}
}
void CombatSystem::InCombat(Level& levelnumber, Player& player) {
	system("CLS");
	inCombat = true;
	enemyindex = 0;
	int i = 0;
	int numberofenemies = rand() % 3 + 1;
	while (i < numberofenemies) {
		RollEnemy(levelnumber, player, i);
		i++;
	}
	while (inCombat == true) {
		PrintStatus(player, enemyindex);
		int input;
		cout << "Round: " << enemyindex + 1 << " / " << battle.size() << endl;
		cout << "==================================================\nYou are in Combat, what will you do?\n\n1. Attack\n2. Skill 1\n3. Skill 2\n4. Open Inventory\n5. Run Away\n==================================================" << endl;
		cin >> input;
		system("CLS");
		switch (input) {
		case 1:
			if (player.getUpdatingSpeed() >= battle.at(enemyindex).getSpeed()) {
				PlayerDefaultAttack(player, enemyindex);
				if (battle.at(enemyindex).getUpdatingHealth() > 0) {
					EnemyTurn(player, enemyindex);
				}
			}
			else {
				EnemyDefaultAttack(player, enemyindex);
				if (player.getUpdatingHealth() > 0) {
					PlayerDefaultAttack(player, enemyindex);
				}
			}
			break;
		case 2:
			if (player.getEquippedSkill(0).getIsUnlocked() == true && player.getUpdatingMana() > player.getEquippedSkill(0).getManaCost() && player.getEquippedSkill(0).getName() != "none") {
				if (player.getUpdatingSpeed() >= battle.at(enemyindex).getSpeed()) {
					cout << "You Choose to use " << player.getEquippedSkill(0).getName() << endl;
					PlayerUseSkill(player, player.getEquippedSkill(0), enemyindex);
					EnemyTurn(player, enemyindex);
				}
				else {
					EnemyTurn(player, enemyindex);
					cout << "You Choose to use " << player.getEquippedSkill(0).getName() << endl;
					PlayerUseSkill(player, player.getEquippedSkill(0), enemyindex);
				}
			}
			else if (player.getEquippedSkill(0).getName() == "none") {
				cout << "You do not have an equipped skill in slot 1! " << endl;
			}
			else if (player.getUpdatingMana() < player.getEquippedSkill(0).getManaCost()) {
				cout << "You do not have enough mana to use this skill! " << endl;
			}
			else {
				cout << "Error, try again..." << endl;
			}
			break;
		case 3:
			if (player.getEquippedSkill(1).getIsUnlocked() == true && player.getUpdatingMana() > player.getEquippedSkill(1).getManaCost() && player.getEquippedSkill(0).getName() != "none") {
				if (player.getUpdatingSpeed() >= battle.at(enemyindex).getSpeed()) {
					cout << "You Choose to use " << player.getEquippedSkill(1).getName() << endl;
					PlayerUseSkill(player, player.getEquippedSkill(1), enemyindex);
					EnemyTurn(player, enemyindex);
				}
				else {
					EnemyTurn(player, enemyindex);
					cout << "You Choose to use " << player.getEquippedSkill(1).getName() << endl;
					PlayerUseSkill(player, player.getEquippedSkill(1), enemyindex);
				}
			}
			else if (player.getEquippedSkill(0).getName() == "none") {
				cout << "You do not have an equipped skill in slot 1! " << endl;
			}
			else if (player.getUpdatingMana() < player.getEquippedSkill(1).getManaCost()) {
				cout << "You do not have enough mana to use this skill! " << endl;
			}
			else {
				cout << "Error, try again..." << endl;
			}
			break;
		case 4:
			player.PrintInventory();
			cout << player.getInventorySize() << ". Exit Inventory" << endl;
			cin >> playernumberinput;
			itemselector = playernumberinput;
			if (playernumberinput > 0) {
				if (itemselector < player.getInventorySize()) {
					player.PrintItemDescription(itemselector);
					if (player.getItem(itemselector).getType() == "Consumable") {
						cout << "Would you like to use this item? (y/n)" << endl;
						cout << player.getItem(itemselector).getDescription();
						cin >> playerinput;
						if (playerinput == "y") {
							player.RemoveItemFromPlayerInventory(player, itemselector);
							player.setUpdatingHealth(player.getUpdatingHealth() + player.getItem(itemselector).getHealth());
							if (player.getUpdatingHealth() > player.getHealth()) {
								player.setUpdatingHealth(player.getHealth());
							}
							player.setUpdatingMana(player.getUpdatingMana() + player.getItem(itemselector).getMana());
							if (player.getUpdatingMana() > player.getMana()) {
								player.setUpdatingMana(player.getMana());
							}
							player.setUpdatingSpeed(player.getUpdatingSpeed() + player.getItem(itemselector).getSpeed());
							player.setUpdatingSpeed(player.getSpeed());
							player.setUpdatingStrength(player.getUpdatingStrength() + player.getItem(itemselector).getStrength());
							player.setUpdatingStrength(player.getStrength());
						}
					}
					else {
						cout << "Sorry, you can only use consumable items while in combat..." << endl;
					}
				}
				else {
					cout << "Error, please enter a number within range." << endl;
				}
			}
			else {
				cout << "Enter any letter to continue..." << endl;
				char input = _getch();
			}
			break;
		case 5:
			cout << "WARNING: If you choose to run away you will loose all your mana and " << hploss << " health. Do you still want to run away? (y/n)" << endl;
			cin >> playerinput;
			if (playerinput == "y") {
				hploss = player.getUpdatingHealth() / 2;
				cout << "You ran away..." << endl;
				inCombat = false;
				if (enemyindex > 0) {
					CalculateResults(player, enemyindex);
				}
				player.setUpdatingHealth(player.getHealth() - hploss);
				player.setUpdatingMana(0);
				battle.clear();
				player.setUpdatingSpeed(player.getSpeed());
				player.setUpdatingStrength(player.getStrength());
			}
			break;
		default:
			cout << "Error, please input a number between 1 - 4..." << endl;
			cin.clear();
			cin.ignore();
			break;
		}
		if (inCombat == true) {
			if (battle.at(enemyindex).getUpdatingHealth() <= 0) {
				if (enemyindex + 1 < battle.size()) {
					enemyindex++;
				}
				else {
					inCombat = false;
					if (enemyindex >= 0) {
						CalculateResults(player, enemyindex);
					}
					battle.clear();
					player.setUpdatingSpeed(player.getSpeed());
					player.setUpdatingStrength(player.getStrength());
				}
			}
			if (player.getUpdatingHealth() <= 0) {
				inCombat = false;
				cout << "You have run out of health! Use potions or go to a tavern and rest to restore your health. ( - " << player.getGold() / 10 << " gold )" << endl;
				if (enemyindex > 0) {
					CalculateResults(player, enemyindex);
				}
				battle.clear();
				player.setUpdatingHealth(0);
				int playergold = player.getGold() - (player.getGold() / 10);
				player.setGold(playergold);
				player.setUpdatingSpeed(player.getSpeed());
				player.setUpdatingStrength(player.getStrength());
			}
		}
	}
}
void InCombat(CombatSystem combat, Level& levelnumber, Player& player) { // Public version of InCombat function
	combat.InCombat(levelnumber, player);
}
void BossBattle(CombatSystem combat, Level& levelnumber, Player& player) { // Public version of BossBattle function
	combat.BossBattle(levelnumber, player);
}