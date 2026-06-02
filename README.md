# Dodoi-Engine - version 0.22.1

A lightweight 2D game engine for **Nintendo GameCube** homebrew, built in C using the [devkitPPC](https://devkitpro.org/) toolchain and SDL2.

Developed by **Hudson Schumaker** — [Dodoi-Lab](https://github.com/Dodoi-Lab) © 2024

---

## Features

- **Scene system** — lifecycle callbacks (`load`, `input`, `update`, `render`, `run`, `unload`) with clean scene transitions
- **2D Graphics** — SDL2-backed renderer, color utilities, horizontal & vertical parallax scrolling
- **Game Objects** — position, size, z-ordering, active flag, and AABB box-collider support
- **Sound & Music** — load/play/pause/stop via SDL2_mixer (supports `.wav` and `.ogg`)
- **UI Widgets** — button, image, and label components
- **Math utilities** — LUT-based sin/cos/atan tables for performance on fixed-point hardware
- **Tile maps** — grid and map helpers with configurable tile sizes
- **Smooth delta time** — exponential moving-average frame timing, capped at 250 ms
- **Camera** — 2D camera system

---

## Project Structure

```
src/
├── core/        # Engine init/quit, context (window + renderer), camera
├── gfx/         # Scene, graphics helpers, parallax scrolling
├── sfx/         # Sound effects and music (SDL_mixer)
├── ui/          # Button, image, label widgets
├── math/        # 2D math with LUT-based trigonometry
├── util/        # Grid and tile-map utilities
└── playground/  # Splash screen and level prototypes
data/            # Binary assets (images, audio, fonts) embedded at build time
build/           # Intermediate object files (generated)
bin/             # Output .elf / .dol binaries (generated)
```

---

## Requirements

| Tool | Notes |
|------|-------|
| [devkitPro](https://devkitpro.org/wiki/Getting_Started) | Install the `gamecube-dev` group |
| `DEVKITPPC` env var | Must point to your devkitPPC installation |
| SDL2 port libs | `gamecube-sdl2`, `gamecube-sdl2_ttf`, `gamecube-sdl2_gfx`, `gamecube-sdl2_mixer`, `gamecube-sdl2_image` |
| freetype2 | Bundled via devkitPro portlibs |

---

## Building

```sh
# Set the devkitPPC path (add to your shell profile)
export DEVKITPPC=/opt/devkitpro/devkitPPC

make        # Build → produces bin/<project>.elf and bin/<project>.dol
make clean  # Remove build artefacts
```

The `.dol` file can be run on real hardware via a loader (e.g. SD Gecko + Swiss) or in an emulator such as [Dolphin](https://dolphin-emu.org/).

---

## License

This project is licensed under the terms found in [LICENSE](LICENSE).
