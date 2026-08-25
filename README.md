# TextBasedRPG
In Console Text based RPG using Visual Studio and C++.

# Concept Overview:
ASCII style map that player can move around in containing the following tiles.

Symbols:
P - Player (gives a visual representation of the player position)
T - Town (when player walks into tile will show "Town" scenario)
L - Level (when player walks into tile, check if player has beat boss then gives option to go to next level)
B - Boss (when player walks into tile triggers boss fight for that level)

Map Tiles:
'#' - wall (player cannot move into or past this tile)
'.' - grass (when player walks into tile they have a random chance of triggering an enemy encounter)
' ' - space (just empty space that player can walk through and does/triggers nothing)

Each level has a collection of enemies and bosses specific to that floor that have their own stats (hp, atk, drops, etc). The town will also have three different shops that have their own items specific to each level.

# Visuals:

In-Game Display:

Whole Map:

Town scenario:

Combat scenario:

# Simplified Flowchart of Main Game Loop:
