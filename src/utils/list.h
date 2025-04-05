/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:18:08 by lgrigore          #+#    #+#             */
/*   Updated: 2025/04/03 14:17:26 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H
# include <stdlib.h>

typedef struct t_node {
    void *data;
    struct t_node *next;
} t_node;

typedef struct {
    t_node *head;
    size_t data_size;
} t_list;

t_list *init_list(size_t data_size);
void insert_front(t_list *list, void *data);
void traverse_list(t_list *list, void (*func)(void *));
void traverse_list_with_param(t_list *list, void (*func)(void *, void *), void *param);
void destroy_list(t_list *list, void (*destroy_data)());

#endif
