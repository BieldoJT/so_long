/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-conc <gda-conc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:29:20 by gda-conc          #+#    #+#             */
/*   Updated: 2024/12/05 02:01:54 by gda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_mlx(t_game *game)
{
	int	width_win;
	int	height_win;

	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
	{
		free(game->mlx_ptr);
		error_map("error on initialize mlx",game);
	}
	width_win = game->map_game.columns_map * 32;
	height_win = game->map_game.rows_map * 32;
	game->win_ptr = mlx_new_window(game->mlx_ptr, \
		width_win, height_win, "so_long");
	if (game->win_ptr == NULL)
	{
		free(game->mlx_ptr);
		error_map("Error on creating a window",game);
	}
}

t_image	get_img(void *mlx, char *path, t_game *game)
{
	t_image img;

	img.img_ptr = mlx_xpm_file_to_image(mlx, path ,&img.size_x, &img.size_y);
	if (img.img_ptr == NULL)
	{
		free(img.img_ptr);
		error_mlx("Couldn't find a sprite. Does it exist?", game);
	}
	return (img);
}

void	init_sprites(t_game *game)
{
	void *mlx;


	mlx = game->mlx_ptr;
	game->wall = get_img(mlx, "textures/wall.xpm", game);
	game->player.cima = get_img(mlx, "textures/player/parado/cima/Player_Parado_Cima.xpm", game);
	game->floor = get_img(mlx,"textures/floor.xpm",game);
	game->exit_open = get_img(mlx,"textures/open_door.xpm", game);
	game->exit_close = get_img(mlx, "textures/closed_door.xpm", game);
	game->collectible = get_img(mlx,"textures/coletible/chicken.xpm", game);
}


