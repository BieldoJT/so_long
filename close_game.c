#include "so_long.h"

int	destroy_everything(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	free_tab(game->map_game.map);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free(game);
	exit(0);
	return (0);
}
