<a name="top"></a>
# [⬅️ Back to LOADER Documentation](./README.md)

# load_textures

Declaration:
```c
int load_textures(t_data *d);
```

Purpose:

Loads all four wall textures (NO, SO, WE, EA) into `d->tex[]`.

Parameters:

`d` - global context with texture paths in `d->map`.

Return value:

`0` on success, `ERROR` on failure.

Logic:

Calls `load_texture(...)` for each texture slot.

Stops early and returns `ERROR` if any texture fails to load.

---
[⬆️ Back to Top](#top)
