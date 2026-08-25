# TextBasedRPG
In Console Text based RPG using Visual Studio and C++. The "CombatSystem" folder is the file that contains all the txt files for the maps, and the code for the game. Overall, this was my first programming project that I wrote in 2023 that I am now uploading to github. It uses basic logic components like if statements, for loops, while loops, arrays, vectors, etc. Hence all the nested logic and inefficient code that is in this project. Though I think its still a cool project for me at the time that helped me really understand objects and classes. Below I explain the main game loop and a lot of things that can be customized in code.

## Concept Overview:
ASCII style map that player can move around in containing the following tiles.

| Symbol  | Explanation |
| ------------- | ------------- |
| P | Player (gives a visual representation of the player position) |
| T | Town (when player walks into tile will show "Town" scenario) |
| L | Level (when player walks into tile, check if player has beat boss then gives option to go to next level) |
| B | Boss (when player walks into tile triggers boss fight for that level) |

| Map Tiles  | Explanation |
| ------------- | ------------- |
| '#' | wall (player cannot move into or past this tile) |
| '.' | grass (when player walks into tile they have a random chance of triggering an enemy encounter) |
| ' ' | space (just empty space that player can walk through and does/triggers nothing) |

Maps are individual to each level and are loaded at the start of the game from text files. Meaning these text files can be edited/customized to make different maps utilizing the above mentioned "Tiles". Size of maps can be made bigger or smaller through the text file as well. Below is some images of the text files that are currently in the game.

![Example Image of Text File Map 1 ](TextBasedRPG-Map1IMG.png)

![Example Image of Text File Map 2 ](TextBasedRPG-Map2IMG.png)

## Simplified Flowchart of Main Game Loop:
