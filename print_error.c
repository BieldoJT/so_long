/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-conc <gda-conc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:36:07 by gda-conc          #+#    #+#             */
/*   Updated: 2024/11/20 23:13:44 by gda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_map(char *message,t_map *map_game)
{
	int i;

	i = 0;
	ft_printf("Error\n");
	perror(message);
	if (map_game->map_alloc == TRUE)
	{
		while (i < map_game->rows_map)
		{
			free(map_game->map[i]); // Liberar cada linha do mapa
			i++;
		}
		free(map_game->map);

	}
	//free(map_game);
	exit(EXIT_FAILURE);
}
