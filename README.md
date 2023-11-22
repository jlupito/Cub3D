# Cub3D
Cub3D project for School 42

![Screenshot from 2023-11-22 11-53-54](https://github.com/jlupito/Cub3D/assets/113239012/4db3a1b4-2216-4e04-a35d-7249ab59cff7)

This is the second graphic project from 42 common core.
As the name stands, the idea is to create a very basic replicate of the famous Wolfenstein 3D game
(using 42 homemade minilibX as a graphic library).
This consists in diplaying a maze that fakes 3D through ray casting,
with a subjective view, the player can move inside the maze.
(bonuses include sprites, doors, minimap and wall handling - only the latter was handled here).

How to use this program:
- Compile with make
- Launch with ./cub3D and map.cub as argument
 (the map provides the 4 wall textures, ceiling and floor colors and the map to read
  composed with 0 (walkable area) and 1 (walls).


