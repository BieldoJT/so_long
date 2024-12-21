/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-conc <gda-conc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 23:19:13 by gda-conc          #+#    #+#             */
/*   Updated: 2024/12/21 18:41:27 by gda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*join_and_free(char *str_to_free, char *str_to_add)
{
	char *new_str;

	new_str = ft_strjoin(str_to_free, str_to_add);
	free (str_to_free);
	return (new_str);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while(tab[i])
		free(tab[i++]);
	free(tab);
}
