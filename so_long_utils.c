#include "so_long.h"

char *join_and_free(char *str_to_free, char *str_to_add)
{
	char *new_str;

	new_str = ft_strjoin(str_to_free, str_to_add);
	free (str_to_free);
	return (new_str);
}