<a name="top"></a>
# [⬅️ Back to MINIMAP Documentation](./README.md)

# draw_line

Declaration:
```c
void draw_line(t_data *d, t_line l);
```

Purpose:

Draws a line segment between two points using incremental interpolation.

Behavior:

- computes number of steps from max delta on X/Y
- interpolates floats
- writes rounded pixel positions

Used by direction and ray overlay drawing.

---
[⬆️ Back to Top](#top)
