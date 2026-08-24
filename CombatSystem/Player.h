#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>

#include "Skill.h"
#include "Shops.h"

using namespace std;

class Player {
public:
	Player(string PlayerName, int PlayerLevel, int PlayerGold, int PlayerHealth, int PlayerStrength, int PlayerSpeed, int PlayerMana); // Constructor
	// Functions
	void EquipItem(int i);
	void EquipSkill(int i);
	void PrintStats();
	void PrintSkillPool();
	void PrintEquippedSkills();
	void UnequipSkill(int i);
	void UnlockSkill(int i);
	void UnequipItem(int i);
	void PrintEquippedItems();
	void PrintInventory();
	void PrintStatus();
	void PrintItemDescription(int i);
	void AddItemToPlayerInventory(Shop& shop, int i);
	void RemoveItemFromPlayerInventory(Player& player, int i);
	void AddGold(int number) { gold = gold + number; };
	void SubGold(int number) { gold = gold - number; };
	void SetExperiencePoints(int xp);
	void AddSkill(Skill skill);
	void InitializeSkills();
	void addHealthPoint(int i) { healthpoint = healthpoint + i; }
	void addManaPoint(int i) { manapoint = manapoint + i; }
	void addStrengthPoint(int i) { strengthpoint = strengthpoint + i; }
	void addSpeedPoint(int i) { speedpoint = speedpoint + i; }
	void subStatPoint(int i) { skillpoints = skillpoints - i; }
	void addStatPoint(int i) { skillpoints = skillpoints + i; }
	// Setters
	void setName(string PlayerName) { name = PlayerName; }
	void setGold(int PlayerGold) { gold = PlayerGold; }
	void setHealth(int PlayerHealth) { health = PlayerHealth; }
	void setUpdatingHealth(int PlayerUpdatingHealth) { updatinghealth = PlayerUpdatingHealth; }
	void setHealthPoint(int i) { healthpoint = i; }
	void setStrength(int PlayerStrength) { strength = PlayerStrength; }
	void setUpdatingStrength(int PlayerUpdatingStrength) { updatingstrength = PlayerUpdatingStrength; }
	void setStrengthPoint(int i) { strengthpoint = i; }
	void setSpeed(int PlayerSpeed) { speed = PlayerSpeed; }
	void setUpdatingSpeed(int PlayerUpdatingSpeed) { updatingspeed = PlayerUpdatingSpeed; }
	void setSpeedPoint(int i) { speedpoint = i; }
	void setMana(int PlayerDefense) { mana = PlayerDefense; }
	void setUpdatingMana(int PlayerUpdatingMana) { updatingmana = PlayerUpdatingMana; }
	void setManaPoint(int i) { manapoint = i; }
	void setPlayerLocation(int PlayerX, int PlayerY) {
		x = PlayerX;
		y = PlayerY;
	}
	// Getters
	string getName() { return name; }
	int getGold() { return gold; }
	int getLevel() { return level; }
	int getHealth() { return health; }
	int getUpdatingHealth() { return updatinghealth; }
	int getStrength() { return strength; }
	int getUpdatingStrength() { return updatingstrength; }
	int getSpeed() { return speed; }
	int getUpdatingSpeed() { return updatingspeed; }
	int getMana() { return mana; }
	int getUpdatingMana() { return updatingmana; }
	int getInventorySize() { return playerinventory.size(); }
	int getPlayerX() { return x; }
	int getPlayerY() { return y; }
	Item getItem(int i) { return playerinventory.at(i); }
	Item getEquipppedItem(int i) { return equippeditems[i]; }
	int getNumberOfSkills() { return skillpool.size(); }
	Skill getSkill(int i) { return skillpool.at(i); }
	Skill getEquippedSkill(int i) { return skills[i]; }
	int getExperiencePoints() { return experiencepoints; }
	int getHealthPoints() { return healthpoint; }
	int getManaPoints() { return manapoint; }
	int getSpeedPoints() { return speedpoint; }
	int getStrengthPoints() { return strengthpoint; }
	int getStatPoints() { return skillpoints; }
private:
	string name; // User Entered Name
	int level;
	int gold;
	int health; // Current Maximum Health
	int healthpoint;
	int updatinghealth; // Current Health
	int strength;
	int updatingstrength;
	int strengthpoint;
	int speed;
	int updatingspeed;
	int speedpoint;
	int mana; // Current Maximum Mana
	int manapoint;
	int updatingmana; // Current Mana
	int skillpoints;
	int experiencepoints;
	int xptolevel;
	int x;
	int y;
	vector<Item> equippeditems;
	vector<Item> playerinventory;
	vector<Skill> skills;
	vector<Skill> skillpool;
};
// Constructor
Player::Player(string PlayerName, int PlayerLevel, int PlayerGold, int PlayerHealth, int PlayerStrength, int PlayerSpeed, int PlayerMana) {
	Item DefaultItem("none", "none", "none", 0, 0, 0, 0, 0);
	Skill DefaultSkill("none", "none", 0, 0, 0, 0, 0);
	name = PlayerName;
	level = PlayerLevel;
	gold = PlayerGold;
	health = PlayerHealth;
	strength = PlayerStrength;
	speed = PlayerSpeed;
	mana = PlayerMana;
	updatingmana = mana;
	updatinghealth = health;
	updatingspeed = speed;
	updatingstrength = strength;
	healthpoint = 0;
	strengthpoint = 0;
	speedpoint = 0;
	manapoint = 0;
	experiencepoints = 0;
	xptolevel = 10;
	equippeditems = { DefaultItem, DefaultItem, DefaultItem, DefaultItem, DefaultItem };
	skills = { DefaultSkill, DefaultSkill };
	x = 5;
	y = 2;
}
// Prints Player Stats for the stat point senario
void Player::PrintStats() {
	cout << "========================================\nStats:\n========================================" << endl;
	cout << "Avaliable Stat Points: " << skillpoints << endl;
	cout << "LVL:\t" << level << "\nExperience Points: " << experiencepoints << " / " << xptolevel << endl;
	cout << "HP:\t" << updatinghealth << " / " << health << "(" << healthpoint << ")" << endl;
	cout << "MP:\t" << updatingmana << " / " << mana << "(" << manapoint << ")" << endl;
	cout << "STR:\t" << strength << "(" << strengthpoint << ")" << endl;
	cout << "SP:\t" << speed << "(" << speedpoint << ")" << endl;
	cout << "========================================" << endl;
}
// Adds skill to game, mainly for initializing the skills for the game
void Player::AddSkill(Skill skill) {
	skillpool.push_back(skill);
}
// Prints the skills that are currently equipped
void Player::PrintEquippedSkills() {
	cout << "====================\nEquipped Skills\n====================" << endl;
	cout << "Skill Slot 1: " << skills.at(0).getName() << endl;
	cout << "Skill Slot 2: " << skills.at(1).getName() << endl;
	cout << "====================" << endl;
}
// Prints all the skills in the game
void Player::PrintSkillPool() {
	cout << "====================\nSkills\n====================" << endl;
	for (int i = 0; i < skillpool.size(); i++) {
		cout << i << ". " << skillpool.at(i).getName();
		if (skillpool.at(i).getIsEquipped() == true) {
			cout << " * equipped *";
		}
		if (skillpool.at(i).getIsUnlocked() == false) {
			cout << " (LOCKED)";
		}
		cout << endl;
	}
}
// Handles equipping skill option and if equipping into a slot that already has a skill will unequip that skill first
void Player::EquipSkill(int i) {
	int PlayerNumberInput;
	if (skillpool.at(i).getIsUnlocked() == true) {
		cout << "Which slot would you like to change? (1 - 2)" << endl;
		PrintEquippedSkills();
		cin >> PlayerNumberInput;
		if (PlayerNumberInput == 1) {
			for (int iterator = 0; iterator < skillpool.size(); iterator++) {
				if (skillpool.at(iterator) == skills.at(0)) {
					skillpool.at(iterator).setIsEquipped(false);
				}
			}
			skills.at(0) = skillpool.at(i);
			skillpool.at(i).setIsEquipped(true);
		}
		else if (PlayerNumberInput == 2) {
			for (int iterator = 0; iterator < skillpool.size(); iterator++) {
				if (skillpool.at(iterator) == skills.at(1)) {
					skillpool.at(iterator).setIsEquipped(false);
				}
			}
			skillpool.at(i).setIsEquipped(false);
			skills.at(1) = skillpool.at(i);
			skillpool.at(i).setIsEquipped(true);
		}
	}
	else {
		cout << "You do not have that skill unlocked. " << endl;
	}
}
// Handles unequipping skill option when you initially select a skill that is already equipped
void Player::UnequipSkill(int i) {
	int PlayerNumberInput;
	Skill DefaultSkill("none", "none", 0, 0, 0, 0, 0);
	cout << "Which slot would you like to change? (1 - 2)" << endl;
	PrintEquippedSkills();
	cin >> PlayerNumberInput;
	if (PlayerNumberInput == 1) {
		skillpool.at(i).setIsEquipped(false);
		skills.at(0) = DefaultSkill;
	}
	else if (PlayerNumberInput == 2) {
		skillpool.at(i).setIsEquipped(false);
		skills.at(1) = DefaultSkill;
	}
}
// Unlock skill logic when you beat the boss the first time
void Player::UnlockSkill(int i) {
	if (skillpool.at(i).getIsUnlocked() == false) {
		skillpool.at(i).setIsUnlocked(true);
	}
}
// Handles equipping items and if equipping items into a slot that already has an item will unequip that item first
void Player::EquipItem(int i) {
	if (playerinventory.at(i).getType() == "Weapon") {
		for (int iterator = 0; iterator < getInventorySize(); iterator++) {
			if (playerinventory.at(iterator) == equippeditems.at(0)) {
				playerinventory.at(iterator).setEquipped(false);
			}
		}
		equippeditems.at(0) = playerinventory.at(i);
		playerinventory.at(i).setEquipped(true);
		setHealth(health + playerinventory.at(i).getHealth());
		setMana(mana + playerinventory.at(i).getMana());
		setSpeed(speed + playerinventory.at(i).getSpeed());
		setStrength(strength + playerinventory.at(i).getStrength());
	}
	else if (playerinventory.at(i).getType() == "Helmet") {
		for (int iterator = 0; iterator < getInventorySize(); iterator++) {
			if (playerinventory.at(iterator) == equippeditems.at(1)) {
				playerinventory.at(iterator).setEquipped(false);
			}
		}
		equippeditems.at(i).setEquipped(false);
		equippeditems.at(1) = playerinventory.at(i);
		playerinventory.at(i).setEquipped(true);
		setHealth(health + playerinventory.at(i).getHealth());
		setMana(mana + playerinventory.at(i).getMana());
		setSpeed(speed + playerinventory.at(i).getSpeed());
		setStrength(strength + playerinventory.at(i).getStrength());
	}
	else if (playerinventory.at(i).getType() == "Chestplate") {
		for (int iterator = 0; iterator < getInventorySize(); iterator++) {
			if (playerinventory.at(iterator) == equippeditems.at(2)) {
				playerinventory.at(iterator).setEquipped(false);
			}
		}
		equippeditems.at(i).setEquipped(false);
		equippeditems.at(2) = playerinventory.at(i);
		playerinventory.at(i).setEquipped(true);
		setHealth(health + playerinventory.at(i).getHealth());
		setMana(mana + playerinventory.at(i).getMana());
		setSpeed(speed + playerinventory.at(i).getSpeed());
		setStrength(strength + playerinventory.at(i).getStrength());
	}
	else if (playerinventory.at(i).getType() == "Leggings") {
		for (int iterator = 0; iterator < getInventorySize(); iterator++) {
			if (playerinventory.at(iterator) == equippeditems.at(3)) {
				playerinventory.at(iterator).setEquipped(false);
			}
		}
		equippeditems.at(i).setEquipped(false);
		equippeditems.at(3) = playerinventory.at(i);
		playerinventory.at(i).setEquipped(true);
		setHealth(health + playerinventory.at(i).getHealth());
		setMana(mana + playerinventory.at(i).getMana());
		setSpeed(speed + playerinventory.at(i).getSpeed());
		setStrength(strength + playerinventory.at(i).getStrength());
	}
	else if (playerinventory.at(i).getType() == "Boots") {
		for (int iterator = 0; iterator < getInventorySize(); iterator++) {
			if (playerinventory.at(iterator) == equippeditems.at(4)) {
				playerinventory.at(iterator).setEquipped(false);
			}
		}
		equippeditems.at(i).setEquipped(false);
		equippeditems.at(4) = playerinventory.at(i);
		playerinventory.at(i).setEquipped(true);
		setHealth(health + playerinventory.at(i).getHealth());
		setMana(mana + playerinventory.at(i).getMana());
		setSpeed(speed + playerinventory.at(i).getSpeed());
		setStrength(strength + playerinventory.at(i).getStrength());
	}
}
// Handles unequipping items when you initally select an item that is already equipped
void Player::UnequipItem(int i) {
	Item DefaultItem("none", "none", "none", 0, 0, 0, 0, 0);
	if (playerinventory.at(i).getType() == "Weapon") {
		playerinventory.at(i).setEquipped(false);
		equippeditems.at(0) = DefaultItem;
		setHealth(health - playerinventory.at(i).getHealth());
		setMana(mana - playerinventory.at(i).getMana());
		setSpeed(speed - playerinventory.at(i).getSpeed());
		setStrength(strength - playerinventory.at(i).getStrength());
	}
	else if (playerinventory.at(i).getType() == "Helmet") {
		playerinventory.at(i).setEquipped(false);
		equippeditems.at(1) = DefaultItem;
		setHealth(health - playerinventory.at(i).getHealth());
		setMana(mana - playerinventory.at(i).getMana());
		setSpeed(speed - playerinventory.at(i).getSpeed());
		setStrength(strength - playerinventory.at(i).getStrength());
	}
	else if (playerinventory.at(i).getType() == "Chestplate") {
		playerinventory.at(i).setEquipped(false);
		equippeditems.at(2) = DefaultItem;
		setHealth(health - playerinventory.at(i).getHealth());
		setMana(mana - playerinventory.at(i).getMana());
		setSpeed(speed - playerinventory.at(i).getSpeed());
		setStrength(strength - playerinventory.at(i).getStrength());
	}
	else if (playerinventory.at(i).getType() == "Leggings") {
		playerinventory.at(i).setEquipped(false);
		equippeditems.at(3) = DefaultItem;
		setHealth(health - playerinventory.at(i).getHealth());
		setMana(mana - playerinventory.at(i).getMana());
		setSpeed(speed - playerinventory.at(i).getSpeed());
		setStrength(strength - playerinventory.at(i).getStrength());
	}
	else if (playerinventory.at(i).getType() == "Boots") {
		playerinventory.at(i).setEquipped(false);
		equippeditems.at(4) = DefaultItem;
		setHealth(health - playerinventory.at(i).getHealth());
		setMana(mana - playerinventory.at(i).getMana());
		setSpeed(speed - playerinventory.at(i).getSpeed());
		setStrength(strength - playerinventory.at(i).getStrength());
	}
}
// Prints equipped items slots
void Player::PrintEquippedItems() {
	cout << "====================\nEquipped Items\n====================" << endl;
	cout << "Weapon: " << equippeditems.at(0).getName() << endl;
	cout << "Helmet: " << equippeditems.at(1).getName() << endl;
	cout << "Chestplate: " << equippeditems.at(2).getName() << endl;
	cout << "Leggings: " << equippeditems.at(3).getName() << endl;
	cout << "Boots: " << equippeditems.at(4).getName() << endl;
	cout << "====================" << endl;
}
// Prints all the items in the inventory
void Player::PrintInventory() { // Checks if inventory is empty then prints inventory
	if (playerinventory.size() == 0) {
		cout << "You have nothing in your inventory... " << endl;
		return;
	}
	cout << "====================\nInventory\n====================" << endl;
	for (int i = 0; i < playerinventory.size(); i++) {
		cout << i << ". " << playerinventory.at(i).getName() << " x " << playerinventory.at(i).getCount();
		if (playerinventory.at(i).getIsEquipped() == true) {
			cout << " * equipped *";
		}
		cout << endl;
	}
}
// Prints status mainly for movement senario
void Player::PrintStatus() {
	cout << "========================================\nStatus:\n========================================" << endl;
	cout << "Name: " << name << "\tLevel: " << level << "\tGold: " << gold << endl;
	cout << "Health: " << updatinghealth << " / " << health << "\tMana: " << updatingmana << " / " << mana << endl;
	cout << "========================================" << endl;
}
// Prints a discription of the item given it's index in player inventory
void Player::PrintItemDescription(int i) {
	cout << "====================\nItem Description\n====================" << endl;
	cout << "Name: " << playerinventory.at(i).getName() << endl;
	cout << "Gold: " << playerinventory.at(i).getValue() << endl;
	cout << "Amount In Inventory: " << playerinventory.at(i).getCount() << endl;
	cout << "Description: " << playerinventory.at(i).getDescription() << endl;
	cout << "====================" << endl;
}
// Logic for adding item to a player inventory, checking for if it is in the inventory, etc.
void Player::AddItemToPlayerInventory(Shop& shop, int i) { // Checks if player has item in inventory and adds it to inventory
	Item item = shop.getItem(shop, i);
	bool found = false;
	for (int x = 0; x < playerinventory.size(); x++) {
		if (playerinventory.at(x) == item) {
			cout << "Item found in inventory " << endl;
			playerinventory.at(x).addItem(1);
			found = true;
			break;
		}
	}
	if (found == false) {
		cout << "Item not found in inventory " << endl;
		playerinventory.push_back(item);
	}
}
// Logic for removing an item from the player inventory
void Player::RemoveItemFromPlayerInventory(Player& player, int i) { // Checks if player has item in inventory and removes it from inventory
	Item item = player.getItem(i);
	bool found = false;
	for (int x = 0; x < playerinventory.size(); x++) {
		if (playerinventory.at(x) == item) {
			cout << "Item found in inventory " << endl;
			playerinventory.at(x).removeItem(1);
			found = true;
			if (playerinventory.at(x).getCount() == 0) {
				playerinventory.erase(playerinventory.begin() + x);
				x--;
			}
			break;
		}
	}
	if (found == false) {
		cout << "Item not found in inventory " << endl;
	}
}
// Logic whenever the player earns experience points, updates everything for the leveling system
void Player::SetExperiencePoints(int xp) {
	experiencepoints = experiencepoints + xp;
	int xlevel = level;
	int xhealth = health;
	int xmana = mana;
	int xexperiencepoints = experiencepoints;
	while (experiencepoints >= xptolevel) {
		level++;
		skillpoints = skillpoints + 2;
		health = health + 25;
		mana = mana + 15;
		experiencepoints = experiencepoints - xptolevel;
		xptolevel = xptolevel * 1.5;
	}
	if (xexperiencepoints >= xptolevel) {
		cout << "Level Up! " << xlevel << " -> " << level << endl;
		cout << "Avaliable Stat Points: " << skillpoints << endl;
		cout << "Experience Points: " << experiencepoints << " / " << xptolevel << endl;
		cout << "HP:\t" << xhealth << " -> " << health << endl;
		cout << "MP:\t" << xmana << " -> " << mana << endl;
	}
}
// string SkillName, string SkillDiscription, int Level, int SkillManaCost, int SkillHealth, int SkillDamage, int SkillTurns
void Player::InitializeSkills() {
	AddSkill(Skill("Basic Heal", "Heals the user for 10 health points.", 0, 10, 10, 0, 0));
	AddSkill(Skill("Ensnare", "Traps the target in webs and reduces their speed to 0 for the rest of the battle.", 1, 20, 0, 0, 0));
	AddSkill(Skill("Advanced Heal", "Heals the user for 10% of their maximum health.", 2, 25, 10, 0, 0));
	AddSkill(Skill("Fireball", "Fires a fire ball at the target dealing 2 times the user's strength.", 3, 50, 0, 2, 0));
	AddSkill(Skill("Shadow Slash", "Using the shadows, slashes the opponet dealing 5 times the user's strength.", 4, 100, 0, 5, 0));
	AddSkill(Skill("Destruction", "Destroying everything in its path dealing 10 times the user's strength.", 5, 500, 0, 10, 0));
}