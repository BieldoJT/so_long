#include "so_long_bonus.h"

void bfs_pathfinding(t_game *game, t_enemy *enemy, t_positon target)
{
	char **map = game->map_game.map;
	int rows = game->map_game.rows_map;
	int cols = game->map_game.columns_map;

    int visited[rows][cols];
    t_positon prev[rows][cols]; // Para rastrear o caminho
    t_queue *queue = init_queue();
    t_positon directions[] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

    // Inicializar arrays de visitados e de predecessores
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            visited[i][j] = 0;
            prev[i][j] = (t_positon) { -1, -1 };
        }
    }

    // Começar do inimigo
    enqueue(&queue, enemy->pos_enemy);
    visited[enemy->pos_enemy.x][enemy->pos_enemy.y] = 1;

    // BFS
    while (!is_empty(queue)) {
        t_positon current = dequeue(&queue);

        // Parar se encontrar o jogador
        if (current.x == target.x && current.y == target.y)
            break;

        // Explorar vizinhos
        for (int d = 0; d < 4; d++) {
            t_positon neighbor = { current.x + directions[d].x, current.y + directions[d].y };

            if (neighbor.x >= 0 && neighbor.x < rows &&
                neighbor.y >= 0 && neighbor.y < cols &&
                !visited[neighbor.x][neighbor.y] &&
                map[neighbor.x][neighbor.y] != '1' &&
				map[neighbor.x][neighbor.y] != 'C' &&
				map[neighbor.x][neighbor.y] != 'E' &&
				map[neighbor.x][neighbor.y] != 'G') { // Ignorar paredes
                enqueue(&queue, neighbor);
                visited[neighbor.x][neighbor.y] = 1;
                prev[neighbor.x][neighbor.y] = current;
            }
        }
    }

    free_queue(queue);

    // Encontrar o próximo movimento
    t_positon next_move = enemy->pos_enemy;
    t_positon step = target;

    while (prev[step.x][step.y].x != -1 && prev[step.x][step.y].y != -1) {
        next_move = step;
        step = prev[step.x][step.y];
    }

    // Atualizar posição do inimigo
    if (map[enemy->pos_enemy.x][enemy->pos_enemy.y] == 'G')
        map[enemy->pos_enemy.x][enemy->pos_enemy.y] = '0'; // Limpar a posição antiga

    enemy->pos_enemy = next_move;
    map[next_move.x][next_move.y] = 'G'; // Atualizar o mapa
}
