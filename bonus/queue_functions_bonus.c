/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-conc <gda-conc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:58:31 by gda-conc          #+#    #+#             */
/*   Updated: 2024/12/22 17:23:14 by gda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// Inicializar a fila
t_queue	*init_queue()
{
	return NULL;
}

// Verificar se a fila está vazia
int	is_empty(t_queue *queue)
{
	return (queue == NULL);
}

// Adicionar à fila
void	enqueue(t_queue **queue, t_positon pos)
{
	t_queue *new_node;
	t_queue *temp = *queue;

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
	else {
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
}

// Remover da fila
t_positon	dequeue(t_queue **queue)
{
	t_queue *temp;
	t_positon pos;

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

// Liberar a fila
void free_queue(t_queue *queue)
{
	while (queue)
		dequeue(&queue);
}
