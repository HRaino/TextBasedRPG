#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Map {
public:

	void InitializeMap(string filename);
	void DisplayMap(Player& player);
	void FindTile(Player& player);
	string CheckTile(int x, int y);

private:
	vector<string> Level;
};
// Basic logic for loading in a text file given it's file name
void Map::InitializeMap(string filename) {
	ifstream file;
	file.open(filename); // Open txt file named filename
	if (file.fail()) { // Checks if file opened successfully
		cout << "Error loading file..." << endl;
		exit(1);
	}
	string line; // Stores each line of the txt file
	while (getline(file, line)) { // while it is still able to retrieve lines from the file it will input those lines into the vector
		Level.push_back(line);
	}
}
// Prints out the map based on the player position so that it moves with the player in the center
void Map::DisplayMap(Player& player) {
	cout << "------------------" << endl;
	for (int y = player.getPlayerY() - 3; y < player.getPlayerY() + 4; y++) {
		cout << "|";
		for (int x = player.getPlayerX() - 8; x < player.getPlayerX() + 8; x++) {
			if (x == player.getPlayerX() && y == player.getPlayerY()) {
				cout << 'P';
			}
			else {
				cout << Level[y][x];
			}
		}
		cout << "|" << endl;
	}
	cout << "------------------" << endl;
}
// This is to set initial player position for when they initially load into a map
void Map::FindTile(Player& player) {
	for (int y = 0; y < Level.size(); y++) {
		for (int x = 0; x < Level[y].size(); x++) {
			if (Level[y][x] == 'L') {
				player.setPlayerLocation(x, y);
			}
		}
		cout << endl;
	}
}
// Method of identifying what tile is in what location
string Map::CheckTile(int x, int y) {
	if (Level[y][x] == '#') {
		return "wall";
	}
	else if (Level[y][x] == '.') {
		return "dot";
	}
	else if (Level[y][x] == ' ') {
		return "space";
	}
	else if (Level[y][x] == 'T') {
		return "town";
	}
	else if (Level[y][x] == 'B') {
		return "boss";
	}
	else if (Level[y][x] == 'L') {
		return "level";
	}
	cout << "failed";
}