#include "so_long.h"

void move_player(t_game *game, int pos_x, int pos_y)
{}
//FAZER FUNÇÃO PARA ANDAAAARRRRRR

int	input_game(int keysym, t_game *game)
{
	int pos_player_x;
	int pos_player_y;

	pos_player_x = game->map_game.player.y;
	pos_player_y = game->map_game.player.x;
	if (keysym == KEY_W)
		move_player(game,pos_player_x, pos_player_y + 1);
	if (keysym == KEY_S)
		move_player(game,pos_player_x, pos_player_y - 1);
	if (keysym == KEY_D)
		move_player(game,pos_player_x + 1, pos_player_y);
	if (keysym == KEY_A)
		move_player(game,pos_player_x - 1, pos_player_y + 1);


}
