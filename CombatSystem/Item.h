#pragma once
#include <iostream>
#include <string>

using namespace std;

class Item {
public:
	Item(string ItemName, string ItemType, string ItemDescription, int ItemValue, int ItemHealth, int ItemStrength, int ItemSpeed, int ItemMana);
	// Functions
	void addItem(int amount) {
		count = count + amount;
	}
	void removeItem(int amount) {
		count = count - amount;
	}
	void setEquipped(bool trueorfalse) {
		isequipped = trueorfalse;
	}
	bool operator==(const Item& other) const { // So that you can compare items because you get an error otherwise
		return name == other.name;
	}
	// Getters
	string getName() { return name; }
	string getType() { return type; }
	string getDescription() { return description; }
	bool getIsEquipped() { return isequipped; }
	int getValue() { return value; }
	int getCount() { return count; }
	int getHealth() { return health; }
	int getStrength() { return strength; }
	int getSpeed() { return speed; }
	int getMana() { return mana; }
private:
	string name;
	string type;
	string description;
	bool isequipped;
	int value;
	int count;
	int health;
	int strength;
	int speed;
	int defense;
	int mana;
};
// Constructor
Item::Item(string ItemName, string ItemType, string ItemDescription, int ItemValue, int ItemHealth, int ItemStrength, int ItemSpeed, int ItemMana) {
	name = ItemName;
	type = ItemType;
	description = ItemDescription;
	value = ItemValue;
	health = ItemHealth;
	strength = ItemStrength;
	speed = ItemSpeed;
	mana = ItemMana;
	count = 1;
	isequipped = false;
}