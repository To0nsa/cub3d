# Cub3D – Raycasting Game

![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)
![Language: C](https://img.shields.io/badge/language-C-blue.svg)
![Made at 42/Hive](https://img.shields.io/badge/made%20at-42%20Hive-blueviolet)
[![GitHub Repo](https://img.shields.io/badge/GitHub-cub3d-black?logo=github)](https://github.com/yourUser/cub3Ds)

> This Cub3D project is more than a raycasting demo. It's a compact, full-featured engine built entirely in C, with puzzle mechanics, animation, and AI.

[🔗 View on GitHub](https://github.com/yourUser/cub3D)

This project was created during our training at **42/Hive School**, expanding on the base Cub3D assignment to build a **dynamic** first person view experience with **additional storyline** elements. Beyond fundamental raycasting (wall projections, sprite management...), this version introduces **A* pathfinding** for NPC behavior, **animated doors**, **dialogue systems**, **inventory items**, **minimap HUD**, and more.

By **developing** and **optimizing** core engine components like **camera transformations**, **texture mapping**, **drawing pixel directly into the image** and **event-driven interactions**, we improved our fluency in **low-level C programming** and **performance tuning**. The emphasis on **modularity** and **clean code** led to a well-structured codebase that's straightforward to maintain, debug, and extend.

Careful attention was given to **error handling**, **project architecture**, and **portability** across UNIX-like systems (using **MiniLibX**). The code is commented in a **Doxygen**-friendly style, ensuring each subsystem (rendering, AI, parsing, etc.) is easy to understand and integrate. In addition to satisfying the 42/Hive curriculum, Cub3D serves as a **springboard** for future C graphics or game development projects.

---

## 🎬 Demo

[![Cub3D Demo](https://img.youtube.com/vi/3mGU6aDea5c/0.jpg)](https://www.youtube.com/watch?v=3mGU6aDea5c)&#8203;

Click the image above to watch a short demo of the game in action on Youtube!

---

## ✨ Cub3D Features

<details>
<summary><strong>See Features</strong></summary>

Cub3D is designed to deliver a polished **Wolfenstein-like** experience in C, featuring advanced systems, optimized performance, and a modular codebase.

**🔦 Extended Raycasting Engine**  
Built upon the classic DDA raycasting technique, our engine supports:

- Textured wall rendering with proper depth and perspective
- Depth-based sprite rendering
- Efficient background drawing (floor and ceiling are pre-rendered once per frame)
- Fast Pixel Drawing, instead of relying on MiniLibX’s `put_pixel()` (which is slow), we write directly to the image buffer. This avoids costly per-pixel function calls and drastically improves frame rates.

**🤖 Astar Pathfinding for NPC AI**  
NPCs move intelligently using the A* algorithm:

- Dynamic chasing or random patrolling
- Doors are opened when blocking paths in follow mode
- Behaviors can be narrative-driven (chasing or following the player)
- The animation frame of NPCs is based on both their direction and the player’s view, creating a smoother and more reactive visual experience.

**⚠️ Defensive Collision & Bounds Checking**

- Wall and door collisions are solid for both players and NPCs
- Out-of-bounds detection ensures a stable and bug-free experience

**🚪 Interactive Objects & Doors**  

- Doors have open/closed states
- Some are locked behind specific items (e.g. keys)
- Objects in the world react based on proximity and player actions

**🪶 Dialogue & Storyline Integration**  

- NPCs react dynamically to your presence, progress, and choices. Every playthrough may differ slightly based on what you trigger.
- A generic raycast utility function that lets any entity or the player check what's in its surroundings Combined with an `is_facing_target` function, it enables smooth and realistic interactions between player, entities and the environment.

**🗺️ Minimap & HUD Overlays**  

- Real-time minimap showing player, NPCs, and static geometry
- HUD elements: FPS counter, status indicators, messages

**🧪 Modular & Extensible**  

Each subsystem (rendering, pathfinding, entity management, story line...) is cleanly separated:

- Easy to maintain
- Easy to expand (new enemy types, NPCs or interaction systems)

**📚 Clear Documentation & Structure**

- Concise comments on all functions
- Larger systems include more detailed comments to explain flow
- Folder layout reflects logical system divisions for easier onboarding

</details>

---

## 🚀 Usage

Easy to install and play on linux and mac.

<details>
<summary><strong> See Usage Guide  </strong></summary>

**1.** Clone the repository (with submodules)

```bash
git clone --recurse-submodules https://github.com/to0nsa/cub3d.git
```

> If you already cloned it without submodules, then run:

```bash
git submodule update --init --recursive
```

**2.** Install dependencies
A make setup rule is provided, it attempts to install essential packages on macOS or Debian/Ubuntu-based Linux to be able to compile the executable:

```bash
make setup
```

> ⚠️ Note: MiniLibX is not compatible with Windows. The project can only be built and run on macOS or Linux systems.

**3.** Build the project
This compiles all sources as well as the correct MiniLibX (macOS or Linux).

```bash
make
```

**4.** Clean and rebuild

Clean object files (and all sub-projects):

```bash
make clean
```

Remove everything (binary + object files):

```bash
make fclean
```

Full rebuild (equivalent to fclean then make):

```bash
make re
```

**5.** Run
Start the cub3D executable:

```bash
./cub3D maps/adventure.cub
```

</details>

---

## 📝 License

This project is licensed under the [MIT License](LICENSE).

You are free to use, modify, and distribute this code for academic, personal, or professional purposes. Attribution is appreciated but not required.

---

## 📬 Contact

Developpers:

- 💻 GitHub: [github.com/to0nsa](https://github.com/to0nsa)
- 💻 GitHub: [github.com/rinatiamaev](https://github.com/rinatiamaev)

If you have any questions, suggestions, or feedback, feel free to reach out:

- **📧 Email:** nicolas.lovis@hotmail.fr

You're also welcome to open an issue or leave a comment on the repository.
