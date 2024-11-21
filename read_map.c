/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-conc <gda-conc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:36:00 by gda-conc          #+#    #+#             */
/*   Updated: 2024/11/20 22:50:20 by gda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void verify_alloc(t_map *map_game)
{
	int i;
	size_t len;

	i = 1;

	map_game->columns_map = ft_strlen(map_game->map[0]); //get number of colluns!
	len = map_game->columns_map;
	while(i < map_game->rows_map)
	{
		if (ft_strlen(map_game->map[i]) != len)
			error_map("column size diferent", map_game);
		i++;
	}
}

void	verify_new_line(char *map, t_map *map_game)
{
	int index;

	index = 0;
	if(map[0] == '\n')
	{
		free(map);
		error_map("map with \\n in the beginning", map_game);
	}
	if(map[ft_strlen(map) - 2] == '\n')
	{
		free(map);
		error_map("map with \\n in the end", map_game);
	}
	while(map[index + 1])
	{
		if(map[index] == '\n' && map[index + 1] == '\n')
		{
			free(map);
			error_map("map with \\n in the middle", map_game);
		}
		index++;
	}
}


void	read_file(char *argv, t_map *data)
{
	char	*temp_map;
	char	*line_temp;
	int		fd_map;

	data->rows_map = 0;
	fd_map = open(argv,O_RDONLY);
	temp_map = ft_strdup("");
	while(TRUE)
	{
		line_temp = get_next_line(fd_map);
		if(!line_temp)
			break;
		temp_map = join_and_free(temp_map, line_temp);
		free(line_temp);
		data->rows_map++;
	}
	close(fd_map);
	verify_new_line(temp_map, data);
	data->map = ft_split(temp_map, '\n');
	data->map_alloc = TRUE;
	free(line_temp);
	free(temp_map);
	verify_alloc(data);
}


