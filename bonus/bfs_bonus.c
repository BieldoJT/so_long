/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bieldojt <bieldojt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:38:38 by gda-conc          #+#    #+#             */
/*   Updated: 2025/01/08 23:11:09 by bieldojt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	bfs_pathfinding(t_game *game, t_enemy *enemy, t_pos target)
{
	t_queue	*queue;
	t_comp	*bfs_components;

	bfs_components = malloc(sizeof(t_comp));
	bfs_components->grafh = init_graph(game);
	bfs_components->prev_pos = init_position(game);
	generate_graph(game, bfs_components);
	queue = init_queue();
	enqueue(&queue, enemy->pos_enemy);
	bfs_components->grafh[enemy->pos_enemy.x][enemy->pos_enemy.y] = 1;
	bfs_looping(game, &queue, target, bfs_components);
	free_queue(queue);
	get_next_move(game, bfs_components, enemy, target);
	free_bfs_components(bfs_components, game->map_game.rows_map);
}
