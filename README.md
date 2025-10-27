# CUB3D

A Wolfenstein-style raycasting engine in C powered by MiniLibX. This repo contains two deliverables:

- mandatory/: the base project (parser + textured raycaster)
- BONUS/: enhanced features (mouse look, minimap, doors, gun HUD, etc.)

Both targets load a .cub file, parse textures and colors, validate the map, and render a 3D scene using DDA raycasting.


## Features

Mandatory
- Raycasting 3D renderer (textured walls)
- Header parsing: wall textures (NO/SO/WE/EA), floor/ceiling colors (F/C)
- Map validation (closed map, single player spawn, no invalid chars)
- Keyboard movement/rotation

Bonus (in addition to the above)
- Mouse look and edge re-centering
- Minimap overlay
- Doors (D) with opening animation and passability threshold
- Basic HUD gun animation (SPACE)


## Dependencies

- C toolchain (cc)
- libft (bundled in each target’s libft/)
- MiniLibX
	- Linux: clone/build MiniLibX for Linux into $HOME/minilibx-linux and install system deps
		- Debian/Ubuntu example: sudo apt-get install build-essential xorg libxext-dev zlib1g-dev libbsd-dev
	- macOS: BONUS includes minilibx_opengl_20191021/ and links against AppKit/OpenGL frameworks


## Build

Linux (example)
- Build BONUS: make -C BONUS
- Build mandatory: make -C mandatory

macOS (example)
- Ensure you’re using the BONUS target that vendors MiniLibX for macOS
- Build BONUS: make -C BONUS
- Build mandatory: provide your own MiniLibX for macOS or adapt the Makefile accordingly

Common Make targets
- make          build
- make clean    remove objects
- make fclean   remove objects and binary
- make re       clean rebuild

Build outputs
- BONUS/cube3d
- mandatory/cube3d


## Run

Provide a .cub file:

```
./cube3d ./maps/map_cube.cub
```

Run from within the corresponding subfolder (BONUS/ or mandatory/) so relative paths resolve. Default resolution is 1024x768 (SCREEN_WIDTH/SCREEN_HEIGHT).


## Controls

Mandatory
- W/S: forward/back
- A/D: strafe left/right
- Left/Right arrows: rotate
- ESC: quit

Bonus (adds)
- Mouse move: look around; cursor re-centers near window edges
- SPACE: play gun animation
- Doors (‘D’): open automatically when the player is near


## .cub file format

Header (order flexible, appears before the map):
- NO <path.xpm>  north wall texture
- SO <path.xpm>  south wall texture
- WE <path.xpm>  west wall texture
- EA <path.xpm>  east wall texture
- F r,g,b        floor color (0–255)
- C r,g,b        ceiling color (0–255)

Notes
- Paths must end with .xpm (parser enforces XPM)
- The parser accepts both compact and spaced color lines (e.g., F 139,69,19 or F 139, 69, 19)

Map grid (after the header):
- Characters
	- ‘1’ wall
	- ‘0’ empty space
	- ‘N’, ‘S’, ‘E’, ‘W’ player start with facing direction (exactly one required)
	- ‘D’ door (BONUS)
- Validation
	- Exactly one player
	- Outer borders must be closed with ‘1’ or spaces beyond walls
	- No invalid characters
	- No interior leaks: walkable tiles must not touch the void via spaces

Example

```
NO pics/north.xpm
SO pics/south.xpm
WE pics/west.xpm
EA pics/east.xpm
F 80,60,40
C 170,210,255

1111111111
1N00000001
1000111001
10D0000001
1111111111
```


## Project layout

- BONUS/
	- cub3d.h, src/*: core logic for bonus (raycasting, input, parsing, doors, minimap, gun)
	- libft/: bundled libft
	- minilibx_opengl_20191021/ (macOS)
	- maps/, pics/: sample maps/textures
- mandatory/
	- cub3d.h, src/*: core logic for mandatory subset
	- libft/: bundled libft
	- maps/, pics/: sample maps/textures
- README.md: this document


## Troubleshooting

- texture not found / invalid extension
	- Ensure texture paths exist and end with .xpm
	- Paths in .cub are relative to the runtime CWD (run from the target folder)

- Error: Map not valid
	- Most common causes: missing single player, open borders, invalid character
	- Check that the first and last non-space characters of each map row are ‘1’

- the start line should be space and '1' not '0'
	- A validation rule enforces rows to start with spaces and/or ‘1’, not immediately with a walkable ‘0’ leak

- Crashes or aborts
	- Rebuild fully (make re)
	- Verify your minilibx-linux install and X11 dependencies on Linux


## Implementation notes

- DDA raycasting per screen column; perpendicular wall distance to avoid fisheye
- Wall texture selection uses hit side and ray direction
- Colors: parsed by splitting numeric groups (robust to comma/space variants)
- Parsing transition fix: when the parser switches from header to map, it now processes that same line as the first map row (prevents skipping the first map line)


## Differences: mandatory vs bonus

Mandatory: core raycaster, keyboard movement, parser/validator.
Bonus: adds mouse look, minimap, animated doors, HUD gun.


## License

Educational project. Textures in pics/ are provided for development/testing.
=======
>>>>>>> 1606eed1b3e6f2f8813040df21f61d2291d1906e
