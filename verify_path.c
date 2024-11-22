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



void	fill_map(char **tab, t_positon size, t_positon cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
			|| tab[cur.y][cur.x] != to_fill)
		return;

	tab[cur.y][cur.x] = 'P';
	fill_map(tab, size, (t_positon){cur.x - 1, cur.y}, to_fill);
	fill_map(tab, size, (t_positon){cur.x + 1, cur.y}, to_fill);
	fill_map(tab, size, (t_positon){cur.x, cur.y - 1}, to_fill);
	fill_map(tab, size, (t_positon){cur.x, cur.y + 1}, to_fill);
}

void	get_path(char **tab, t_positon size, t_positon begin)
{
	fill_map(tab, size, begin, tab[begin.y][begin.x]);
}
