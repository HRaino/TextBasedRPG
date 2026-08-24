#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Skill.h"
#include "Item.h"

using namespace std;

class Enemy {
public:
	Enemy(string EnemyName, string Adjective, string EnemyType, int EnemyLevel, int EnemyStage, int EnemyMinimumDamage, int EnemyMaximumDamage, int EnemyHealth, int EnemySpeed, int EnemyMana); // Constructor
	// Setters
	void setHealth(int EnemyHealth) { health = EnemyHealth; }
	void setUpdatingHealth(int PlayerUpdatingHealth) { updatinghealth = PlayerUpdatingHealth; }
	void setMinDmg(int EnemyMinDmg) { mindmg = EnemyMinDmg; }
	void setMaxDmg(int EnemyMaxDmg) { maxdmg = EnemyMaxDmg; }
	void setSpeed(int EnemySpeed) { speed = EnemySpeed; }
	void setMana(int EnemyMana) { mana = EnemyMana; }
	void setUpdatingMana(int EnemyUpdatingMana) { updatingmana = EnemyUpdatingMana; }
	// Getters
	string getName() { return name; }
	string getAdjective() { return adjective; }
	string getType() { return type; }
	int getLevel() { return level; }
	int getStage() { return stage; }
	int getMinDmg() { return mindmg; }
	int getMaxDmg() { return maxdmg; }
	int getHealth() { return health; }
	int getUpdatingHealth() { return updatinghealth; }
	int getSpeed() { return speed; }
	int getMana() { return mana; }
	int getUpdatingMana() { return updatingmana; }
private:
	string name;
	string adjective;
	string type;
	int level;
	int stage;
	int mindmg;
	int maxdmg;
	int health;
	int updatinghealth;
	int speed;
	int mana;
	int updatingmana;
	vector<Item> loottable;
};
// Constructor
Enemy::Enemy(string EnemyName, string Adjective, string EnemyType, int EnemyLevel, int EnemyStage, int EnemyMinimumDamage, int EnemyMaximumDamage, int EnemyHealth, int EnemySpeed, int EnemyMana) {
	name = EnemyName;
	adjective = Adjective;
	type = EnemyType;
	level = EnemyLevel;
	mindmg = EnemyMinimumDamage;
	maxdmg = EnemyMaximumDamage;
	health = EnemyHealth;
	speed = EnemySpeed;
	mana = EnemyMana;
	stage = EnemyStage;
	updatingmana = mana;
	updatinghealth = health;
}