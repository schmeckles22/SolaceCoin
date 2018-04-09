
#ifndef randsolytes_H
#define randsolytes_H

#include <sys/types.h>

#include <stddef.h>
#include <stdint.h>

#include "export.h"

#ifdef __cplusplus
# if __GNUC__
#  pragma GCC diagnostic ignored "-Wlong-long"
# endif
extern "C" {
#endif

typedef struct randsolytes_implementation {
    const char *(*implementation_name)(void); /* required */
    uint32_t    (*random)(void);              /* required */
    void        (*stir)(void);                /* optional */
    uint32_t    (*uniform)(const uint32_t upper_bound); /* optional, a default implementation will be used if NULL */
    void        (*buf)(void * const buf, const size_t size); /* required */
    int         (*close)(void);               /* optional */
} randsolytes_implementation;

SODIUM_EXPORT
void randsolytes_buf(void * const buf, const size_t size);

SODIUM_EXPORT
uint32_t randsolytes_random(void);

SODIUM_EXPORT
uint32_t randsolytes_uniform(const uint32_t upper_bound);

SODIUM_EXPORT
void randsolytes_stir(void);

SODIUM_EXPORT
int randsolytes_close(void);

SODIUM_EXPORT
int randsolytes_set_implementation(randsolytes_implementation *impl);

SODIUM_EXPORT
const char *randsolytes_implementation_name(void);

/* -- NaCl compatibility interface -- */

SODIUM_EXPORT
void randsolytes(unsigned char * const buf, const unsigned long long buf_len);

#ifdef __cplusplus
}
#endif

#endif
