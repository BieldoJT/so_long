#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>

typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
} t_data;


int	pressionei_botao(int keysym, t_data *data)
{
	if(keysym == XK_Escape)
	{
		printf("precionei o %d, que é ESC\n", keysym);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(0);
	}
	printf("pressionei esse botão: %d\n", keysym);

	return (0);
}


int main()
{
	t_data data;

	data.mlx_ptr = mlx_init();
	if (!(data.mlx_ptr))
	{
		printf("deu merdaa");
		mlx_destroy_display(data.mlx_ptr);
		return 0;
	}
	data.win_ptr = mlx_new_window(data.mlx_ptr,600,400,"teste");
	if (!(data.win_ptr))
	{
		printf("n criou a imagem");
		mlx_destroy_window(data.mlx_ptr, data.win_ptr);
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return 0;
	}

	mlx_key_hook(data.win_ptr,pressionei_botao, &data);

	mlx_loop(data.mlx_ptr);


	return 0;

}
