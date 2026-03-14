<a name="top"></a>
# [⬅️ Back to Main Documentation](README.md)

# Troubleshooting Notes

## Fish-eye distortion

Symptoms:

- walls bend or scale incorrectly near screen edges
- distortion increases after rotation

Cause:

- direction vector and camera plane get out of sync

Fix:

- rotate both `dir` and `plane`
- or recompute plane from direction each frame using FOV

References:

- [player_rotate API](API/player/player_rotate.md)
- [camera_init API](API/app/camera_init.md)
- [render_wall_column API](API/render/render_wall_column.md)

## Close-wall texture distortion

Symptoms:

- texture appears to crawl/stretch when standing very close to a wall

Cause:

- texture step computed from clipped screen height (`end - start`) instead of full projected wall height

Fix:

- compute texture step from full `line_height`
- compute texture start offset from full projection

References:

- [draw_wall_column API](API/render/draw_wall_column.md)
- [draw_column_pixels API](API/render/draw_column_pixels.md)

## Collision jitter at corners

Symptoms:

- player sticks or vibrates near wall corners

Fix:

- check player radius against wall cells
- apply movement per axis (X then Y) with separate collision checks

Reference:

- [player_move_forward API](API/player/player_move_forward.md)

---
[⬆️ Back to Top](#top)
