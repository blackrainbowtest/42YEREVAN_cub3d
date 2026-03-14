<a name="top"></a>
# [⬅️ Back to API Documentation](../README.md)

# Minimap API

This section documents minimap rendering helpers and overlays.

## Functions

| function name | Declaration | Description |
|--------|--------|--------|
| [draw_minimap](draw_minimap.md) | ```void draw_minimap(t_data *d)``` | draws full minimap (tiles, player, direction, rays) |
| [draw_map_tiles](draw_map_tiles.md) | ```void draw_map_tiles(t_data *d)``` | draws each grid tile on minimap |
| [draw_player_minimap](draw_player_minimap.md) | ```void draw_player_minimap(t_data *d)``` | draws player marker on minimap |
| [draw_player_direction](draw_player_direction.md) | ```void draw_player_direction(t_data *d)``` | draws direction line from player |
| [draw_line](draw_line.md) | ```void draw_line(t_data *d, t_line l)``` | generic line draw helper (DDA style) |
| [draw_minimap_rays](draw_minimap_rays.md) | ```void draw_minimap_rays(t_data *d)``` | draws FOV rays on minimap |
| [get_player_minimap_pos](get_player_minimap_pos.md) | ```void get_player_minimap_pos(t_data *d, int *x, int *y)``` | converts player world position to minimap pixels |
| [draw_square](draw_square.md) | ```void draw_square(t_data *d, int x, int y, int color)``` | fills one minimap tile square |
| [draw_tile_with_border](draw_tile_with_border.md) | ```void draw_tile_with_border(t_data *d, int x, int y, int fill_color)``` | fills tile with border color |

[⬆️ Back to Top](#top)
