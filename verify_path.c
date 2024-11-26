#include "so_long.h"

char	**copy_map(t_game *game)
{
	char	**copy;
	int	i;
	int	j;

	copy = malloc((game->map_game.rows_map + 1) * sizeof(char *));
	if (!copy)
		error_map("malloc error on copy", game); //n sei se vale a pena fazer isso
	i = 0;
	while (i < game->map_game.rows_map)
	{
		copy[i] = ft_strdup(game->map_game.map[i]);
		if (!copy[i])
		{
			j = 0;
			while(j < i)
				free(copy[j++]);
			free(copy);
			error_map("malloc error on copying map", game); //n sei se vale a pena fazer isso
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}



void	fill_map(char **tab, t_positon size, t_positon cur)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x)// Verifica se ta na borda
		return;
	if (tab[cur.y][cur.x] == '1' || tab[cur.y][cur.x] == 'X') // não faz nada se for 1 ou X
		return;
	tab[cur.y][cur.x] = 'X';// Muda a posição atual
	t_positon next;
	next = cur; next.x -= 1; fill_map(tab, size, next); // Esquerda
	next = cur; next.x += 1; fill_map(tab, size, next); // Direita
	next = cur; next.y -= 1; fill_map(tab, size, next); // Cima
	next = cur; next.y += 1; fill_map(tab, size, next); // Baixo
}

void get_path(char **tab, t_game *game)
{
	t_positon size;
	t_positon begin;

	if (game->map_game.columns_map <= 2 || game->map_game.rows_map <= 2)// Valida o tamanho
		return; //TRATAR ERRO, FAZER FUNÇÃO QUE DE FREE NOS DOIS MAPAS
	size.x = game->map_game.columns_map;
	size.y = game->map_game.rows_map;
	begin.x = game->map_game.player.y;// Valida e pega a posição inicial
	begin.y = game->map_game.player.x;
	if (begin.x < 0 || begin.x >= size.x || begin.y < 0 || begin.y >= size.y)
		return; // Começa no lugar errado
		//TRATAR ERRO, FAZER FUNÇÃO QUE DE FREE NOS DOIS MAPAS
	fill_map(tab, size, begin);//Preenche o mapa
}

