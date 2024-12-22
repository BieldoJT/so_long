/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-conc <gda-conc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 23:18:43 by gda-conc          #+#    #+#             */
/*   Updated: 2024/12/22 01:03:12 by gda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	change_pos(t_game *game, int pos_x, int pos_y)
{
	int	last_x;
	int	last_y;
	char **map;

	map = game->map_game.map;
	last_x = game->map_game.player.x;
	last_y = game->map_game.player.y;
	map[last_x][last_y] = '0';
	if (map[pos_x][pos_y] == 'C')
		game->map_game.collectible--;
	map[pos_x][pos_y] = 'P';
	game->map_game.player.x = pos_x;
	game->map_game.player.y = pos_y;
	game->movements++;
}
 //essa função é static??
void	move_player(t_game *game, int pos_x, int pos_y)
{
	char **map;

	map = game->map_game.map;
	if (map[pos_x][pos_y] == '1')
		return ;
	if (map[pos_x][pos_y] == 'E')
	{
		if (!game->map_game.collectible)
			finish_game("Congratulations, you win!!\n",game);
		else
			return ;
	}
	//fazer a função de andar o inimigo
	if (map[pos_x][pos_y] == 'G')
		finish_game("Ohh, you touched the globin, you lose!!!\n",game);
	move_enemy(game, pos_x, pos_y);
	change_pos(game, pos_x, pos_y);
}

int	input_game(int keysym, t_game *game)
{
	int	pos_player_x;
	int	pos_player_y;

	pos_player_y = game->map_game.player.y;
	pos_player_x = game->map_game.player.x;
	if (keysym == ESC)
		destroy_mlx_and_game(game);
	if (keysym == KEY_W)
		move_player(game,pos_player_x - 1, pos_player_y);
	if (keysym == KEY_S)
		move_player(game,pos_player_x + 1, pos_player_y);
	if (keysym == KEY_D)
		move_player(game,pos_player_x, pos_player_y + 1);
	if (keysym == KEY_A)
		move_player(game,pos_player_x, pos_player_y - 1);
	render(game);
	return (0);
}
