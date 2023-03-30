#include "aerideus_mem.h"

int main(void)
{
	int* a;

	AE_MALLOC(a, sizeof(int));

	*a = 5;

	AE_LOG_CONSOLE_INFO("a = %d", *a);

	AE_REALLOC(a, sizeof(int) * 3);

	a[1] = 7;
	a[2] = 9;

	AE_LOG_CONSOLE_INFO("a[0] = %d, a[1] = %d, a[2] = %d", a[0], a[1], a[2]);

	AE_FREE(a);

	i_ae_log_leaks_console_debug();

	return 0;
}