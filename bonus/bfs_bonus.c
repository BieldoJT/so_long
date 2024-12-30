#include "so_long_bonus.h"

void bfs_pathfinding(t_game *game, t_enemy *enemy, t_positon target)
{
	t_queue				*queue;
	t_bfs_components	*bfs_components;

	bfs_components = malloc(sizeof(t_bfs_components));
	bfs_components->grafh = init_graph(game);
	bfs_components->prev_pos = init_position(game);
	generate_graph(game,bfs_components);
	queue = init_queue();
	enqueue(&queue, enemy->pos_enemy); // Começar do inimigo
	bfs_components->grafh[enemy->pos_enemy.x][enemy->pos_enemy.y] = 1;
	//bfs
	bfs_looping(game,&queue,target,bfs_components);
	free_queue(queue);
	get_next_move(game,bfs_components,enemy,target);
	free_bfs_components(bfs_components, game->map_game.rows_map);
}
