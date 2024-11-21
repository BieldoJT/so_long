/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-conc <gda-conc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:41:49 by gda-conc          #+#    #+#             */
/*   Updated: 2024/11/20 23:16:58 by gda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_var(t_map *map)
{
	t_content	wall;
	t_content	collectible;
	t_content	exit_map;
	t_player	player;

	wall.qtd = 0;
	collectible.qtd = 0;
	exit_map.qtd = 0;
	player.qtd = 0;
	map->wall = wall;
	map->collectible = collectible;
	map->exit_map = exit_map;
	map->player = player;

}

void	check_walls(t_map *map_game)
{
	int x;
	int y;
	int	len_x;
	int len_y;

	len_x = map_game->rows_map;
	len_y = map_game->columns_map;
	x = 0;
	while(x < len_x)
	{
		y = 0;
		while(y < len_y)
		{
			if(x == 0 && map_game->map[0][y] != '1') //checking in the beginnning
				error_map("wall is incomplete in the first row", map_game);
			else if(x == (len_x - 1) && map_game->map[x][y] != '1') //checking last row
				error_map("wall is incomplete in the last row", map_game);
			else if((map_game->map[x][0] != '1') || (map_game->map[x][len_y - 1] != '1')) //checking sides
				error_map("wall is incomplete in the sides", map_game);
			y++;
		}
		x++;
	}
}
