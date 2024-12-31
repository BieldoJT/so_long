/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bieldojt <bieldojt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 23:18:58 by gda-conc          #+#    #+#             */
/*   Updated: 2024/12/31 18:15:21 by bieldojt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	destroy_img(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->collectible.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->exit_close.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->exit_open.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->floor.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->wall.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->enemy.img_ptr);
}

int	destroy_mlx_and_game(t_game *game)
{
	free_lst(game->enemies);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	free_tab(game->map_game.map);
	destroy_img(game);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free(game);
	exit(0);
	return (0);
}

void	finish_game(char *str, t_game *game)
{
	ft_putstr_fd(str, 1);
	destroy_mlx_and_game(game);
}


