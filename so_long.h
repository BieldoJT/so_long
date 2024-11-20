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
	void *mlx_ptr;
	void *win_ptr;

} t_mlx;

# define TRUE	1
# define FALSE	0



typedef struct s_map
{
	char	**map;
	int	rows_map;
	int	columns_map;
	int	map_alloc;
}	t_map;


char	*join_and_free(char *str_to_free, char *str_to_add);


void	get_map(char *argv, t_map *data);
void	verify_map(char *map, t_map *map_game);
void	verify_alloc(t_map *map_game);

void	error_map(char *message,t_map *map_game);

int		init_create_win(t_mlx *data);

#endif
