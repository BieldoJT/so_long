/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bieldojt <bieldojt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:36:00 by gda-conc          #+#    #+#             */
/*   Updated: 2024/12/31 18:39:37 by bieldojt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_command_line_arguments(int argc, char **argv, t_game *game)
{
	int	map_parameter_len;

	game->map_game.map_alloc = FALSE;
	if (argc > 2)
		error_map("Too many arguments (It should be only two).", game);
	if (argc < 2)
		error_map("The Map file is missing.", game);
	map_parameter_len = ft_strlen(argv[1]);
	if (!ft_strnstr(&argv[1][map_parameter_len - 4], ".ber", 4))
		error_map("Map file extention is wrong (It should be .ber).", game);
}

static void	verify_alloc(t_game *game)
{
	int		i;
	size_t	len;

	i = 1;
	game->map_game.columns_map = ft_strlen(game->map_game.map[0]); //get number of colluns!
	len = game->map_game.columns_map;
	while(i < game->map_game.rows_map)
	{
		if (ft_strlen(game->map_game.map[i]) != len)
			error_map("column size diferent", game);
		i++;
	}
}

static void	verify_new_line(char *map, t_game *game)
{
	int	index;

	index = 0;
	if(map[0] == '\n')
	{
		free(map);
		error_map("map with \\n in the beginning", game);
	}
	if(map[ft_strlen(map) - 2] == '\n')
	{
		free(map);
		error_map("map with \\n in the end", game);
	}
	while(map[index + 1])
	{
		if(map[index] == '\n' && map[index + 1] == '\n')
		{
			free(map);
			error_map("map with \\n in the middle", game);
		}
		index++;
	}
}


void	read_file(char *argv, t_game *game)
{
	char	*temp_map;
	char	*line_temp;
	int		fd_map;

	game->map_game.rows_map = 0;
	fd_map = open(argv,O_RDONLY);
	if(fd_map == -1)
		error_map("The file couldn't be opened. verify name or if the file exists", game);
	temp_map = ft_strdup("");
	while(TRUE)
	{
		line_temp = get_next_line(fd_map);
		if(!line_temp)
			break;
		temp_map = join_and_free(temp_map, line_temp);
		free(line_temp);
		game->map_game.rows_map++;
	}
	close(fd_map);
	verify_new_line(temp_map, game);
	game->map_game.map = ft_split(temp_map, '\n');
	game->map_game.map_alloc = TRUE;
	free(line_temp);
	free(temp_map);
	verify_alloc(game);
}


