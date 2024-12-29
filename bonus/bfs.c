#include "so_long_bonus.h"

static void	*get_directions(t_positon *directions)
{
	directions[0].x = 0;
	directions[0].y = 1;
	directions[1].x = 0;
	directions[1].y = -1;
	directions[2].x = 1;
	directions[2].y = 0;
	directions[3].x = -1;
	directions[3].y = 0;
}

static int	verify_direction(t_game *game,int **visited, int x, int y)
{
	char	**map;
	int		rows;
	int		cols;

	rows = game->map_game.rows_map;
	cols = game->map_game.columns_map;
	map = game->map_game.map;
	if ((x < 0 || x >= rows) || (y < 0 || y>=cols))
		return (0);
	if (visited[x][y])
		return (0);
	if (map[x][y] == '1' || map[x][y] == 'C')
		return (0);
	if (map[x][y] == 'E' || map[x][y] == 'G')
		return (0);
	return (1);
}



void	bfs_looping(t_game *game ,t_queue *queue, t_positon target, int **visited)
{
	t_positon	directions[4];
	t_positon	current;
	t_positon	neighbor;
	int			i;

	get_directions(directions);
	while (!is_empty(queue))
	{
		current = dequeue(&queue);
		if (current.x == target.x && current.y == target.y)
			break;
		i = 0;
		while (i < 4)
		{
			neighbor.x = current.x + directions[i].x;
			neighbor.y = current.y + directions[i].y;
			if (verify_direction(game,visited,neighbor.x,neighbor.y))
				enqueue(&queue, neighbor);
			i++;
		}
	}
}

