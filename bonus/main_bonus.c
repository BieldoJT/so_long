/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bieldojt <bieldojt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 23:18:47 by gda-conc          #+#    #+#             */
/*   Updated: 2025/01/08 23:15:42 by bieldojt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	ft_check_command_line_arguments(argc, argv, game);
	read_file(argv[1], game);
	check_all_map(game);
	check_path(game);
	init_mlx(game);
	init_sprites(game);
	create_lst_enemy(game);
	render(game);
	mlx_key_hook(game->win_ptr, input_game, game);
	mlx_hook(game->win_ptr, 17, 0, destroy_mlx_and_game, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}
