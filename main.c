#include "so_long.h"
int printa(int keycode,t_game *game)
{
	t_player pos;

	pos = game->player;
	printf("%d\n", keycode);
	if (keycode == 115)
		mlx_put_image_to_window(game->mlx_ptr,game->win_ptr,pos.cima.img_ptr,((game->map_game.columns_map - 1) * 32),((game->map_game.rows_map - 1) * 32));


	return 0;
}

int destroy_everything(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	free_tab(game->map_game.map);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free(game);
	exit(0);

	return 0;
}

int main(int argc, char **argv)
{
	t_game *game;

	game = malloc(sizeof(t_game));
	ft_check_command_line_arguments(argc, argv, game);
	read_file(argv[1], game);

	printf("Mapa carregado com sucesso!\n");
	printf("Número de linhas: %d\n", game->map_game.rows_map);
	printf("Número de colunas: %d\n", game->map_game.columns_map);

    // Exibir o mapa
	int i;
	for (i = 0; game->map_game.map[i]; i++)
		printf("%s\n", game->map_game.map[i]);

	check_all_map(game);

	//copy
	printf("\n\n");
	char **copy = copy_map(game);
	for (i = 0; copy[i]; i++)
		printf("%s\n", copy[i]);

	get_path(copy, game);
	confirm_path(copy,game);
	/*				// descomentar no confirm_path!!!!
	//copy
	printf("\n\n");
	for (i = 0; copy[i]; i++)
		printf("%s\n", copy[i]);*/


	init_mlx(game);
	init_sprites(game);

	mlx_put_image_to_window(game->mlx_ptr,game->win_ptr,game->floor.img_ptr,((game->map_game.columns_map - 1) * 32),((game->map_game.rows_map - 1) * 32));
	//mlx_put_image_to_window(game->mlx_ptr,game->win_ptr,game->player.img_ptr,((game->map_game.columns_map - 1) * 32),((game->map_game.rows_map - 1) * 32));
	mlx_key_hook(game->win_ptr,printa, game);
	mlx_hook(game->win_ptr, 17, 0, destroy_everything, game);
	mlx_loop(game->mlx_ptr);

/*
	for (i = 0; data.map[i]; i++)
		free(data.map[i]); // Liberar cada linha do mapa
	free(data.map);
*/
    return (0);
}
