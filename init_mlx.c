#include "so_long.h"

int	init_create_win(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!(data->mlx_ptr))
	{
		printf("deu merdaa"); //put ft_printf
		mlx_destroy_display(data->mlx_ptr);
		return (0);
	}
	//name and size of new of window is here
	data->win_ptr = mlx_new_window(data->mlx_ptr,600,400,"teste"); 
	if (!(data->win_ptr))
	{
		printf("n criou a imagem"); //put ft_printf
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		return (0);
	}
	return (1);
}
