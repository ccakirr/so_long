# So Long 🎮

A simple 2D game developed as part of the 42 School curriculum. The player must collect all collectibles on the map and reach the exit with the minimum number of moves possible.

## 📋 Table of Contents

- [About](#about)
- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Map Format](#map-format)
- [Controls](#controls)
- [Project Structure](#project-structure)

## 📖 About

So Long is a small 2D game where the player navigates through a map, collecting coins and finding the exit. The project focuses on working with textures, sprites, and basic game mechanics using the MiniLibX graphics library.

This project is part of the 42 School common core curriculum and helps students understand:

- Window management
- Event handling
- Texture rendering
- Basic game loop implementation
- Map validation and pathfinding

## ✨ Features

- **Smooth movement** - Move your character with arrow keys or WASD
- **Collectibles** - Gather all coins before the exit opens
- **Animated sprites** - Coin animations for visual appeal
- **Move counter** - Track your efficiency with a movement counter
- **Map validation** - Comprehensive map checking for valid paths
- **Error handling** - Clear error messages for invalid maps or inputs

## 🛠️ Requirements

- GCC or Clang compiler
- Make
- X11 development libraries (for MiniLibX)
- Linux/Unix operating system

### Installing Dependencies (Ubuntu/Debian)

```bash
sudo apt-get update
sudo apt-get install gcc make xorg libxext-dev libbsd-dev
```

## 📥 Installation

1. Clone the repository:

```bash
git clone https://github.com/ccakirr/so_long.git
cd so_long
```

2. Compile the project:

```bash
make
```

This will create the `so_long` executable.

## 🎯 Usage

Run the game with a map file:

```bash
./so_long maps/test_map.ber
```

### Available Maps

The project includes several test maps in the `maps/` directory:

- `test_map.ber` - Small test map
- `easy_map_to_test.ber` - Easy level
- `map_42.ber` - Medium difficulty
- `big_map.ber` - Larger challenging map

## 🗺️ Map Format

Maps must be rectangular and saved with a `.ber` extension. They consist of the following characters:

| Character | Meaning                  |
| --------- | ------------------------ |
| `1`       | Wall                     |
| `0`       | Empty space              |
| `C`       | Collectible (coin)       |
| `E`       | Exit                     |
| `P`       | Player starting position |

### Map Rules

1. The map must be **rectangular**
2. The map must be **surrounded by walls** (1s)
3. Must contain:
   - Exactly **one exit** (E)
   - Exactly **one starting position** (P)
   - At least **one collectible** (C)
4. Must have a **valid path** from the player to all collectibles and the exit

### Example Map

```
111111111
100000001
1C0E0P0C1
100000001
111111111
```

## 🎮 Controls

| Key       | Action     |
| --------- | ---------- |
| `W` / `↑` | Move up    |
| `A` / `←` | Move left  |
| `S` / `↓` | Move down  |
| `D` / `→` | Move right |
| `ESC`     | Exit game  |

## 📁 Project Structure

```
so_long/
├── src/              # Source files
│   ├── main.c
│   ├── game_init.c
│   ├── map_parse.c
│   ├── validate_map.c
│   ├── floodfill.c
│   ├── load_textures.c
│   ├── render.c
│   ├── handle_input.c
│   └── exit_game.c
├── inc/              # Header files
│   └── so_long.h
├── utils/            # Utility functions
├── maps/             # Map files (.ber)
├── assets/           # Game textures/sprites
├── my_libs/          # External libraries
│   ├── minilibx-linux/
│   ├── get_next_line/
│   └── ft_printf/
├── Makefile
└── README.md
```

## 🏗️ Compilation

### Available Make Commands

- `make` - Compile the project
- `make clean` - Remove object files
- `make fclean` - Remove object files and executable
- `make re` - Recompile the project from scratch
- `make norm` - Check code against 42 norminette standards

## 🧪 Testing

To test the game with different scenarios:

1. **Valid map**: `./so_long maps/test_map.ber`
2. **Invalid map** (no exit): The program will display an error
3. **Invalid map** (not rectangular): The program will display an error
4. **No valid path**: The program will check and reject maps where collectibles or exit are unreachable

## 🐛 Common Issues

**Error: "Invalid map file!"**

- Check that your map follows all the rules listed above
- Ensure the map is rectangular
- Verify all collectibles and the exit are reachable

**Error: "Usage: ./so_long map_file.ber"**

- You need to provide a map file as an argument

**Compilation errors**

- Make sure all dependencies are installed
- Check that you're using a compatible operating system (Linux/Unix)

## 📝 License

This project is part of the 42 School curriculum and is meant for educational purposes.

## 👤 Author

**Caner Çakır**

- GitHub: [@ccakirr](https://github.com/ccakirr)

## 🙏 Acknowledgments

- 42 School for the project specifications
- MiniLibX team for the graphics library
- Fellow 42 students for testing and feedback

---

_Made with ❤️ at 42 Istanbul_
