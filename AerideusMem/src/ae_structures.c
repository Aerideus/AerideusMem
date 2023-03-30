#include "../internal/i_ae_structures.h"

#include <stdlib.h>
#include <memory.h>

#include "aerideus_log.h"

void i_ae_linked_list_push_front(linked_list* list, allocation alloc)
{
	linked_list_node* prev_head = list->head;

	list->head = malloc(sizeof(linked_list_node));

	if (!list->head)
	{
		AE_LOG_CONSOLE_ERROR("Failed to allocate memory for linked_list_node. This should never happen and means that no memory tracking is performed.");
		return;
	}

	list->head->alloc.name = alloc.name;
	list->head->alloc.data = alloc.data;
	list->head->alloc.size = alloc.size;
	list->head->next = prev_head;

	list->length++;
}

void i_ae_linked_list_pop_item(linked_list* list, void* data)
{
	if (list->length == 0)
	{
		return;
	}

	linked_list_node* current = list->head;

	if (current->alloc.data == data)
	{
		linked_list_node* next = current->next;

		free(current);

		list->head = next;

		list->length--;
		return;
	}

	linked_list_node* prev = current;
	current = current->next;

	while (current)
	{
		linked_list_node* next = current->next;

		if (current->alloc.data == data)
		{
			prev->next = next;

			free(current);

			list->length--;
			return;
		}

		prev = current;
		current = next;
	}
}

void i_ae_linked_list_clear(linked_list* list)
{
	if (list->length == 0)
	{
		return;
	}

	linked_list_node* current = list->head;

	while (current)
	{
		linked_list_node* next = current->next;

		free(current);

		current = next;
	}

	list->length = 0;
}
