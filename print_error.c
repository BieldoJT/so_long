#include "so_long.h"

void	error_map(char *message,t_map *map_game)
{
	int i;

	i = 0;
	ft_printf("Error\n");
	perror(message);
	if (map_game->map_alloc == TRUE)
	{
		while (i < map_game->rows_map)
		{
			free(map_game->map[i]); // Liberar cada linha do mapa
			i++;
		}

	}
	free(map_game);
	exit(EXIT_FAILURE);
}
