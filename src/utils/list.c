#include "./list.h"

t_list *init_list(size_t data_size) {
    t_list *list = (t_list *)malloc(sizeof(t_list));
    if (!list) return NULL;

    list->head = NULL;
    list->data_size = data_size;
    return list;
}

void insert_front(t_list *list, void *data) {
    t_node *new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node) return;

    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
}


void traverse_list(t_list *list, void (*func)(void *)) {
    t_node *current = list->head;
    while (current) {
        func(current->data);
        current = current->next;
    }
}

void traverse_list_with_param(t_list *list, void (*func)(void *, void *), void *param) {
    t_node *current = list->head;
    while (current) {
        func(current->data, param);
        current = current->next;
    }
}


void destroy_list(t_list *list, void (*destroy_data)())
{
	if (!list)
		return;
    t_node *current = list->head;
    t_node *next_node;

    while (current) {
        next_node = current->next;
        destroy_data(current->data);
        free(current);
        current = next_node;
    }
    free(list);
}
