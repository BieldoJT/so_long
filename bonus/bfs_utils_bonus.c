
#include "so_long_bonus.h"

static void	get_directions(t_positon *directions)
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

static int	verify_direction(t_game *game,int **graph, int x, int y)
{
	char	**map;
	int		rows;
	int		cols;

	rows = game->map_game.rows_map;
	cols = game->map_game.columns_map;
	map = game->map_game.map;
	if ((x < 0 || x >= rows) || (y < 0 || y>=cols))
		return (0);
	if (graph[x][y])
		return (0);
	if (map[x][y] == '1' || map[x][y] == 'C')
		return (0);
	if (map[x][y] == 'E' || map[x][y] == 'G')
		return (0);
	return (1);
}



void	bfs_looping(t_game *game ,t_queue **queue, t_positon target, t_bfs_components *components)
{
	t_positon	directions[4];
	t_positon	current;
	t_positon	neighbor;
	int			i;

	get_directions(directions);
	while (!is_empty(*queue))
	{
		current = dequeue(queue);
		if (current.x == target.x && current.y == target.y)
			break;
		i = 0;
		while (i < 4)
		{
			neighbor.x = current.x + directions[i].x;
			neighbor.y = current.y + directions[i].y;
			if (verify_direction(game,components->grafh,neighbor.x,neighbor.y))
			{
				enqueue(queue, neighbor);
				components->grafh[neighbor.x][neighbor.y] = 1;
				components->prev_pos[neighbor.x][neighbor.y] = current;
			}
			i++;
		}
	}
}

void	get_next_move(t_game *game, t_bfs_components *comp, t_enemy *enemy, t_positon target)
{
	char		**map;
	t_positon	next_move;
	t_positon	step;
	int			prev_x;
	int			prev_y;

	map = game->map_game.map;
	next_move = enemy->pos_enemy;
	step = target;
	prev_x = comp->prev_pos[step.x][step.y].x;
	prev_y = comp->prev_pos[step.x][step.y].y;
	while (prev_x != -1 && prev_y != -1)
	{
		next_move = step;
		step = comp->prev_pos[step.x][step.y];
		prev_x = comp->prev_pos[step.x][step.y].x;
		prev_y = comp->prev_pos[step.x][step.y].y;
	}
	if (map[enemy->pos_enemy.x][enemy->pos_enemy.y] == 'G') // update enemy pos
		map[enemy->pos_enemy.x][enemy->pos_enemy.y] = '0';
	enemy->pos_enemy = next_move;
	map[next_move.x][next_move.y] = 'G'; // update map
}

