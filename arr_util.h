#include<stdlib.h>
#include<stdarg.h>

typedef void* array;

typedef struct
{
	size_t size;
	array data[]; 
} array_header;

array_header* array_get_header(array* arr) { return &((array_header*)arr)[-1]; }
size_t len(array arr) { return array_get_header(arr)->size; }

#define DEFINE_ARRAY_HEADER_TYPE(type_name, type, va_type) \
    typedef struct \
    { \
        size_t size; \
        type data[]; \
    } array_header_##type_name; \
    \
    type *array_create_##type_name(size_t count, ...) { \
        size_t total_size = sizeof(array_header_##type_name) + count * sizeof(type); \
        array_header_##type_name *h = (array_header_##type_name *)malloc(total_size); \
        if (!h) return NULL; \
        \
        h->size = count; \
        \
        va_list args; \
        va_start(args, count); \
        for (size_t i = 0; i < count; i++) { \
            h->data[i] = (type)va_arg(args, va_type); \
        } \
        va_end(args); \
        \
        return h->data; \
    } \
	
DEFINE_ARRAY_HEADER_TYPE(_Bool, _Bool, int)
DEFINE_ARRAY_HEADER_TYPE(unsigned_char, unsigned char, int)
DEFINE_ARRAY_HEADER_TYPE(char, char, int)
DEFINE_ARRAY_HEADER_TYPE(signed_char, signed char, int)
DEFINE_ARRAY_HEADER_TYPE(short_int, short int, int)
DEFINE_ARRAY_HEADER_TYPE(unsigned_short_int, unsigned short int, int)
DEFINE_ARRAY_HEADER_TYPE(int, int, int)
DEFINE_ARRAY_HEADER_TYPE(unsigned_int, unsigned int, unsigned int)
DEFINE_ARRAY_HEADER_TYPE(long_int, long int, long int)
DEFINE_ARRAY_HEADER_TYPE(unsigned_long_int, unsigned long int, unsigned long int)
DEFINE_ARRAY_HEADER_TYPE(long_long_int, long long int, long long int)
DEFINE_ARRAY_HEADER_TYPE(unsigned_long_long_int, unsigned long long int, unsigned long long int)
DEFINE_ARRAY_HEADER_TYPE(float, float, double)
DEFINE_ARRAY_HEADER_TYPE(double, double, double)
DEFINE_ARRAY_HEADER_TYPE(long_double, long double, long double)
DEFINE_ARRAY_HEADER_TYPE(pointer_to_char, char *, char *)
DEFINE_ARRAY_HEADER_TYPE(pointer_to_void, void *, void *)
DEFINE_ARRAY_HEADER_TYPE(pointer_to_int, int *, int *)

/* array_create__Bool */
/* array_create_unsigned_char */
/* array_create_char */
/* array_create_signed_char */
/* array_create_short_int */
/* array_create_unsigned_short_int */
/* array_create_int */
/* array_create_unsigned_int */
/* array_create_long_int */
/* array_create_unsigned_long_int */
/* array_create_long_long_int */
/* array_create_unsigned_long_long_int */
/* array_create_float */
/* array_create_double */
/* array_create_long_double */
/* array_create_pointer_to_char */
/* array_create_pointer_to_void */
/* array_create_pointer_to_int */

