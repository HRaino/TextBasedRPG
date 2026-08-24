#pragma once
#include <iostream>
#include <string>

using namespace std;

class Skill {
public:
	// Constructor
	Skill(string SkillName, string SkillDiscription, int Level, int SkillManaCost, int SkillHealth, int SkillDamage, int SkillTurns);
	// Getters
	string getName() { return name; }
	string getDiscription() { return discription; }
	int getManaCost() { return manacost; }
	int getHealth() { return health; }
	int getDamage() { return damage; }
	int getTurns() { return turns; }
	bool getIsEquipped() { return isequipped; }
	bool getIsUnlocked() { return isunlocked; }
	// Setters
	void setIsEquipped(bool trueorfalse) { isequipped = trueorfalse; }
	void setIsUnlocked(bool trueorfalse) { isunlocked = trueorfalse; }
	bool operator==(const Skill& other) const { // So that you can compare items because you get an error otherwise
		return name == other.name;
	}
private:
	// Skills Unique Variables
	string name;
	string discription;
	bool isunlocked;
	bool isequipped;
	int level;
	int manacost;
	// Stats Associated with Skills
	int health;
	int damage;
	int turns;
};
// Constructor
Skill::Skill(string SkillName, string SkillDiscription, int Level, int SkillManaCost, int SkillHealth, int SkillDamage, int SkillTurns) {
	name = SkillName;
	discription = SkillDiscription;
	level = Level;
	manacost = SkillManaCost;
	health = SkillHealth;
	damage = SkillDamage;
	turns = SkillTurns;
	isequipped = false;
	isunlocked = false;
}