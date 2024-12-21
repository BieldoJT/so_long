/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-conc <gda-conc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:36:07 by gda-conc          #+#    #+#             */
/*   Updated: 2024/12/17 23:23:15 by gda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_map(char *message,t_game *game)
{
	int	i;

	i = 0;
	ft_putstr_fd("Error\n",2);
	ft_putstr_fd(message,2);
	ft_putstr_fd("\n",2);
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

void	error_mlx(char *message, t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	error_map(message, game);
}


