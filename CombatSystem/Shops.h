#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Item.h"

using namespace std;

class Shop {
public:
	// Constructor
	Shop(string ShopName, string ShopType) {
		name = ShopName;
		type = ShopType;
	}
	// Functions
	void AddItem(Item item);
	void PrintShop(Shop& shop);
	void BuyItem(int i, int NumberOfItems);
	void PrintItemDescription(Shop& shop, int i);
	// Getters
	string getName() { return name; }
	string getType() { return type; }
	int getNumberOfItems(Shop shop) { return shop.shopinventory.size(); }
	int getItemValue(Shop shop, int i) { return shop.shopinventory[i].getValue(); }
	auto getItem(Shop shop, int i) { return shop.shopinventory.at(i); }
private:
	string name;
	string type;
	vector<Item> shopinventory;
};
// Add item to shop, used for initialization of the different shops
void Shop::AddItem(Item item) {
	shopinventory.push_back(item);
}
// Prints all the items in the shop with their indexes given the specific shop
void Shop::PrintShop(Shop& shop) {
	cout << "====================\n" << name << "\n====================\nAvaliable Items:\n" << endl;
	for (int i = 0; i < shop.shopinventory.size(); i++) {
		cout << i << ". " << shop.shopinventory.at(i).getName() << " - " << shop.shopinventory.at(i).getValue() << " gold." << endl;
	}
}
// Logic for buying items
void Shop::BuyItem(int i, int NumberOfItems) {
	int TotalCost = (shopinventory.at(i).getValue()) * NumberOfItems;
	cout << "You have purchased " << NumberOfItems << " x " << shopinventory.at(i).getName() << " for " << TotalCost << " gold." << endl;
}
// Prints Item Description given the item index for that specific shop
void Shop::PrintItemDescription(Shop& shop, int i) {
	cout << "====================\nItem Description\n====================\nAvaliable Items:\n" << endl;
	cout << "Name: " << shop.shopinventory.at(i).getName() << endl;
	cout << "Gold: " << shop.shopinventory.at(i).getValue() << endl;
	cout << "Description: " << shop.shopinventory.at(i).getDescription() << endl;
	if (getItem(shop, i).getType() != "Consumable") {
		cout << "Stats:\n" << "+" << getItem(shop, i).getHealth() << " health, +" << getItem(shop, i).getStrength() << " strength, +" << getItem(shop, i).getSpeed() << " speed." << endl;
	}
}
// string ItemName, string ItemType, string ItemDescription, int ItemValue, int ItemHealth, int ItemStrength, int ItemSpeed, int ItemMana
// Level 0
void InitializeTavern1(Shop& shop) {
	shop.AddItem(Item("Mysterious Yellow Drink", "Consumable", "Perfectly Acidic and Tangy. Increases speed by +5 for the next battle.", 1, 0, 0, 5, 0));
	shop.AddItem(Item("Mysterious Red Drink", "Consumable", "A sweet drink, almost too sweet. Increases speed by +10 for the next battle.", 5, 0, 0, 10, 0));
	shop.AddItem(Item("Crispy Apple", "Consumable", "An apple a day keeps the doctor away. Recovers 10 health points.", 10, 10, 0, 0, 0));
	shop.AddItem(Item("Blue Bannana", "Consumable", "Why is it blue?. Increases speed stat by +20 for the next battle.", 10, 0, 0, 20, 0));
}
void InitializeShop1(Shop& shop) {
	shop.AddItem(Item("Rock", "Weapon", "Rock.", 5, 0, 5, 0, 0));
	shop.AddItem(Item("Old Pickaxe", "Weapon", "An old pickaxe left by a dishearted miner.", 15, 0, 10, 0, 0));
	shop.AddItem(Item("Old Stone Sword", "Weapon", "A stone sword with visible chips, but it is still usable.", 25, 0, 15, 0, 0));
}
void InitializeShop2(Shop& shop) {
	shop.AddItem(Item("Worn Hood", "Helmet", "An old hood made of thin cloth that barely provides warmth.", 5, 10, 0, 0, 0));
	shop.AddItem(Item("Worn Cloak", "Chestplate", "An old cloak made of thin cloth that barely provides warmth.", 15, 20, 0, 0, 0));
	shop.AddItem(Item("Worn Pants", "Leggings", "Old pants made of thin cloth that barely provides warmth.", 10, 15, 0, 0, 0));
	shop.AddItem(Item("Worn Shoes", "Boots", "Old boots made of thin cloth that barely provides warmth.", 2, 5, 0, 0, 0));
	shop.AddItem(Item("Leather Hat", "Helmet", "Stylish and warm.", 20, 15, 0, 0, 0));
	shop.AddItem(Item("Leather Coat", "Chestplate", "Good to keep warm on a cold day.", 35, 25, 0, 0, 0));
	shop.AddItem(Item("Leather Pants", "Leggings", "Good to keep warm on a cold day.", 30, 20, 0, 0, 0));
	shop.AddItem(Item("Leather Boots", "Boots", "Sturdy and warm.", 15, 10, 0, 0, 0));
}
// Level 1
void InitializeTavern2(Shop& shop) {
	shop.AddItem(Item("Luminescent Fungus Potion", "Consumable", "A flask containing a flowing liquid extracted from glowing fungi found deep within the caves. Increases strength by +10 for the next battle.", 20, 0, 10, 0, 0));
	shop.AddItem(Item("Moss Bandage", "Consumable", "A bandage infused with healing properties extracted from cave moss that grows in the damp corners of the caverns. Recovers 50 health points", 50, 50, 0, 0, 0));
	shop.AddItem(Item("Batwing Brew", "Consumable", "A dark potion brewed from bat wings and various other ingredients. Recovers 30 mana points.", 15, 0, 0, 0, 30));
	shop.AddItem(Item("Echochamber Elixier", "Consumable", "A bubbling potion brewed from rare cave minerals, recovers 50 mana points.", 25, 0, 0, 0, 50));
}
void InitializeShop3(Shop& shop) {
	shop.AddItem(Item("Old Sword", "Weapon", "With visible chips on its edges, but is still usable.", 10, 0, 10, 0, 0));
	shop.AddItem(Item("Wooden Sword", "Weapon", "Crafted from the wood of the finest trees in Dawnlight.", 15, 0, 10, 5, 0));
	shop.AddItem(Item("Training Sword", "Weapon", "The standard training sword all knights in Dawnlight use.", 25, 0, 20, 0, 0));
}
void InitializeShop4(Shop& shop) {
	shop.AddItem(Item("Chain Helmet", "Helmet", "Made of chains, it is enough to protect against sharp objects.", 15, 25, 0, 0, 0));
	shop.AddItem(Item("Chain Chestplate", "Chestplate", "Made of chains, it is enough to protect against sharp objects.", 25, 35, 0, 0, 0));
	shop.AddItem(Item("Chain Leggings", "Leggings", "Made of chains, it is enough to protect against sharp objects.", 20, 30, 0, 0, 0));
	shop.AddItem(Item("Chain Boots", "Boots", "Made of chains, it is enough to protect against sharp objects.", 10, 20, 0, 0, 0));
	shop.AddItem(Item("Iron Helmet", "Helmet", "Very sturdy and reliable.", 40, 35, 0, 0, 0));
	shop.AddItem(Item("Iron Chestplate", "Chestplate", "Very sturdy and reliable.", 55, 45, 0, 0, 0));
	shop.AddItem(Item("Iron Leggings", "Leggings", "Very sturdy and reliable.", 50, 40, 0, 0, 0));
	shop.AddItem(Item("Iron Boots", "Boots", "Very sturdy and reliable.", 35, 30, 0, 0, 0));
}
// Level 2
void InitializeTavern3(Shop& shop) {
	shop.AddItem(Item("Fairy Dust", "Consumable", "Zoom. Increases speed by +30 for next battle.", 15, 0, 0, 30, 0));
	shop.AddItem(Item("Mysterious Purple Drink", "Consumable", "Doesn't taste great... Recovers 25 mana points.", 15, 0, 0, 0, 25));
	shop.AddItem(Item("Health Potion", "Consumable", "A normal potion, or is it? Recovers 50 health points.", 25, 50, 0, 0, 0));
	shop.AddItem(Item("Sparkley Golden Potion", "Consumable", "Looks expensive. Recovers all health and mana points.", 1000, 5000, 0, 0, 5000));
}
void InitializeShop5(Shop& shop) {
	shop.AddItem(Item("Sylvien Dagger", "Weapon", "A lightweight dagger crafted from rare metals found in the deepest parts of the forest, allowing for swift and agile attacks.", 30, 0, 20, 20, 0));
	shop.AddItem(Item("Fay Blade", "Weapon", "A shimmering blade blessed by the fairies of the forest.", 50, 0, 25, 0, 0));
	shop.AddItem(Item("Moonlit Shine", "Weapon", "A blade forged under the night of a full moon, glowing softly in the dark night, showing the path of righteousness", 80, 0, 30, 20, 0));
}
void InitializeShop6(Shop& shop) {
	shop.AddItem(Item("Drudic Cap", "Helmet", "Inscribed into the fabric are mysterious symbols protecting the user from harm.", 100, 60, 0, 0, 0));
	shop.AddItem(Item("Drudic Robes", "Chestplate", "Inscribed into the fabric are mysterious symbols protecting the user from harm.", 150, 80, 0, 0, 0));
	shop.AddItem(Item("Drudic Pants", "Leggings", "Inscribed into the fabric are mysterious symbols protecting the user from harm.", 135, 75, 0, 0, 0));
	shop.AddItem(Item("Drudic Boots", "Boots", "Inscribed into the fabric are mysterious symbols protecting the user from harm.", 90, 50, 0, 0, 0));
	shop.AddItem(Item("Elven Cap", "Helmet", "Crafted with care from the greatest elven blacksmiths.", 180, 65, 0, 0, 0));
	shop.AddItem(Item("Elven Cloak", "Chestplate", "Crafted with care from the greatest elven blacksmiths.", 200, 85, 0, 0, 0));
	shop.AddItem(Item("Elven Pants", "Leggings", "Crafted with care from the greatest elven blacksmiths.", 280, 80, 0, 0, 0));
	shop.AddItem(Item("Elven Boots", "Boots", "Crafted with care from the greatest elven blacksmiths.", 160, 55, 0, 0, 0));
}
// Level 3
void InitializeTavern4(Shop& shop) {
	shop.AddItem(Item("Wind Scroll", "Consumable", "Calls on the wind and increases speed by +50 for the next battle.", 15, 0, 0, 50, 0));
	shop.AddItem(Item("Aqua Potion", "Consumable", "A shimmering blue liquid contained in a small vial, with small bubbles dancing on its surface. Recovers 50 mana points.", 25, 0, 0, 0, 50));
	shop.AddItem(Item("Earthbound Elixir", "Consumable", "A thick, earthy potion brewed from rare herbs and minerals found deep within the Enchanted Forest. Recovers 100 health points.", 50, 100, 0, 0, 0));
	shop.AddItem(Item("Crystal Prism Shard", "Consumable", "A shard of enchanted crystal, reflecting and refracting light in dazzling patterns. Recovers all health and mana points.", 1000, 5000, 0, 0, 5000));
}
void InitializeShop7(Shop& shop) {
	shop.AddItem(Item("Quicksilver Dagger", "Weapon", "A dagger crafted with silver, its edge gleaming with a silvery sheen.", 150, 0, 50, 50, 0));
	shop.AddItem(Item("Earthen Hammer of the Titans", "Weapon", "A massive warhammer forged from enchanted stone,w ith runes carved into its surface pulsating with earthen energy.", 200, 0, 55, 0, 0));
	shop.AddItem(Item("Infernal Blade of Chaos", "Weapon", "A blade forged under the night of a full moon, glowing softly in the dark night, showing the path of righteousness", 300, 0, 60, 20, 0));
}
void InitializeShop8(Shop& shop) {
	shop.AddItem(Item("Elemental Cap", "Helmet", "Good at reflecting elemental attacks.", 200, 70, 0, 0, 0));
	shop.AddItem(Item("Elemental Robes", "Chestplate", "Good at reflecting elemental attacks.", 300, 100, 0, 0, 0));
	shop.AddItem(Item("Elemental Pants", "Leggings", "Good at reflecting elemental attacks.", 280, 90, 0, 0, 0));
	shop.AddItem(Item("Elemental Boots", "Boots", "Good at reflecting elemental attacks.", 180, 60, 0, 0, 0));
	shop.AddItem(Item("Fire Cap", "Helmet", "Burns those that meets its eye.", 300, 80, 0, 0, 0));
	shop.AddItem(Item("Earth Cloak", "Chestplate", "Protects the heart.", 400, 120, 0, 0, 0));
	shop.AddItem(Item("Water Pants", "Leggings", "Great when swimming.", 450, 100, 0, 0, 0));
	shop.AddItem(Item("Wind Boots", "Boots", "Swiftly glide across the ground.", 280, 70, 0, 100, 0));
}
// Level 4
void InitializeTavern5(Shop& shop) {
	shop.AddItem(Item("Shadow Essence Flask", "Consumable", "A small vial containing concentrated shadow essence. Increases speed by +100 for the next battle", 25, 0, 0, 100, 0));
	shop.AddItem(Item("Moonlit Elixir", "Consumable", "An elixir distilled from moonlit mushrooms found only in the darkest corners of the dark forest. Increases speed by +150 for the next battle", 40, 0, 0, 150, 0));
	shop.AddItem(Item("Twilight Brew", "Consumable", "A mysterious potion made from rare herbs and flowers that bloom only under the light of a full moon. Recovers 150 health points.", 80, 150, 0, 0, 0));
	shop.AddItem(Item("Shade Shroud Scroll", "Consumable", "A scroll inscribed with ancient runes that weave around the user recovering 80 mana points.", 20, 0, 0, 0, 80));
}
void InitializeShop9(Shop& shop) {
	shop.AddItem(Item("Shadow Dagger", "Weapon", "A dark dagger that can even slash through shadows.", 250, 0, 60, 60, 0));
	shop.AddItem(Item("Dark Fang", "Weapon", "Crafted from the fangs of dire wolves found in the dark forest.", 300, 0, 70, 0, 0));
	shop.AddItem(Item("Blade of the Night", "Weapon", "A blade of the purest darkness taking on the burdens of the fallen.", 400, 0, 80, 20, 0));
}
void InitializeShop10(Shop& shop) {
	shop.AddItem(Item("Dark Mage's Cap", "Helmet", "The dark mages of the forest's standard robes.", 350, 90, 0, 5, 0));
	shop.AddItem(Item("Dark Mage's Robes", "Chestplate", "The dark mages of the forest's standard robes.", 450, 150, 0, 20, 0));
	shop.AddItem(Item("Dark Mage's Pants", "Leggings", "The dark mages of the forest's standard robes.", 400, 130, 0, 12, 0));
	shop.AddItem(Item("Dark Mage's Boots", "Boots", "The dark mages of the forest's standard robes.", 300, 80, 0, 3, 0));
	shop.AddItem(Item("Shadow Helmet", "Helmet", "Blend in and move within the shadows.", 500, 130, 0, 15, 0));
	shop.AddItem(Item("Shadow Chestplate", "Chestplate", "Blend in and move within the shadows.", 600, 200, 0, 30, 0));
	shop.AddItem(Item("Shadow Leggings", "Leggings", "Blend in and move within the shadows.", 580, 150, 0, 20, 0));
	shop.AddItem(Item("Shadow Boots", "Boots", "Blend in and move within the shadows.", 480, 120, 0, 10, 0));
}
// Level 5
void InitializeTavern6(Shop& shop) {
	shop.AddItem(Item("Mysterious Yellow Drink", "Consumable", "Perfectly Acidic and Tangy. Increases speed by +5 for the next battle.", 1, 0, 0, 5, 0));
	shop.AddItem(Item("Mysterious Red Drink", "Consumable", "A sweet drink, almost too sweet. Increases speed by +10 for the next battle.", 5, 0, 0, 10, 0));
	shop.AddItem(Item("Crispy Apple", "Consumable", "An apple a day keeps the doctor away. Recovers 10 health points.", 10, 10, 0, 0, 0));
	shop.AddItem(Item("Blue Bannana", "Consumable", "Why is it blue?. Increases speed stat by +20 for the next battle.", 10, 0, 0, 20, 0));
}
void InitializeShop11(Shop& shop) {
	shop.AddItem(Item("Inferno Dagger", "Weapon", "A dagger flickering with the flames of the fallen souls it has claimed.", 350, 0, 80, 50, 0));
	shop.AddItem(Item("Tears of Hell", "Weapon", "A glowing blade of passion at first glance, but if you listen closer, faint cries can be heard.", 400, 0, 90, 0, 0));
	shop.AddItem(Item("Blade of the Eternal", "Weapon", "A blade, never broken, only those of strong determination, can bare to wield it.", 500, 0, 100, 80, 20));
}
void InitializeShop12(Shop& shop) {
	shop.AddItem(Item("Inferno Cap", "Helmet", "Glowing with the passion of the heart.", 500, 150, 0, 20, 0));
	shop.AddItem(Item("Inferno Robes", "Chestplate", "Glowing with the passion of the heart.", 600, 250, 0, 40, 0));
	shop.AddItem(Item("Inferno Pants", "Leggings", "Glowing with the passion of the heart.", 550, 200, 0, 25, 0));
	shop.AddItem(Item("Inferno Boots", "Boots", "Glowing with the passion of the heart.", 480, 135, 0, 15, 0));
	shop.AddItem(Item("Overlord Helmet", "Helmet", "Only those recognized by them can dream of wearing it.", 600, 200, 0, 30, 0));
	shop.AddItem(Item("Overlord Chestplate", "Chestplate", "Only those recognized by them can dream of wearing it.", 800, 400, 0, 50, 0));
	shop.AddItem(Item("Overlord Leggings", "Leggings", "Only those recognized by them can dream of wearing it.", 750, 350, 0, 45, 0));
	shop.AddItem(Item("Overlord Boots", "Boots", "Only those recognized by them can dream of wearing it.", 550, 180, 0, 25, 0));
}