<a name="top"></a>
# [⬅️ Back to RENDER Documentation](./README.md)

# draw_column_pixels

Declaration:
```c
void draw_column_pixels(t_data *d, int x, int start, int end,
        int line_height, t_dda *r);
```

Purpose:

Draws all pixels of one vertical screen column:

- ceiling part
- wall texture slice (or flat fallback color)
- floor part

Important close-wall detail:

Texture mapping uses the full projected `line_height`, not only clipped
`end - start`. This keeps texture sampling stable when walls are very close.

---
[⬆️ Back to Top](#top)
