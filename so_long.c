#include "so_long.h"


/*
int	main(int argc, char **argv)
{
	if (argv == 1)
		//fazer função de error para falta de ARQUIVO
		printf("ta errado");
	else if(argc == 2)
		printf("verifica se ta certo");
		//fazer função para verificar se o ARQUIVO ESTÁ CORRETO
	else
		printf("ta super errado");
		//tratar esse erro!!!

}*/
int main(int argc, char **argv)
{
	t_map	map;
	read_file(argv[1], &map);
}
