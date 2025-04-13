# Cub3D – Wolfenstein-like Raycasting Game

![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)
![Language: C](https://img.shields.io/badge/language-C-blue.svg)
![Made at 42/Hive](https://img.shields.io/badge/made%20at-42%20Hive-blueviolet)
[![GitHub Repo](https://img.shields.io/badge/GitHub-cub3d-black?logo=github)](https://github.com/yourUser/cub3Ds)

> A full-featured 3D raycasting engine in C, inspired by Wolfenstein enhanced with a game logic.

[🔗 View on GitHub](https://github.com/yourUser/cub3D)

This project was created during my training at **42/Hive School**, expanding on the base Cub3D assignment to build a **dynamic** first person view experience with **additional storyline** elements. Beyond fundamental raycasting (wall projections, sprite management, etc.), this version introduces **A* pathfinding** for NPC behavior, **animated doors**, **dialogue systems**, **inventory items**, **minimap HUD**, and more.

By **developing** and **optimizing** core engine components like **camera transformations**, **texture mapping**, **drawing pixel directly into the image** and **event-driven interactions**, I improved my fluency in **low-level C programming** and **performance tuning**. The emphasis on **modularity** and **clean code** led to a well-structured codebase that's straightforward to maintain, debug, and extend.

Careful attention was given to **error handling**, **project architecture**, and **portability** across UNIX-like systems (using **MiniLibX**). The code is commented in a **Doxygen**-friendly style, ensuring each subsystem (rendering, AI, parsing, etc.) is easy to understand and integrate. In addition to satisfying the 42/Hive curriculum, Cub3D serves as a **springboard** for future C graphics or game development projects.

---

## ✨ Cub3D Features

<details>
<summary><strong>See Features</strong></summary>

Cub3D is designed to deliver a polished **Wolfenstein-like** experience in C, featuring advanced systems, optimized performance, and clear code structure.

**🔦 Extended Raycasting Engine**  
Built upon the classic DDA raycasting technique, the engine supports textured walls, multiple sprite types, and depth-based rendering for a more realistic 3D feel.

**🤖 Astar Pathfinding for NPC AI**  
NPCs can follow or chase the player using A*, navigating around walls and doors. This pathfinding system creates more challenging and dynamic enemy encounters and allows friendly NPCs to move intelligently.

**⚠️ Defensive Collision & Bounds Checking**  
Players and NPCs cannot pass through walls or doors incorrectly. The map's edges are checked to avoid out-of-bound behavior. Each collision scenario is handled gracefully, preventing game-breaking bugs.

**🚪 Interactive Objects & Doors**  
Doors feature open/close states, some locked behind specific items (keys). This interactive mechanic enriches the world with puzzle-like elements, requiring item usage and correct positioning.

**🗺️ Minimap & HUD Overlays**  
A real-time overhead display shows walls, the player, and NPCs. Additional HUD elements like FPS counters, messages, and item statuses provide quick, in-game feedback.

**🧪 Modular & Extensible**  
Each subsystem—rendering, pathfinding, interactions, story line is self-contained, making the code easier to maintain and integrate. This modular design also accelerates feature additions or refactors.

**📚 Clear Documentation & Structure**  
While not as exhaustive as a full Doxygen suite, the project includes concise function comments and more extensive ones for complex systems, a robust folder organization, and a minimal overhead for new contributors or students to grasp its architecture.

**🎮 Immersive Gameplay Loop**  
From roaming across the labyrinth to interacting with NPCs and finding a way to get everyone out of there, the story elements (dialogues, quests) enhance engagement beyond basic raycasting demos.

</details>

---
## 🚀 Usage
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

If you have any questions, suggestions, or feedback, feel free to reach out:

- **📧 Email:** nicolas.lovis@hotmail.fr
- **💻 GitHub:** [github.com/to0nsa](https://github.com/to0nsa)

You're also welcome to open an issue or leave a comment on the repository.
