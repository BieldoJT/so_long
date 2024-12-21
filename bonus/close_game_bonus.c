/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-conc <gda-conc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 23:18:58 by gda-conc          #+#    #+#             */
/*   Updated: 2024/12/21 18:40:51 by gda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	destroy_img(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->collectible.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->exit_close.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->exit_open.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->floor.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->wall.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player.img_ptr);
}

int	destroy_mlx_and_game(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	free_tab(game->map_game.map);
	destroy_img(game);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free(game);
	exit(0);
	return (0);
}

