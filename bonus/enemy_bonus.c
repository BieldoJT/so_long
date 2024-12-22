/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-conc <gda-conc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:12:12 by gda-conc          #+#    #+#             */
/*   Updated: 2024/12/22 01:00:35 by gda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_enemy	*create_node_enemy(int pos_x, int pos_y)
{
	t_enemy	*node;
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

//apagar essa função!!!
void testing_lst(t_enemy **lst)
{
	t_enemy *aux;

	aux = *lst;

	while (aux != NULL)
	{
		printf("coordenada x: %i\ncoordenada y: %i\n", aux->pos_enemy.x, aux->pos_enemy.y);
		aux = aux->next;
	}
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
void	chose_direcion(t_enemy *enemy, int delta_x, int delta_y)
{
	int	temp_x;
	int	temp_y;

	temp_x = delta_x;
	temp_y = delta_y;
	if (temp_x < 0)
		temp_x *= -1;
	if (temp_y < 0)
		temp_y *= -1;
	if (temp_x > temp_y)
	{
		if (delta_x > 0)
			enemy->pos_enemy.x++;
		else
			enemy->pos_enemy.x--;
	}
	else
	{
		if (delta_y > 0)
			enemy->pos_enemy.y++;
		else
			enemy->pos_enemy.y--;
	}
}


void	move_enemy(t_game *game, int pos_player_x, int pos_player_y)
{
	int		dist_x;
	int		dist_y;
	t_enemy	*enemy;
	char **map;

	map = game->map_game.map;
	enemy = game->enemies;
	while (enemy)
	{
		map[enemy->pos_enemy.x][enemy->pos_enemy.y] = '0';
		dist_x = pos_player_x - enemy->pos_enemy.x;
		dist_y = pos_player_y - enemy->pos_enemy.y;
		chose_direcion(enemy, dist_x, dist_y);
		map[enemy->pos_enemy.x][enemy->pos_enemy.y] = 'G';
		enemy = enemy->next;
	}
}

