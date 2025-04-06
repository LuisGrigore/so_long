/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:17:59 by lgrigore          #+#    #+#             */
/*   Updated: 2025/04/06 17:21:53 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./list.h"

t_list	*init_list(size_t data_size)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->head = (NULL);
	list->data_size = data_size;
	return (list);
}

void	insert_front(t_list *list, void *data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->data = data;
	new_node->next = list->head;
	list->head = new_node;
}

void	traverse_list(t_list *list, void (*func)(void *))
{
	t_node	*current;

	current = list->head;
	while (current)
	{
		func(current->data);
		current = current->next;
	}
}

void	traverse_list_with_param(t_list *list,
		void (*func)(void *, void *), void *param)
{
	t_node	*current;

	current = list->head;
	while (current)
	{
		func(current->data, param);
		current = current->next;
	}
}

void	destroy_list(t_list *list, void (*destroy_data)())
{
	t_node	*current;
	t_node	*next_node;

	current = list->head;
	if (!list)
		return ;
	while (current)
	{
		next_node = current->next;
		destroy_data(current->data);
		free(current);
		current = next_node;
	}
	free(list);
}
