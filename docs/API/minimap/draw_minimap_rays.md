<a name="top"></a>
# [⬅️ Back to MINIMAP Documentation](./README.md)

# draw_minimap_rays

Declaration:
```c
void draw_minimap_rays(t_data *d);
```

Purpose:

Draws a set of rays over the minimap inside configured minimap FOV.

Details:

- uses player angle from `atan2(dir_y, dir_x)`
- distributes rays across `MINIMAP_FOV`
- always draws exact facing ray as well

---
[⬆️ Back to Top](#top)
