/*
	Author: @rasmushugosson
	Last modified: 2023-03-30
*/

#include "../include/aerideus_mem.h"

#include <stdlib.h>

#include "../internal/i_ae_structures.h"

static linked_list s_allocations_list;

void i_ae_malloc_debug(const char* n, void** d, size_t s)
{
	*d = malloc(s);

	if (!(*d))
	{
		AE_LOG_CONSOLE_DEBUG_FATAL("Failed to allocate heap memory for variable: %s", n);
	}

	allocation a = { n, *d, s };
	i_ae_linked_list_push_front(&s_allocations_list, a);
}

void i_ae_calloc_debug(const char* n, void** d, size_t c, size_t s)
{
	*d = calloc(c, s);

	if (!(*d))
	{
		AE_LOG_CONSOLE_DEBUG_FATAL("Failed to allocate heap memory for variable: %s", n);
	}

	allocation a = { n, *d, c * s };
	i_ae_linked_list_push_front(&s_allocations_list, a);
}

void i_ae_realloc_debug(const char* n, void** d, size_t s)
{
	void* td = realloc(*d, s);

	if (!td)
	{
		AE_LOG_CONSOLE_DEBUG_FATAL("Failed to reallocate heap memory for variable: %s", n);
	}

	else
	{
		linked_list_node* current = s_allocations_list.head;

		while (current)
		{
			if (current->alloc.data == *d)
			{
				current->alloc.data = td;
				current->alloc.size = s;
				break;
			}

			current = current->next;
		}

		*d = td;
	}
}

void i_ae_free_debug(void* d)
{
	if (d)
	{
		i_ae_linked_list_pop_item(&s_allocations_list, d);

		free(d);
	}

	else
	{
		AE_LOG_CONSOLE_DEBUG_WARNING("Tried to free pointer to adress NULL");
	}
}

void i_ae_log_allocations_console_debug(log_level l)
{
	if (s_allocations_list.length == 0)
	{
		AE_LOG_CONSOLE_DEBUG(l, "No heap memory is currently allocated");
		return;
	}

	AE_LOG_CONSOLE_DEBUG(l, "Allocations: ");

	linked_list_node* current = s_allocations_list.head;

	while (current)
	{
		AE_LOG_CONSOLE_DEBUG(l, "%s | %p", current->alloc.name, current->alloc.data);
		current = current->next;
	}
}

void i_ae_log_allocations_file_debug(log_level l)
{
	if (s_allocations_list.length == 0)
	{
		AE_LOG_FILE_DEBUG(l, "No heap memory is currently allocated");
		return;
	}

	AE_LOG_FILE_DEBUG(l, "Allocations: ");

	linked_list_node* current = s_allocations_list.head;

	while (current)
	{
		AE_LOG_FILE_DEBUG(l, "%s | %p", current->alloc.name, current->alloc.data);
		current = current->next;
	}
}

void i_ae_log_leaks_console_debug()
{
	if (s_allocations_list.length == 0)
	{
		AE_LOG_CONSOLE_NEXT_LINE_DEBUG();
		AE_LOG_CONSOLE_DEBUG_INFO("No memory leaks detected");
		return;
	}

	AE_LOG_CONSOLE_NEXT_LINE_DEBUG();
	AE_LOG_CONSOLE_DEBUG_WARNING("Memory leak detected");
	AE_LOG_CONSOLE_DEBUG_WARNING("Allocations: ");

	linked_list_node* current = s_allocations_list.head;

	while (current)
	{
		AE_LOG_CONSOLE_DEBUG_WARNING("%s | %p | %u bytes", current->alloc.name, current->alloc.data, current->alloc.size);
		current = current->next;
	}
}

void i_ae_log_leaks_file_debug()
{
	if (s_allocations_list.length == 0)
	{
		AE_LOG_FILE_NEXT_LINE_DEBUG();
		AE_LOG_FILE_DEBUG_INFO("No memory leaks detected");
		return;
	}

	AE_LOG_FILE_NEXT_LINE_DEBUG();
	AE_LOG_FILE_DEBUG_WARNING("Memory leak detected");
	AE_LOG_FILE_DEBUG_WARNING("Allocations: ");

	linked_list_node* current = s_allocations_list.head;

	while (current)
	{
		AE_LOG_FILE_DEBUG_WARNING("%s | %p | %u bytes", current->alloc.name, current->alloc.data, current->alloc.size);
		current = current->next;
	}
}
