#include <stdio.h>

// Função recursiva para explorar o mapa
void explore_map(char **map, int rows, int cols, int x, int y, int *collectibles, int *reached_exit) {
    // Verificar limites do mapa
    if (x < 0 || y < 0 || x >= rows || y >= cols)
        return;

    // Parar se encontrar uma parede ou célula já visitada
    if (map[x][y] == '1' || map[x][y] == 'V')
        return;

    // Coletar colecionável
    if (map[x][y] == 'C') {
        (*collectibles)--;
    }

    // Verificar se alcançou a saída
    if (map[x][y] == 'E') {
        *reached_exit = 1;
    }

    // Marcar célula como visitada
    map[x][y] = 'V';

    // Movimentos recursivos
    explore_map(map, rows, cols, x - 1, y, collectibles, reached_exit); // Cima
    explore_map(map, rows, cols, x + 1, y, collectibles, reached_exit); // Baixo
    explore_map(map, rows, cols, x, y - 1, collectibles, reached_exit); // Esquerda
    explore_map(map, rows, cols, x, y + 1, collectibles, reached_exit); // Direita
}

// Função principal para verificar se há um caminho válido
void validate_path(char **map, int rows, int cols, int start_x, int start_y, int collectibles) {
    int reached_exit = 0;

    // Explorar o mapa a partir da posição inicial
    explore_map(map, rows, cols, start_x, start_y, &collectibles, &reached_exit);

    // Verificar se o caminho é válido
    if (collectibles > 0 || !reached_exit) {
        // Erro: caminho inválido
        // Insira sua função de erro aqui
        printf("Erro: Caminho inválido!\n");
        return;
    }

    // Caminho válido
    printf("Caminho válido encontrado!\n");
}
