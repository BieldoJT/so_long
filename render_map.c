#include "so_long.h"


void	put_to_window(t_game *game, char element, int row, int col)
{
	void	*mlx;
	void	*win;
	void	*img_ptr;

	mlx = game->mlx_ptr;
	win = game->win_ptr;
	if(element == '0')
		img_ptr = game->floor.img_ptr;
	if(element == '1')
		img_ptr = game->wall.img_ptr;
	if(element == 'C')
		img_ptr = game->collectible.img_ptr;
	if(element == 'E')
	{
		if(game->map_game.collectible != 0)
			img_ptr = game->exit_close.img_ptr;
		else
			img_ptr = game->exit_open.img_ptr;
	}
	if(element == 'P')
		img_ptr = game->player.cima.img_ptr;

	mlx_put_image_to_window(mlx,win,img_ptr, (col * 32), (row * 32));
}

void	render(t_game *game)
{
	char	**map;
	int	col;
	int row;
	int i;
	int j;

	map = game->map_game.map;
	row = game->map_game.rows_map - 1;
	col = game->map_game.columns_map - 1;
	i = 0;
	while(i <= row)
	{
		j = 0;
		while (j <= col)
		{
			put_to_window(game, map[i][j], i, j);
			j++;
		}
		i++;
	}
	

}
