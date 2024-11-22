/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-conc <gda-conc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:36:07 by gda-conc          #+#    #+#             */
/*   Updated: 2024/11/22 00:38:46 by gda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_map(char *message,t_game *game)
{
	int i;

	i = 0;
	ft_printf("Error\n");
	perror(message);
	if (game->map_game.map_alloc == TRUE)
	{
		while (i < game->map_game.rows_map)
		{
			free(game->map_game.map[i]); // Liberar cada linha do mapa
			i++;
		}
		free(game->map_game.map);

	}
	free(game);
	exit(EXIT_FAILURE);
}
