#include "so_long.h"

int main()
{
	t_game *game;



	game = malloc(sizeof(t_game));


    read_file("maps/map.ber", game);

	printf("Mapa carregado com sucesso!\n");
	printf("Número de linhas: %d\n", game->map_game.rows_map);
	printf("Número de colunas: %d\n", game->map_game.columns_map);

    // Exibir o mapa
	int i;
	for (i = 0; game->map_game.map[i]; i++)
		printf("%s\n", game->map_game.map[i]);

	check_all_map(game);

	//copy
	printf("\n\n");
	char **copy = copy_map(game);
	for (i = 0; copy[i]; i++)
		printf("%s\n", copy[i]);

	get_path(copy, game);

	//copy
	printf("\n\n");
	for (i = 0; copy[i]; i++)
		printf("%s\n", copy[i]);




/*
	for (i = 0; data.map[i]; i++)
		free(data.map[i]); // Liberar cada linha do mapa
	free(data.map);
*/
    return (0);
}
