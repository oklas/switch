
#ifdef __cplusplus
#define DECL extern "C"
#else
#define DECL
#endif

DECL const char*
check( const char* top, const char* sub, const char* val );
