
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
