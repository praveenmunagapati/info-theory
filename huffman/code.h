
#ifndef _ECCODE_H_
#define _ECCODE_H_

#include <stddef.h>

/* standard bit vector macros */
#define BIT_TEST(c,i)  (c[(i)/8] &   (1 << ((i) % 8)))
#define BIT_SET(c,i)   (c[(i)/8] |=  (1 << ((i) % 8)))
#define BIT_CLEAR(c,i) (c[(i)/8] &= ~(1 << ((i) % 8)))

/* while the first four are mutually exclusive we use
 * bit flags to support OR'ing additional options */
#define MODE_ENCODE     (1U << 0)
#define MODE_DECODE     (1U << 1)

int huf_recode(int mode, unsigned char *ib, size_t ilen, unsigned char *ob);
size_t huf_compute_olen(int mode, size_t ilen, size_t *ibits, size_t *obits);

#endif /* _ECCODE_H_ */
