#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>

typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
	void *img;
	int x_img;
	int y_img;
} t_data;


int	init_create_win(t_data *data);
