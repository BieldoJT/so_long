#include "so_long_bonus.h"

int **init_visited(t_game *game)
{
	int rows;
	int cols;
	int i;
	int **visited;

	rows = game->map_game.rows_map;
	cols = game->map_game.columns_map;
	i = 0;
	visited = malloc(rows * sizeof(int*));
	while (i < rows)
	{
		visited[i] = malloc(cols * sizeof(int));
		i++;
	}
	return visited;
}

t_positon **init_position(t_game *game)
{
	int rows;
	int cols;
	int i;
	t_positon **positions;

	rows = game->map_game.rows_map;
	cols = game->map_game.columns_map;
	i = 0;
	positions = malloc(cols * sizeof(t_positon*));
	while (i < rows)
	{
		positions[i] = malloc(cols * sizeof(t_positon));
		i++;
	}
	return positions;
}

void generate_visited(t_game *game, int **visited, t_positon **prev)
{
	int rows;
	int cols;
	int i;
	int j;

	rows = game->map_game.rows_map;
	cols = game->map_game.columns_map;
	i = 0;
	while(i < rows)
	{
		j = 0;
		while (j < cols)
		{
			visited[i][j] = 0;
			prev[i][j].x = -1;
			prev[i][j].y = -1;
			j++;
		}
		i++;
	}
}


