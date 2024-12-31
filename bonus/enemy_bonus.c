/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bieldojt <bieldojt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:12:12 by gda-conc          #+#    #+#             */
/*   Updated: 2024/12/31 18:17:26 by bieldojt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_enemy	*create_node_enemy(int pos_x, int pos_y)
{
	t_enemy		*node;
	t_positon	pos;

	pos.x = pos_x;
	pos.y = pos_y;
	node = malloc(sizeof(t_enemy));
	node->pos_enemy = pos;
	node->next = NULL;
	return (node);
}

void	create_lst_enemy(t_game *game)
{
	int		i;
	int		j;
	char	**map;
	t_enemy	*node;
	t_enemy	*list_enemy;

	list_enemy = NULL;
	map = game->map_game.map;
	i = 1;
	while(i <= game->map_game.rows_map - 1)
	{
		j = 1;
		while (j <= game->map_game.columns_map - 1)
		{
			if(map[i][j] == 'G')
			{
				node = create_node_enemy(i,j);
				lst_add_back(&list_enemy, node);
			}
			j++;
		}
		i++;
	}
	game->enemies = list_enemy;
}


//fazer função pra dar free na lista encadeada

void	free_lst(t_enemy *lst)
{
	t_enemy	*aux;

	while (lst)
	{
		aux = lst->next;
		free(lst);
		lst = aux;
	}
}

void	move_enemy(t_game *game, t_positon player)
{
	t_enemy *enemy = game->enemies;

	while (enemy)
	{
		bfs_pathfinding(game, enemy, player);
		if (enemy->pos_enemy.x == player.x && enemy->pos_enemy.y == player.y)
			finish_game("Ohh, you touched the globin, you lose!!!\n",game);
		enemy = enemy->next;
	}

}

