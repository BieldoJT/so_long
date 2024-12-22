/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-conc <gda-conc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:12:12 by gda-conc          #+#    #+#             */
/*   Updated: 2024/12/21 22:30:26 by gda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_enemy	*create_node_enemy(int pos_x, int pos_y)
{
	t_enemy	*node;

	node = malloc(sizeof(t_enemy));
	node->pos_enemy.x = pos_x;
	node->pos_enemy.y = pos_y;
	node->next = NULL;
	return (node);
}

void	create_lst_enemy(t_game *game)
{
	int		i;
	int		j;
	char	**map;
	t_enemy	*list_enemy;

	list_enemy = malloc(sizeof(t_enemy));
	map = game->map_game.map;
	i = 1;
	while(i <= game->map_game.rows_map - 1)
	{
		j = 1;
		while (j <= game->map_game.columns_map - 1)
		{
			if(map[i][j] == 'G')
				lst_add_back(&list_enemy, create_node_enemy(i,j));
			j++;
		}
		i++;
	}
	game->enemies = list_enemy;
}

//apagar essa função!!!
void testing_lst(t_enemy *lst)
{
	t_enemy *aux;

	aux = lst;
	while (aux != NULL)
	{
		printf("coordenada x: %i\ncoordenada y: %i\n", aux->pos_enemy.x, aux->pos_enemy.y);
		aux = aux->next;
	}
}
//fazer função pra dar free na lista encadeada

