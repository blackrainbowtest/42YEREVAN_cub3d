<a name="top"></a>
# [⬅️ Back to PLAYER Documentation](./README.md)

# player_rotate

Declaration:
```c
void player_rotate(t_data *d, double angle);
```

Purpose:

Rotates both view direction and camera plane by the given angle.

Parameters:

`angle` is in radians. Positive rotates right, negative rotates left.

Why both vectors rotate:

If only direction rotates and plane does not, rendering distortion appears.

---
[⬆️ Back to Top](#top)
