/*

#include <unistd.h>

static int x = 20;
static int y = 20;
static int color = 0x00FF0000;*/

/*
int	buttun_press(int keysym, t_data *data)
{

	if(keysym == XK_Escape)
	{
		printf("precionei o %d, que é ESC\n", keysym);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(0);
	}
	else if(keysym == 113)
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
	else if (keysym == 114)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);


	/*
	else if(keysym == 114)
	{
		//mlx_clear_window(data->mlx_ptr, data->win_ptr);
		//mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 20, 0x00FF0000, "printei em vermelho");
		color = 0x00FF0000;
	}
	else if (keysym == 103)
	{
		//mlx_clear_window(data->mlx_ptr, data->win_ptr);
		//mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 20, 0x0000FF00, "printei em verde");
		color = 0x0000FF00;
	}
	else if (keysym == 65535)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
	}
	//mlx_string_put(data->mlx_ptr, data->win_ptr, x++, y++, 0x0000FF00, "printei em verde");
	printf("pressionei esse botão: %d\n", keysym);

	return (0);
}
*/
/*
int change_window(t_data *data)
{

	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_string_put(data->mlx_ptr, data->win_ptr, x++, y++, color, "printei em verde");
	usleep(1000 * 10);


	return (1);
}*/

/*
int main()
{
	t_data data;




	init_create_win(&data);

	//pega a imagem e bota no struct
	data.img =  mlx_xpm_file_to_image(data.mlx_ptr, "grass.xpm", &data.x_img, &data.y_img);
	printf("tamanho x da imagem%d\n tamanho y: %d\n\n", data.x_img, data.y_img);


	//mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img, 0, 0);
	// mlx_string_put(data.mlx_ptr, data.win_ptr, 20, 20, 0x0000FF00, "vamo ver se sobrepoe");

	mlx_key_hook(data.win_ptr,buttun_press, &data);
	//mlx_loop_hook(data.mlx_ptr, change_window, &data);
	mlx_loop(data.mlx_ptr);


	return 0;

}
*/
