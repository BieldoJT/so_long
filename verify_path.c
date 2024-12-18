/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-conc <gda-conc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 23:19:58 by gda-conc          #+#    #+#             */
/*   Updated: 2024/12/17 23:22:17 by gda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(t_game *game)
{
	char	**copy;
	int	i;
	int	j;

	copy = malloc((game->map_game.rows_map + 1) * sizeof(char *));
	if (!copy)
		error_map("malloc error on copy", game);
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
			error_map("malloc error on copying map", game);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	fill_map(char **tab, t_positon size, t_positon cur)
{
	char	item;

	item = tab[cur.y][cur.x];
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x)
		return;
	if (item == '1' || item == 'X' || item == 'E')
		return;
	tab[cur.y][cur.x] = 'X';
	t_positon next;
	next = cur; next.x -= 1; fill_map(tab, size, next);
	next = cur; next.x += 1; fill_map(tab, size, next);
	next = cur; next.y -= 1; fill_map(tab, size, next);
	next = cur; next.y += 1; fill_map(tab, size, next);
}

void get_path(char **tab, t_game *game)
{
	t_positon	size;
	t_positon	begin;

	size.x = game->map_game.columns_map;
	size.y = game->map_game.rows_map;
	begin.x = game->map_game.player.y;
	begin.y = game->map_game.player.x;
	if (begin.x < 0 || begin.x >= size.x || begin.y < 0 || begin.y >= size.y)
	{
		free_tab(tab);
		error_map("Map has an invalid start", game);
	}
	fill_map(tab, size, begin);
}

void	confirm_path(char **tab, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while(i < game->map_game.rows_map)
	{
		j = 0;
		while (j < game->map_game.columns_map)
		{
			if(!(ft_strchr("01CEP",game->map_game.map[i][j])))
			{
				free_tab(tab);
				error_map("Map has an invalid caracter", game);
			}
			if (!(tab[i][j] == 'X' || tab[i][j] == '1' || tab[i][j] == '0' || tab[i][j] == 'E'))
			{
				free_tab(tab);
				error_map("Map has an invalid path", game);
			}
			j++;
		}
		i++;
	}
	free_tab(tab);
}

void	check_path(t_game *game)
{
	char	**copy;

	copy = copy_map(game);
	get_path(copy, game);
	confirm_path(copy,game);
}

