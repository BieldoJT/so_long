#include "so_long.h"

void move_player(t_game *game, int pos_x, int pos_y)
{
	int	last_x;
	int last_y;

	if (game->map_game.map[pos_x][pos_y] == '1')
		return ;
	if (game->map_game.map[pos_x][pos_y] == 'E')
	{
		if (!game->map_game.collectible)
		{
			//FAZER FUNÇÃO PRA FECHAR O JOGO E DIZER QUE VENCEU
		}
		else
			return ;
	}
	last_x = game->map_game.player.x;
	last_y = game->map_game.player.y;
	game->map_game.map[last_x][last_y] = '0';
	if (game->map_game.map[pos_x][pos_y] == 'C')
		game->map_game.collectible--;
	game->map_game.map[pos_x][pos_y] = 'P';
	game->map_game.player.x = pos_x;
	game->map_game.player.y = pos_y;
	game->movements++;
}

int	input_game(int keysym, t_game *game)
{
	int pos_player_x;
	int pos_player_y;

	pos_player_y = game->map_game.player.y;
	pos_player_x = game->map_game.player.x;
	if (keysym == ESC)
		destroy_everything(game); 

	if (keysym == KEY_W)
		move_player(game,pos_player_x - 1, pos_player_y);
	if (keysym == KEY_S)
		move_player(game,pos_player_x + 1, pos_player_y);
	if (keysym == KEY_D)
		move_player(game,pos_player_x, pos_player_y + 1);
	if (keysym == KEY_A)
		move_player(game,pos_player_x, pos_player_y - 1);
	render(game);
	return 0;

}
