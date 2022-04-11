# wolf3d
Raycasting engine remade in C++ with SDL2.

![alt-text](https://i.imgur.com/JDhi7ie.png)

## How to Use
All you have to do is build the solution and drop
the exe in the base folder with the maps, tilesheet, bgm, and appropriate dlls.

## Maps
Maps are text files composed of numbers that signify which tile to display.
Each map is laid out in a rectangle, with a switch and a door needed to be able to progress.
Specifically, doors are tile 50, switches are tile 22, and secret doors are tile 33.
If you want to make a map without a switch, you can place an open door with tile 51.

## Controls
The game uses WASD or the arrow keys for movement, the Z key to sprint, Q and E to strafe,
Space to interact with switches and secret doors, and Escape to quit.
