#pragma once
#include "Shops.h"


using namespace std;

class Level {
public:
	// Constructor
	Level(int LevelNumber, string LevelName, string TownName);
	// Functions
	void AddEnemy(Enemy enemy);
	void InitializeLevel0Enemies(Level& levelnumber);
	void InitializeLevel1Enemies(Level& levelnumber);
	void InitializeLevel2Enemies(Level& levelnumber);
	void InitializeLevel3Enemies(Level& levelnumber);
	void InitializeLevel4Enemies(Level& levelnumber);
	void InitializeLevel5Enemies(Level& levelnumber);
	void InitializeShopsForLevel0(Level& levelnumber);
	void InitializeShopsForLevel1(Level& levelnumber);
	void InitializeShopsForLevel2(Level& levelnumber);
	void InitializeShopsForLevel3(Level& levelnumber);
	void InitializeShopsForLevel4(Level& levelnumber);
	void InitializeShopsForLevel5(Level& levelnumber);
	// Setters
	void setLevelNumber(int LevelNumber) { levelnumber = LevelNumber; }
	void setLevelName(string LevelName) { levelname = LevelName; }
	void setTownName(string TownName) { townname = TownName; }
	void setIsBossDefeated(bool trueorfalse) { isBossDefeated = trueorfalse; }
	// Getters
	int getLevelNumber() { return levelnumber; }
	string getLevelName() { return levelname; }
	string getTownName() { return townname; }
	auto getEnemy(Level& levelnumber, int i) { return levelnumber.enemies.at(i); } // Returns a vector to move data from this class's vector to another class's vector
	int getNumberOfEnemies(Level& levelnumber) { return levelnumber.enemies.size(); } // Returns the number of enemies in that level
	auto getShop(Level& levelnumber, int i) { return levelnumber.shops[i]; }
	bool getIsBossDefeated() { return isBossDefeated; }
private:
	string levelname;
	string townname;
	int levelnumber;
	bool isBossDefeated;
	vector<Enemy> enemies;
	vector<Shop> shops;
};
// Constructor
Level::Level(int LevelNumber, string LevelName, string TownName) {
	levelnumber = LevelNumber;
	levelname = LevelName;
	townname = TownName;
	isBossDefeated = false;
}
// Adds Enemies to the level, used to initialize levels
void Level::AddEnemy(Enemy enemy) {
	enemies.push_back(enemy);
}
// Note: (name, adj, type, level, stage, mindmg, maxdmg, health, speed, mana)
void Level::InitializeLevel0Enemies(Level& levelnumber) {
	levelnumber.AddEnemy(Enemy("Slime", " attacks", "normal", 5, 0, 2, 5, 20, 20, 20));
	levelnumber.AddEnemy(Enemy("Goblin", " swings its dagger and cuts", "normal", 1, 0, 1, 3, 10, 40, 30));
	levelnumber.AddEnemy(Enemy("Troll", " slams", "normal", 8, 0, 5, 8, 30, 50, 25));
	levelnumber.AddEnemy(Enemy("Giant Slime", " attacks", "boss", 10, 0, 10, 20, 100, 20, 50));
}
void Level::InitializeLevel1Enemies(Level& levelnumber) {
	levelnumber.AddEnemy(Enemy("Spider", " bites", "normal", 15, 1, 9, 12, 75, 20, 50));
	levelnumber.AddEnemy(Enemy("Bat", " cuts", "normal", 10, 1, 10, 15, 25, 40, 30));
	levelnumber.AddEnemy(Enemy("Ghost", " haunts", "normal", 18, 1, 10, 15, 30, 50, 25));
	levelnumber.AddEnemy(Enemy("Giant Spider", " uses its sharp fangs and bites", "boss", 20, 1, 20, 30, 200, 20, 100));
}
void Level::InitializeLevel2Enemies(Level& levelnumber) {
	levelnumber.AddEnemy(Enemy("Wisp", " quickly cuts", "normal", 22, 2, 20, 22, 80, 50, 50));
	levelnumber.AddEnemy(Enemy("Cursed Spirit", " violently slashes", "normal", 25, 2, 20, 25, 100, 80, 50));
	levelnumber.AddEnemy(Enemy("Enchanted Tree", " grabs and slams", "normal", 28, 2, 25, 28, 150, 30, 50));
	levelnumber.AddEnemy(Enemy("Ancient Guardian of the Forest", " uses its branches and slashes", "boss", 30, 2, 30, 40, 300, 30, 200));
}
void Level::InitializeLevel3Enemies(Level& levelnumber) {
	levelnumber.AddEnemy(Enemy("Living Flame", " burns", "normal", 32, 2, 30, 32, 180, 100, 50));
	levelnumber.AddEnemy(Enemy("Frost Spirit", " freezes", "normal", 35, 2, 30, 35, 180, 80, 50));
	levelnumber.AddEnemy(Enemy("Crystal Golem", " stabs", "normal", 38, 2, 35, 38, 200, 50, 50));
	levelnumber.AddEnemy(Enemy("Elemental Being", " attacks", "boss", 40, 3, 40, 50, 500, 80, 350));
}
void Level::InitializeLevel4Enemies(Level& levelnumber) {
	levelnumber.AddEnemy(Enemy("Dire Wolf", " lunges and bites", "normal", 42, 3, 45, 42, 200, 150, 50));
	levelnumber.AddEnemy(Enemy("Twisted Elemental", " grabs and slams", "normal", 45, 3, 42, 45, 250, 100, 50));
	levelnumber.AddEnemy(Enemy("Poisonous Spider", " uses its poisonous fangs and bites", "normal", 48, 3, 45, 48, 300, 200, 50));
	levelnumber.AddEnemy(Enemy("Shade of Dusk", " comes out from the shadows and slashes", "boss", 50, 4, 50, 60, 800, 400, 500));
}
void Level::InitializeLevel5Enemies(Level& levelnumber) {
	levelnumber.AddEnemy(Enemy("Hell Hound", " lunges and bites", "normal", 52, 2, 50, 52, 350, 400, 50));
	levelnumber.AddEnemy(Enemy("Tormented Spirit", " violently slashes", "normal", 55, 2, 50, 55, 400, 450, 50));
	levelnumber.AddEnemy(Enemy("Overseer", " mysteriously attacks", "normal", 58, 2, 55, 58, 450, 300, 50));
	levelnumber.AddEnemy(Enemy("Demon of Eternal Hell", " attacks", "boss", 60, 5, 50, 50, 1000, 500, 600));
}
void Level::InitializeShopsForLevel0(Level& levelnumber) {
	Shop Shop1("Dawnlight Weaponary", "Weapon");
	Shop Shop2("Dawnlight Armory", "Armor");
	Shop Tavern1("Dawnlight Brewery", "Consumables");
	InitializeShop1(Shop1);
	InitializeShop2(Shop2);
	InitializeTavern1(Tavern1);
	levelnumber.shops.push_back(Shop1);
	levelnumber.shops.push_back(Shop2);
	levelnumber.shops.push_back(Tavern1);
}
void Level::InitializeShopsForLevel1(Level& levelnumber) {
	Shop Shop3("Dwarven Wares", "Weapon");
	Shop Shop4("Dwarven Armory", "Armor");
	Shop Tavern2("Miner's Haven", "Consumables");
	InitializeShop3(Shop3);
	InitializeShop4(Shop4);
	InitializeTavern2(Tavern2);
	levelnumber.shops.push_back(Shop3);
	levelnumber.shops.push_back(Shop4);
	levelnumber.shops.push_back(Tavern2);
}
void Level::InitializeShopsForLevel2(Level& levelnumber) {
	Shop Shop5("Flying Swords Weaponary", "Weapon");
	Shop Shop6("Livingstone Armory", "Armor");
	Shop Tavern3("Fairy's Touch Tavern", "Consumables");
	InitializeShop5(Shop5);
	InitializeShop6(Shop6);
	InitializeTavern3(Tavern3);
	levelnumber.shops.push_back(Shop5);
	levelnumber.shops.push_back(Shop6);
	levelnumber.shops.push_back(Tavern3);
}
void Level::InitializeShopsForLevel3(Level& levelnumber) {
	Shop Shop7("Living Flame Weaponary", "Weapon");
	Shop Shop8("Hearth Armory", "Armor");
	Shop Tavern4("Elemental's Touch", "Consumables");
	InitializeShop7(Shop7);
	InitializeShop8(Shop8);
	InitializeTavern4(Tavern4);
	levelnumber.shops.push_back(Shop7);
	levelnumber.shops.push_back(Shop8);
	levelnumber.shops.push_back(Tavern4);
}
void Level::InitializeShopsForLevel4(Level& levelnumber) {
	Shop Shop9("Shady Smithery", "Weapon");
	Shop Shop10("Dark Armory", "Armor");
	Shop Tavern5("Dusk's Shadow", "Consumables");
	InitializeShop9(Shop9);
	InitializeShop10(Shop10);
	InitializeTavern5(Tavern5);
	levelnumber.shops.push_back(Shop9);
	levelnumber.shops.push_back(Shop10);
	levelnumber.shops.push_back(Tavern5);
}
void Level::InitializeShopsForLevel5(Level& levelnumber) {
	Shop Shop11("Burning Flames", "Weapon");
	Shop Shop12("Inferno's Fiery", "Armor");
	Shop Tavern6("Eternal Slumber", "Consumables");
	InitializeShop11(Shop11);
	InitializeShop12(Shop12);
	InitializeTavern6(Tavern6);
	levelnumber.shops.push_back(Shop11);
	levelnumber.shops.push_back(Shop12);
	levelnumber.shops.push_back(Tavern6);
}