/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bieldojt <bieldojt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 23:18:47 by gda-conc          #+#    #+#             */
/*   Updated: 2025/01/11 08:50:38 by bieldojt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//usar essa função pra saber os botoes no linux
int print_button(int KeyCode)
{
	printf("%d\n", KeyCode);

	return 0;
}

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
	render(game);
	mlx_key_hook(game->win_ptr, input_game, game);
	//usar essa função pra saber os botoes no linux
	//mlx_key_hook(game->win_ptr, print_button, game);
	mlx_hook(game->win_ptr, 17, 0, destroy_mlx_and_game, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}
