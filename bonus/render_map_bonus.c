/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bieldojt <bieldojt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 23:18:37 by gda-conc          #+#    #+#             */
/*   Updated: 2024/12/31 19:06:58 by bieldojt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	put_to_window(t_game *game, char element, int row, int col)
{
	void	*mlx;
	void	*win;
	void	*img_ptr;

	mlx = game->mlx_ptr;
	win = game->win_ptr;
	if(element == '0')
		img_ptr = game->floor.img_ptr;
	if(element == '1')
		img_ptr = game->wall.img_ptr;
	if(element == 'C')
		img_ptr = game->collectible.img_ptr;
	if(element == 'E')
	{
		if(game->map_game.collectible != 0)
			img_ptr = game->exit_close.img_ptr;
		else
			img_ptr = game->exit_open.img_ptr;
	}
	if(element == 'P')
		img_ptr = game->player.img_ptr;
	if(element == 'G')
		img_ptr = game->enemy.img_ptr;
	mlx_put_image_to_window(mlx,win,img_ptr, (col * 32), (row * 32));
}

int	render(t_game *game)
{
	int		i;
	int		j;
	char	*print_moviments;
	char	*str_num;

	i = 0;
	while(i < game->map_game.rows_map)
	{
		j = 0;
		while (j < game->map_game.columns_map)
		{
			put_to_window(game, game->map_game.map[i][j], i, j);
			j++;
		}
		i++;
	}
	str_num = ft_itoa(game->movements);
	print_moviments = ft_strjoin("Moviments: ", str_num);
	mlx_string_put(game->mlx_ptr,game->win_ptr,10,10,0x34cfeb,print_moviments); //bonus
	free(str_num);
	free(print_moviments);
	return (0);
}
