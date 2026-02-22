#include "../minilibx-linux/mlx.h"
#include <stdlib.h>

# define MLX_ERROR		1
# define WINDOW_WIDTH	400
# define WINDOW_HEIGHT	400

int	main(void)
{
	t_mlx_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		retur(MLX_ERROR);
}
