#include "../include/aerideus_mem.h"

#include "aerideus_log.h"

#include <stdlib.h>

void i_ae_malloc_debug(const char* n, void** d, size_t s)
{
	*d = malloc(s);

	if (!(*d))
	{
		AE_LOG_CONSOLE_DEBUG_FATAL("Failed to allocate heap memory for variable: %s", n);
	}
}

void i_ae_calloc_debug(const char* n, void** d, size_t c, size_t s)
{
	*d = calloc(c, s);

	if (!(*d))
	{
		AE_LOG_CONSOLE_DEBUG_FATAL("Failed to allocate heap memory for variable: %s", n);
	}
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
		*d = td;
	}
}

void i_ae_free_debug(void* d)
{
	if (d)
	{
		free(d);
	}

	else
	{
		AE_LOG_CONSOLE_DEBUG_WARNING("Tried to free pointer to adress NULL");
	}
}
