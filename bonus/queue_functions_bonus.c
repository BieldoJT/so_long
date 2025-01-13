/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_functions_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-conc <gda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:58:31 by gda-conc          #+#    #+#             */
/*   Updated: 2025/01/13 16:11:30 by gda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_queue	*init_queue(void)
{
	return (NULL);
}

int	is_empty(t_queue *queue)
{
	if (queue == NULL)
		return (1);
	else
		return (0);
}

void	enqueue(t_queue **queue, t_pos pos)
{
	t_queue	*new_node;
	t_queue	*temp;

	temp = *queue;
	new_node = malloc(sizeof(t_queue));
	temp = *queue;
	if (!new_node)
		return ;
	new_node->pos = pos;
	new_node->next = NULL;
	if (is_empty(*queue))
	{
		*queue = new_node;
	}
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
}

t_pos	dequeue(t_queue **queue)
{
	t_queue	*temp;
	t_pos	pos;

	temp = *queue;
	pos.x = -1;
	pos.y = -1;
	if (is_empty(*queue))
		return (pos);
	pos = temp->pos;
	*queue = temp->next;
	free(temp);
	return (pos);
}

void	free_queue(t_queue *queue)
{
	while (queue)
		dequeue(&queue);
}
