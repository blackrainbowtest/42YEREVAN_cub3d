<a name="top"></a>
# [⬅️ Back to RENDER Documentation](./README.md)

# render_frame

Declaration:
```c
int render_frame(void *param);
```

Purpose:

Executes one full frame:

1. update player state
2. render 3D scene
3. render minimap overlay
4. push image to window

Return value:

Returns `0` for MLX loop compatibility.

---
[⬆️ Back to Top](#top)
