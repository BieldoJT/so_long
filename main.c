#include "so_long.h"

int main()
{
    t_map data;
    int i;



    read_file("maps/map.ber", &data);

    printf("Mapa carregado com sucesso!\n");
    printf("Número de linhas: %d\n", data.rows_map);
	printf("Número de colunas: %d\n", data.columns_map);

    // Exibir o mapa
	for (i = 0; data.map[i]; i++)
		printf("%s\n", data.map[i]);

	check_walls(&data);








/*
	for (i = 0; data.map[i]; i++)
		free(data.map[i]); // Liberar cada linha do mapa
	free(data.map);
*/
    return (0);
}
