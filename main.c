#include "so_long.h"
/*int printa(int keycode,t_game *game)
{
	t_player pos;

	pos = game->player;
	printf("%d\n", keycode);
	if (keycode == 115)
		mlx_put_image_to_window(game->mlx_ptr,game->win_ptr,pos.cima.img_ptr,((game->map_game.columns_map - 1) * 32),((game->map_game.rows_map - 1) * 32));


	return 0;
}*/

int get_key(int keysym, t_game *game)
{
	printf("%d", keysym);
	//mlx_clear_window(game->mlx_ptr, game->win_ptr);
	render(game);
	
	return 0;
}



int main(int argc, char **argv)
{
	t_game *game;

	game = malloc(sizeof(t_game));
	ft_check_command_line_arguments(argc, argv, game);
	read_file(argv[1], game);
	check_all_map(game);
	check_path(game);
	init_mlx(game);
	init_sprites(game);
	render(game);
	mlx_key_hook(game->win_ptr,input_game,game);
	mlx_hook(game->win_ptr, 17, 0, destroy_everything, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}
