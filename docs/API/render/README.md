<a name="top"></a>
# [⬅️ Back to API Documentation](../README.md)

# Render API

This section documents frame rendering and wall-column drawing.

## Functions

| function name | Declaration | Description |
|--------|--------|--------|
| [ft_put_pixel](ft_put_pixel.md) | ```void ft_put_pixel(t_img *img, int x, int y, int color)``` | writes one pixel into image buffer |
| [render_frame](render_frame.md) | ```int render_frame(void *param)``` | per-frame update + draw + present |
| [render_scene](render_scene.md) | ```void render_scene(t_data *d)``` | loops over screen columns and renders walls |
| [render_wall_column](render_wall_column.md) | ```void render_wall_column(t_data *d, int x)``` | raycasts and renders one column |
| [draw_wall_column](draw_wall_column.md) | ```void draw_wall_column(t_data *d, int x, t_dda *r)``` | computes projected wall segment on screen |
| [draw_column_pixels](draw_column_pixels.md) | ```void draw_column_pixels(t_data *d, int x, int start, int end, int line_height, t_dda *r)``` | draws ceiling, textured wall slice, floor |

[⬆️ Back to Top](#top)
