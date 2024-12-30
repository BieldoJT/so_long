/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bieldojt <bieldojt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 23:18:40 by gda-conc          #+#    #+#             */
/*   Updated: 2024/12/30 14:54:43 by bieldojt         ###   ########.fr       */
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


typedef struct s_position
{
	int	x;
	int	y;
}	t_positon;

typedef struct s_queue {
	t_positon	pos;
	struct s_queue *next;
}	t_queue;



typedef struct s_enemy
{
	t_positon	pos_enemy;
	struct s_enemy	*next;
}	t_enemy;

typedef struct s_bfs_components
{
	int **grafh;
	t_positon **prev_pos;
}	t_bfs_components;


typedef struct s_map
{
	char		**map;
	int			rows_map;
	int			columns_map;
	int			map_alloc;
	int			collectible;
	int			exit_map;
	int			player_qtd;
	int			qtd_enemy;
	t_positon	player;
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
void	verify_new_line(char *map, t_game *game);
void	verify_alloc(t_game *game);

//print_error.c
void	error_map(char *message,t_game *game);
void	error_mlx(char *message, t_game *game);

//verify_map.c
void	init_var(t_game *map); //inicia as variaveis do map_game dentro do struct game
void	check_walls(t_game *map_game);
void	count_contents(t_game *map_game);
void	verify_content(t_game *map_game);
void	check_all_map(t_game *game);

//verify_path.c
char	**copy_map(t_game *game);
void	get_path(char **tab, t_game *game);
void	fill_map(char **tab, t_positon size, t_positon cur);
void	confirm_path(char **tab, t_game *game);
void	check_path(t_game *game);

//start_game.c
void	init_mlx(t_game *game);
t_image	get_img(void *mlx, char *path, t_game *game);
void	init_sprites(t_game *game);

//render_map.c
int		render(t_game *game);
void	put_to_window(t_game *game, char element, int row, int col);

//play_game
void	move_player(t_game *game, int pos_x, int pos_y);
int		input_game(int keysym, t_game *game);

//close_game.c
int		destroy_mlx_and_game(t_game *game);
void	finish_game(char *str, t_game *game);

//enemy_bonus.c
void	create_lst_enemy(t_game *game);
t_enemy	*create_node_enemy(int pos_x, int pos_y);
void	free_lst(t_enemy *lst);
void	chose_direcion(t_enemy *enemy, int delta_x, int delta_y);
void	move_enemy(t_game *game, t_positon player);

//queue_funct.c
t_queue	*init_queue();
int	is_empty(t_queue *queue);
void	enqueue(t_queue **queue, t_positon pos);
t_positon	dequeue(t_queue **queue);
void free_queue(t_queue *queue);

//bsf algorith
void bfs_pathfinding(t_game *game, t_enemy *enemy, t_positon target);

//bfs.c
void	bfs_looping(t_game *game ,t_queue **queue, t_positon target, t_bfs_components *components);
void	get_next_move(t_game *game, t_bfs_components *comp, t_enemy *enemy, t_positon target);

//create_visited
int **init_graph(t_game *game);
t_positon **init_position(t_game *game);
void	generate_graph(t_game *game, t_bfs_components *components);
void	free_bfs_components(t_bfs_components *components, int rows);


#endif
