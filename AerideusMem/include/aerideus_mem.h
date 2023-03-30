#include "aerideus_log.h"

#include <stdlib.h>

/// <summary>
/// Internal function that should only be called through macro. (AE_MALLOC)
/// </summary>
/// <param name="n">should not be specified</param>
/// <param name="d">should not be specified</param>
/// <param name="s">should not be specified</param>
void i_ae_malloc_debug(const char* n, void** d, size_t s);

/// <summary>
/// Internal function that should only be called through macro. (AE_CALLOC)
/// </summary>
/// <param name="n">should not be specified</param>
/// <param name="d">should not be specified</param>
/// <param name="c">should not be specified</param>
/// <param name="s">should not be specified</param>
void i_ae_calloc_debug(const char* n, void** d, size_t c, size_t s);

/// <summary>
/// Internal function that should only be called through macro. (AE_REALLOC)
/// </summary>
/// <param name="n">should not be specified</param>
/// <param name="d">should not be specified</param>
/// <param name="s">should not be specified</param>
void i_ae_realloc_debug(const char* n, void** d, size_t s);

/// <summary>
/// Internal function that should only be called through macro. (AE_FREE)
/// </summary>
/// <param name="d">should not be specified</param>
void i_ae_free_debug(void* d);

#ifdef AE_DEBUG

/// <summary>
/// Use instead of standard malloc to enable memory tracking.
/// </summary>
/// <param name="d">is the pointer to allocate memory for</param>
/// <param name="s">is the size of the memory to be allocated</param>
#define AE_MALLOC(d, s) i_ae_malloc_debug(#d, &(d), s)

/// <summary>
/// Use instead of standard calloc to enable memory tracking.
/// </summary>
/// <param name="d">is the pointer to allocate memory for</param>
/// <param name="c">is the number of items to be allocated</param>
/// <param name="s">is the size of the items to be allocated</param>
#define AE_CALLOC(d, c, s) i_ae_calloc_debug(#d, &(d), c, s)

/// <summary>
/// Use instead of standard realloc to enable memory tracking.
/// </summary>
/// <param name="d">is the pointer to allocate memory for</param>
/// <param name="s">is the new size of the memory to be allocated</param>
#define AE_REALLOC(d, s) i_ae_realloc_debug(#d, &(d), s)

/// <summary>
/// Use instead of standard free to enable memory tracking.
/// </summary>
/// <param name="d">is the pointer to the allocated memory</param>
#define AE_FREE(d) i_ae_free_debug(d)

#endif // AE_DEBUG

#ifdef AE_RELEASE

/// <summary>
/// Use instead of standard malloc to enable memory tracking. Replaced by standard malloc since the build type is Release.
/// </summary>
/// <param name="d">is the pointer to allocate memory for</param>
/// <param name="s">is the size of the memory to be allocated</param>
#define AE_MALLOC(d, s) d = malloc(s)

/// <summary>
/// Use instead of standard calloc to enable memory tracking. Replaced by standard calloc since the build type is Release.
/// </summary>
/// <param name="d">is the pointer to allocate memory for</param>
/// <param name="c">is the number of items to be allocated</param>
/// <param name="s">is the size of the items to be allocated</param>
#define AE_CALLOC(d, c, s) d = calloc(c, s)

/// <summary>
/// Use instead of standard realloc to enable memory tracking. Replaced by standard realloc since the build type is Release.
/// </summary>
/// <param name="d">is the pointer to allocate memory for</param>
/// <param name="s">is the new size of the memory to be allocated</param>
#define AE_REALLOC(d, s) d = realloc(d, s)

/// <summary>
/// Use instead of standard free to enable memory tracking. Replaced by standard free since the build type is Release.
/// </summary>
/// <param name="d">is the pointer to the allocated memory</param>
#define AE_FREE(d) free(d)

#endif // AE_RELEASE

#ifdef AE_DIST

/// <summary>
/// Use instead of standard malloc to enable memory tracking. Replaced by standard malloc since the build type is Dist.
/// </summary>
/// <param name="d">is the pointer to allocate memory for</param>
/// <param name="s">is the size of the memory to be allocated</param>
#define AE_MALLOC(d, s) d = malloc(s)

/// <summary>
/// Use instead of standard calloc to enable memory tracking. Replaced by standard calloc since the build type is Dist.
/// </summary>
/// <param name="d">is the pointer to allocate memory for</param>
/// <param name="c">is the number of items to be allocated</param>
/// <param name="s">is the size of the items to be allocated</param>
#define AE_CALLOC(d, c, s) d = calloc(c, s)

/// <summary>
/// Use instead of standard realloc to enable memory tracking. Replaced by standard realloc since the build type is Dist.
/// </summary>
/// <param name="d">is the pointer to allocate memory for</param>
/// <param name="s">is the new size of the memory to be allocated</param>
#define AE_REALLOC(d, s) d = realloc(d, s)

/// <summary>
/// Use instead of standard free to enable memory tracking. Replaced by standard free since the build type is Dist.
/// </summary>
/// <param name="d">is the pointer to the allocated memory</param>
#define AE_FREE(d) free(d)

#endif // AE_DIST

/// <summary>
/// Internal function that should only be called through macro. (AE_LOG_ALLOCATIONS_CONSOLE)
/// </summary>
/// <param name="l">should not be specified</param>
void i_ae_log_allocations_console_debug(log_level l);
/// <summary>
/// Internal function that should only be called through macro. (AE_LOG_ALLOCATIONS_FILE)
/// </summary>
/// <param name="l">should not be specified</param>
void i_ae_log_allocations_file_debug(log_level l);

/// <summary>
/// Internal function that should only be called through macro. (AE_LOG_LEAKS_CONSOLE)
/// </summary>
void i_ae_log_leaks_console_debug();
/// <summary>
/// Internal function that should only be called through macro. (AE_LOG_LEAKS_FILE)
/// </summary>
void i_ae_log_leaks_file_debug();
