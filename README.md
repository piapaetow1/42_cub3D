# cub3D – The Museum

cub3D is a 42 project inspired by the classic raycasting technique used in early 3D games like Wolfenstein 3D.

In this implementation, the player explores a small virtual museum inspired by the Louvre. 
The project focuses on graphics programming, raycasting, event handling, and real-time rendering using the MiniLibX library.

---

## 🎨 Concept – The Museum

You find yourself inside a digital museum.

Walk through exhibition rooms, observe paintings, and explore the architecture from a first-person perspective.  
The project recreates a 3D environment using a 2D map and a raycasting engine.

---

# 🧱 Mandatory Part – Basic cub3D

The mandatory version includes:

- Raycasting engine
- Textured walls
- First-person movement
- Map parsing (.cub files)
- Player rotation and movement
- Collision detection

## 🎮 Controls (Mandatory)

| Key | Action |
|-----|--------|
| W | Move forward |
| A | Move left |
| S | Move backward |
| D | Move right |
| ← / → | Rotate camera |
| ESC | Exit program |

In this version, the player can freely walk through the museum and look around using the arrow keys.

---

# ⭐ Bonus Part – Extended Museum Experience

The bonus version expands the museum with interactive features:

- 🗺 Minimap
- 🖼 Animated paintings (sprites wobble)
- 🚪 Interactive doors

## 🎮 Additional Controls (Bonus)

| Key | Action |
|-----|--------|
| ENTER | Make paintings wobble |
| SPACE | Open / close doors |

### Bonus Features Explained

**Minimap**  
A real-time top-down minimap helps visualize the player’s position and orientation inside the museum.

**Animated Paintings (Sprites)**  
Pressing `ENTER` makes the paintings wobble, adding a dynamic effect to the exhibition.

**Interactive Doors**  
Doors are integrated into the map and can be opened or closed using `SPACE`.

---

# 🏗 Compilation

## Mandatory Version

```bash
make
```

Run with:
```bash
./cub3D cub/maps/<map_name>
```

Example:
```bash
./cub3D cub/maps/museum.cub
```

## Bonus Version

```bash
make bonus
```

Run with:
```bash
./cub3D_bonus bonus/maps/<map_name>
```

Example:
```bash
./cub3D_bonus bonus/maps/museum_bonus.cub
```

# 🧠 Technical Concepts

Raycasting algorithm  
DDA (Digital Differential Analyzer)   
Texture mapping  
Sprite rendering  
Event handling  
Real-time rendering  
2D map to 3D projection  
Collision detection  
Minimap rendering (bonus)  
Interactive objects (bonus)

# 📚 Technologies Used

C  
MiniLibX  
X11  
Math library  
Unix system calls  
