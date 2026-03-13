<a name="top"></a>
# [⬅️ Back to Main Documentation](../README.md)

## HITIN (Priority Legend):
⬜ — normal priority  
🟩 — low priority  
🟦 — high priority  
🟫 — critical  
✅ — done  

## 🟢 STAGE 1 — PROJECT SKELETON
- ✅ TODO: create Makefile
- ✅ TODO: link mlx and libft correctly
- ✅ TODO: create base headers (cub3d.h)
- 🟩 TODO: create main.c
- 🟦 TODO: create basic structs (t_data, t_map, t_player)
- 🟩 TODO: init mlx (mlx_init + mlx_new_window)
- 🟫 TODO: handle clean exit (ESC + window close)

## 🟡 STAGE 2 — PARSING .cub FILE
- ⬜ TODO: open .cub file
- ⬜ TODO: read file line by line (get_next_line)
- ⬜ TODO: store file content in dynamic array
- ⬜ TODO: create validator module

### Validator subtasks:
- ⬜ TODO: check file extension (.cub)
- ⬜ TODO: validate texture identifiers (NO, SO, WE, EA)
- ⬜ TODO: validate floor and ceiling colors
- ⬜ TODO: validate RGB format (0-255)
- ⬜ TODO: extract map section
- ⬜ TODO: normalize map (pad shorter lines)
- ⬜ TODO: validate allowed characters (01NSEW)
- ⬜ TODO: validate single player spawn
- ⬜ TODO: validate map is closed (flood fill)

## 🟠 STAGE 3 — DATA INITIALIZATION
- ✅ TODO: initialize player position
- ✅ TODO: initialize player direction vector
- ✅ TODO: initialize camera plane vector
- ⬜ TODO: load textures (mlx_xpm_file_to_image)
- ⬜ TODO: create image buffer
- ⬜ TODO: get image data address

## 🔵 STAGE 4 — RAYCASTING ENGINE
- ⬜ TODO: create render loop
- ⬜ TODO: for each screen column cast ray
- ⬜ TODO: calculate ray direction
- ⬜ TODO: implement DDA algorithm
- ⬜ TODO: detect wall hit
- ⬜ TODO: calculate perpendicular wall distance
- ⬜ TODO: calculate line height
- ⬜ TODO: calculate draw start / draw end
- ⬜ TODO: choose texture based on wall side
- ⬜ TODO: calculate texture x coordinate
- ⬜ TODO: draw vertical stripe

## 🟣 STAGE 5 — PLAYER MOVEMENT
- ✅ TODO: handle W key (move forward)
- ✅ TODO: handle S key (move backward)
- ✅ TODO: handle A key (strafe left)
- ✅ TODO: handle D key (strafe right)
- ✅ TODO: handle LEFT arrow (rotate left)
- ✅ TODO: handle RIGHT arrow (rotate right)
- ✅ TODO: implement wall collision

## 🔴 STAGE 6 — CLEAN ARCHITECTURE
- ⬜ TODO: separate modules (parsing, render, events, utils)
- ⬜ TODO: no more than 5 functions per file
- ⬜ TODO: no memory leaks (valgrind clean)
- ⬜ TODO: free textures on exit
- ⬜ TODO: free map properly
- ⬜ TODO: destroy images and window

⚫ BONUS
- ⬜ TODO: implement minimap
- ⬜ TODO: mouse rotation
- ⬜ TODO: door support
- ⬜ TODO: animated sprites
- ⬜ TODO: sprite rendering (enemies)

---

### Suggested File Structure

``` bash
src/
    main.c
    init.c
    parsing/
        parse_file.c
        validate_map.c
        validate_textures.c
    render/
        render.c
        raycast.c
        draw.c
    player/
        movement.c
        rotation.c
    utils/
        free.c
        error.c
include/
    cub3d.h
```

[⬆️ Back to Top](#top)