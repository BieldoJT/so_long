/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-conc <gda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:41:49 by gda-conc          #+#    #+#             */
/*   Updated: 2025/01/08 13:37:58 by gda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	init_var(t_game *game)
{
	game->map_game.collectible = 0;
	game->map_game.exit_map = 0;
	game->map_game.player_qtd = 0;
	game->movements = 0;
	game->map_game.qtd_enemy = 0;
	game->map_game.columns_map = ft_strlen(game->map_game.map[0]);
}

static void	check_walls(t_game *game)
{
	int		x;
	int		y;
	int		len_x;
	int		len_y;
	char	**map;

	len_x = game->map_game.rows_map;
	len_y = game->map_game.columns_map;
	map = game->map_game.map;
	x = 0;
	while (x < len_x)
	{
		y = 0;
		while (y < len_y)
		{
			if (x == 0 && map[0][y] != '1')
				error_map("wall is incomplete in the first row", game);
			else if (x == (len_x - 1) && map[x][y] != '1')
				error_map("wall is incomplete in the last row", game);
			else if ((map[x][0] != '1') || (map[x][len_y - 1] != '1'))
				error_map("wall is incomplete in the sides", game);
			y++;
		}
		x++;
	}
}

static void	count_contents(t_game *game)
{
	int	x;
	int	y;

	x = 1;
	while(x < game->map_game.rows_map - 1)
	{
		y = 1;
		while (y < game->map_game.columns_map - 1)
		{
			if(game->map_game.map[x][y] == 'C')
				game->map_game.collectible++;
			if(game->map_game.map[x][y] == 'P')
			{
				game->map_game.player.x = x;
				game->map_game.player.y = y;
				game->map_game.player_qtd++;
			}
			if(game->map_game.map[x][y] == 'E')
				game->map_game.exit_map++;
			if (game->map_game.map[x][y] == 'G')
				game->map_game.qtd_enemy++;
			y++;
		}
		x++;
	}
}

static void	verify_content(t_game *game)
{
	if ((game->map_game.columns_map <= 2) || (game->map_game.rows_map <= 2))// Valida o tamanho
		error_map("Map has an invalid aaaa", game);
	if(game->map_game.collectible < 1)
		error_map("Must have at least one collectible", game);
	else if(game->map_game.qtd_enemy < 1)
		error_map("Must have at least one enemy", game);
	else if(game->map_game.exit_map != 1)
		error_map("Must have just one exit", game);
	else if(game->map_game.player_qtd != 1)
		error_map("Must have just one starting point", game);

}

void	check_all_map(t_game *game)
{
	init_var(game);
	check_walls(game);
	count_contents(game);
	verify_content(game);
}


