<a name="top"></a>
# [⬅️ Back to RAYCAST Documentation](./README.md)

# cast_dda

Declaration:
```c
void cast_dda(t_data *d, t_dda *r);
```

Purpose:

Performs DDA stepping through the grid until a wall is hit.

Parameters:

`d` - global context containing map grid.

`r` - initialized DDA state.

Logic:

1. Compare `side_x` and `side_y`.
2. Step to the nearest next grid boundary.
3. Update current map cell and which side was crossed.
4. Stop on wall or when `RAY_MAX_DIST` is reached.

Distance behavior:

`r->dist` stores wall distance used by rendering.

If no wall is hit before limit, distance is clamped to `RAY_MAX_DIST`.

---
[⬆️ Back to Top](#top)
