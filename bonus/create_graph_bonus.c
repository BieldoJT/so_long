/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_graph_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bieldojt <bieldojt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 23:11:51 by bieldojt          #+#    #+#             */
/*   Updated: 2025/01/08 23:13:23 by bieldojt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	**init_graph(t_game *game)
{
	int	rows;
	int	cols;
	int	i;
	int	**visited;

	rows = game->map_game.rows_map;
	cols = game->map_game.columns_map;
	i = 0;
	visited = malloc(rows * sizeof(int *));
	while (i < rows)
	{
		visited[i] = malloc(cols * sizeof(int));
		i++;
	}
	return (visited);
}

t_pos	**init_position(t_game *game)
{
	int		rows;
	int		cols;
	int		i;
	t_pos	**positions;

	rows = game->map_game.rows_map;
	cols = game->map_game.columns_map;
	i = 0;
	positions = malloc(cols * sizeof(t_pos *));
	while (i < rows)
	{
		positions[i] = malloc(cols * sizeof(t_pos));
		i++;
	}
	return (positions);
}

void	generate_graph(t_game *game, t_comp *components)
{
	int	rows;
	int	cols;
	int	i;
	int	j;

	rows = game->map_game.rows_map;
	cols = game->map_game.columns_map;
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			components->grafh[i][j] = 0;
			components->prev_pos[i][j].x = -1;
			components->prev_pos[i][j].y = -1;
			j++;
		}
		i++;
	}
}

void	free_bfs_components(t_comp *components, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(components->grafh[i]);
		free(components->prev_pos[i]);
		i++;
	}
	free(components->grafh);
	free(components->prev_pos);
	free(components);
}
