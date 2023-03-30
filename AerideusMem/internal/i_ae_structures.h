#include <stdint.h>

typedef struct {
	const char* name;
	void* data;
	size_t size;
} allocation;

typedef struct linked_list_node {
	allocation alloc;
	struct linked_list_node* next;
} linked_list_node;

typedef struct {
	linked_list_node* head;
	uint32_t length;
} linked_list;

void i_ae_linked_list_push_front(linked_list* list, allocation alloc);

void i_ae_linked_list_pop_item(linked_list* list, void* data);

void i_ae_linked_list_clear(linked_list* list);
