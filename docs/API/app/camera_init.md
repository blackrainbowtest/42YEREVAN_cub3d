<a name="top"></a>
# [⬅️ Back to APP Documentation](./README.md)

# camera_init

Declaration:
```c
void camera_init(t_map *map);
```

Purpose:

Initializes the camera plane vector from the current player direction.

The camera plane is perpendicular to the direction vector and its length
controls the horizontal field of view.

Parameters:

`map`
Pointer to the map/game state structure.

Expected type:
```c
t_map *
```

Logic:

1. Compute plane length from FOV.
```c
plane_len = tan((SCENE_FOV * DEG_TO_RAD) / 2.0);
```

2. Build a perpendicular vector from direction.
```c
map->plane_x = -map->dir_y * plane_len;
map->plane_y = map->dir_x * plane_len;
```

Why this matters:

Ray directions are built as:

`ray_dir = dir + plane * camera_x`

If the plane is not consistent with direction, rendering gets distorted.

---
[⬆️ Back to Top](#top)
