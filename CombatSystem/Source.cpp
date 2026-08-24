#include <iostream>
#include <vector>
#include <string>

#include "GameSystem.h"

using namespace std;

int main() {
	Player player(PlayerName, 0, 0, 100, 5, 5, 50); // Initialize Player (string PlayerName, int PlayerLevel, int PlayerGold, int PlayerHealth, int PlayerStrength, int PlayerSpeed, int PlayerMana)
	player.InitializeSkills();
	// Initialize Levels
	CombatSystem combat;
	Map Map0;
	Map0.InitializeMap("Level0.txt");
	Level Level0(0, "Dawnlight Meadows", "Dawnlight");
	Level0.InitializeShopsForLevel0(Level0);
	Level0.InitializeLevel0Enemies(Level0);
	Map Map1;
	Map1.InitializeMap("Level1.txt");
	Level Level1(1, "Dwarven Mines", "Dripstone Caverns");
	Level1.InitializeShopsForLevel1(Level1);
	Level1.InitializeLevel1Enemies(Level1);
	Map Map2;
	Map2.InitializeMap("Level2.txt");
	Level Level2(2, "Fairy Falls", "Starlight Forest");
	Level2.InitializeShopsForLevel2(Level2);
	Level2.InitializeLevel2Enemies(Level2);
	Map Map3;
	Map3.InitializeMap("Level3.txt");
	Level Level3(3, "Elven Keep", "Elemental Plains");
	Level3.InitializeShopsForLevel3(Level3);
	Level3.InitializeLevel3Enemies(Level3);
	Map Map4;
	Map4.InitializeMap("Level4.txt");
	Level Level4(4, "Mysterious Sanctuary", "Dark Forest");
	Level4.InitializeShopsForLevel4(Level4);
	Level4.InitializeLevel4Enemies(Level4);
	Map Map5;
	Map5.InitializeMap("Level5.txt");
	Level Level5(5, "Black Market", "Inferno's Wraith");
	Level5.InitializeShopsForLevel5(Level5);
	Level5.InitializeLevel5Enemies(Level5);
	srand(time(NULL));
	// Initial Code only ran once at the beginning of the game
	cout << "You open your eyes to the bright light of the sun... Where are you?... Who are you?\nEnter Your Name: " << endl;
	cin >> PlayerName;
	player.setName(PlayerName);
	system("CLS");
	cout << "The floor is cold and hard, maybe you should walk around...\n(Press 'w', 'a', 's', or 'd' on your keyboard to walk around.)" << endl;
	cout << "Enter any letter to continue...";
	char input = _getch();
	system("CLS");
	LevelNumber = 0;
	// Game Loop that handles switching from one level to the next
	while (GameOver == false) {
		
		switch (LevelNumber) {
		case 0:
			RunGame(player, Level0, Map0, combat);
			break;
		case 1:
			RunGame(player, Level1, Map1, combat);
			InLevel = true;
			break;
		case 2:
			RunGame(player, Level2, Map2, combat);
			InLevel = true;
			break;
		case 3:
			RunGame(player, Level3, Map3, combat);
			InLevel = true;
			break;
		case 4:
			RunGame(player, Level4, Map4, combat);
			InLevel = true;
			break;
		case 5:
			RunGame(player, Level5, Map5, combat);
			InLevel = true;
			break;
		default:
			cout << "Failed to load level..." << endl;
			break;
		}
	}
	return 0;
}