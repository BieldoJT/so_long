/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-conc <gda-conc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:41:49 by gda-conc          #+#    #+#             */
/*   Updated: 2024/11/22 00:37:54 by gda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_var(t_game *game)
{
	game->map_game.collectible = 0;
	game->map_game.exit_map = 0;
	game->map_game.player.qtd = 0;
	game->movements = 0;
	game->map_game.columns_map = ft_strlen(game->map_game.map[0]) - 1;


}

void	check_walls(t_game *game)
{
	int x;
	int y;
	int	len_x;
	int len_y;

	len_x = game->map_game.rows_map;
	len_y = game->map_game.columns_map;
	x = 0;
	while(x < len_x)
	{
		y = 0;
		while(y < len_y)
		{
			if(x == 0 && game->map_game.map[0][y] != '1') //checking in the beginnning
				error_map("wall is incomplete in the first row", game);
			else if(x == (len_x - 1) && game->map_game.map[x][y] != '1') //checking last row
				error_map("wall is incomplete in the last row", game);
			else if((game->map_game.map[x][0] != '1') || (game->map_game.map[x][len_y - 1] != '1')) //checking sides
				error_map("wall is incomplete in the sides", game);
			y++;
		}
		x++;
	}
}

void	count_contents(t_game *game)
{
	int x;
	int y;

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
				game->map_game.player.qtd++;
			}
			if(game->map_game.map[x][y] == 'E')
				game->map_game.exit_map++;
			y++;
		}
		x++;
	}
}

void	verify_content(t_game *game)
{
	if(game->map_game.collectible < 1)
		error_map("Must have at least one collectible", game);
	else if(game->map_game.exit_map > 1)
		error_map("Must have just one exit", game);
	else if(game->map_game.player.qtd > 1)
		error_map("Must have just one starting point", game);

}


