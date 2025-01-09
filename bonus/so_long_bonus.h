/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bieldojt <bieldojt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 23:18:40 by gda-conc          #+#    #+#             */
/*   Updated: 2025/01/08 23:29:05 by bieldojt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../minilibx-linux/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../libraries/Libft/libft.h"
# include <stdio.h>

# define TRUE	1
# define FALSE	0

//numbers keysym keyboard
# define KEY_W	119
# define KEY_S	115
# define KEY_A	97
# define KEY_D	100
# define ESC	65307

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_queue
{
	t_pos			pos;
	struct s_queue	*next;
}	t_queue;

typedef struct s_enemy
{
	t_pos			pos_enemy;
	struct s_enemy	*next;
}	t_enemy;

typedef struct s_comp
{
	int		**grafh;
	t_pos	**prev_pos;
}	t_comp;

typedef struct s_map
{
	char	**map;
	int		rows_map;
	int		columns_map;
	int		map_alloc;
	int		collectible;
	int		exit_map;
	int		player_qtd;
	int		qtd_enemy;
	t_pos	player;
}	t_map;

typedef struct s_image
{
	void		*img_ptr;
	int			size_x;
	int			size_y;
}	t_image;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			movements;
	t_map		map_game;
	t_image		wall;
	t_image		floor;
	t_image		collectible;
	t_image		exit_open;
	t_image		exit_close;
	t_image		player;
	t_image		enemy;
	t_enemy		*enemies;
}	t_game;

//utils.c
char	*join_and_free(char *str_to_free, char *str_to_add);
void	free_tab(char **tab);
t_enemy	*lstlast(t_enemy *lst);
void	lst_add_back(t_enemy **lst, t_enemy *new);

//read_map.c
void	ft_check_command_line_arguments(int argc, char **argv, t_game *game);
void	read_file(char *argv, t_game *data);

//print_error.c
void	error_map(char *message, t_game *game);
void	error_mlx(char *message, t_game *game);

//verify_map.c
void	check_all_map(t_game *game);

//verify_path.c
void	check_path(t_game *game);

//start_game.c
void	init_mlx(t_game *game);
void	init_sprites(t_game *game);

//render_map.c
int		render(t_game *game);

//play_game
int		input_game(int keysym, t_game *game);

//close_game.c
int		destroy_mlx_and_game(t_game *game);
void	finish_game(char *str, t_game *game);

//enemy_bonus.c
void	create_lst_enemy(t_game *game);
void	free_lst(t_enemy *lst);
void	move_enemy(t_game *game, t_pos player);

//queue_funct.c
t_queue	*init_queue(void);
int		is_empty(t_queue *queue);
void	enqueue(t_queue **queue, t_pos pos);
t_pos	dequeue(t_queue **queue);
void	free_queue(t_queue *queue);

//bfs.c
void	bfs_pathfinding(t_game *game, t_enemy *enemy, t_pos target);

//bfs_utils.c
void	bfs_looping(t_game *game, t_queue **queue, t_pos target, t_comp *comp);
void	get_next_move(t_game *game, t_comp *comp, t_enemy *enemy, t_pos target);

//create_graph
int		**init_graph(t_game *game);
t_pos	**init_position(t_game *game);
void	generate_graph(t_game *game, t_comp *comp);
void	free_bfs_components(t_comp *comp, int rows);
#endif
