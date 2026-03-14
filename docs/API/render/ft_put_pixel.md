<a name="top"></a>
# [⬅️ Back to RENDER Documentation](./README.md)

# ft_put_pixel

Declaration:
```c
void ft_put_pixel(t_img *img, int x, int y, int color);
```

Purpose:

Writes one pixel color directly into the image buffer.

Safety:

Performs bounds checks against window dimensions before writing.

Used by:

- wall rendering
- minimap drawing
- line and tile helpers

---
[⬆️ Back to Top](#top)
