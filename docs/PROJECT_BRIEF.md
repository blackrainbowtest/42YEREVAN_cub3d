<a name="top"></a>
# [⬅️ Back to Main Documentation](README.md)

# Cub3D Project Brief

## One-minute summary

Cub3D is a small 3D engine built in C with MiniLibX.
It renders a pseudo-3D world using classic raycasting and a 2D map grid.

Core features:

- real-time raycast wall rendering
- keyboard movement and rotation
- minimap with direction and ray overlay
- texture loading and sampling

## Main challenges (and what solved them)

1. Fish-eye distortion while rotating/viewing side columns.
Fix: keep camera plane consistent with direction vector during rotation.
Reference: [player_rotate API](API/player/player_rotate.md), [camera_init API](API/app/camera_init.md)

2. Texture crawling/stretching when very close to a wall.
Fix: sample texture using full projected wall height, not clipped visible height.
Reference: [draw_column_pixels API](API/render/draw_column_pixels.md), [draw_wall_column API](API/render/draw_wall_column.md)

3. Stable movement near walls.
Fix: collision checks with player radius and axis-separated movement updates.
Reference: [player_move_forward API](API/player/player_move_forward.md)

4. Keep minimap visual/debug view aligned with world logic.
Fix: ray overlay derived from the same direction math and DDA hit points.
Reference: [draw_minimap_rays API](API/minimap/draw_minimap_rays.md), [raycast_dda API](API/raycast/raycast_dda.md)

## Quick links

- API index: [docs/API/README.md](API/README.md)
- Troubleshooting notes: [docs/TROUBLESHOOTING.md](TROUBLESHOOTING.md)
- Build/test notes: [docs/testing/testing.md](testing/testing.md)
- Roadmap: [docs/roadmap/roadmap.md](roadmap/roadmap.md)

---
[⬆️ Back to Top](#top)
