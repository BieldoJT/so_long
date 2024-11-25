#include "so_long.h"

char	**copy_map(t_game *game)
{
	char	**copy;
	int	i;
	int	j;

	copy = malloc((game->map_game.rows_map + 1) * sizeof(char *));
	if (!copy)
		error_map("malloc error on copy", game); //n sei se vale a pena fazer isso
	i = 0;
	while (i < game->map_game.rows_map)
	{
		copy[i] = ft_strdup(game->map_game.map[i]);
		if (!copy[i])
		{
			j = 0;
			while(j < i)
				free(copy[j++]);
			free(copy);
			error_map("malloc error on copying map", game); //n sei se vale a pena fazer isso
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}



void	fill_map(char **tab, t_positon size, t_positon cur)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x)
		return;
	if (tab[cur.y][cur.x] == 1)
		return;

	tab[cur.x][cur.y] = 'X';
	cur.x -= 1;
	fill_map(tab, size, cur);
	cur.x += 1;
	fill_map(tab, size, cur);
	cur.y -= 1;
	fill_map(tab, size, cur);
	cur.y += 1;
	fill_map(tab, size, cur);
}

void	get_path(char **tab, t_game *game)
{
	t_positon size;
	t_positon begin;

	size.x = game->map_game.columns_map;
	size.y = game->map_game.rows_map;
	begin.x = game->map_game.player.x;
	begin.y = game->map_game.player.y;
	fill_map(tab, size, begin);
}
/*
void testmap(t_game *game)
{
	char **copia_map = copy_map(game);
}
*/
