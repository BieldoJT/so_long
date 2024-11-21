#ifndef SO_LONG_H
# define SO_LONG_H


# include "minilibx-linux/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "libraries/Libft/libft.h"
# include <stdio.h>

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;

} t_mlx;

# define TRUE	1
# define FALSE	0

typedef struct s_image
{
	void		*image;
	int			size_x;
	int			size_y;
}	t_image;



typedef struct s_contents
{
	t_image		img_content;
	int			qtd;
}	t_content;

typedef struct s_player
{
	t_image		img_player;
	int			pos_x;
	int			pos_y;
	int			qtd;
}	t_player;



typedef struct s_map
{
	char		**map;
	int			rows_map;
	int			columns_map;
	int			map_alloc;
	t_content	*wall;
	t_content	*collectible;
	t_content	*exit_map;
	t_player	*player;
}	t_map;



//utils.c
char	*join_and_free(char *str_to_free, char *str_to_add);

//read_map.c
void	read_file(char *argv, t_map *data);
void	verify_new_line(char *map, t_map *map_game);
void	verify_alloc(t_map *map_game);

//print_error.c
void	error_map(char *message,t_map *map_game);

//verify_map.c
void	init_var(t_map *map);
void	check_walls(t_map *map_game);



int		init_create_win(t_mlx *data);

#endif
