
#ifndef _STD_TYPES_H_
#define _STD_TYPES_H_

// #include "_stdint.h"

#define STD_HIGH    1u /* physical high state (5V, 3V3) */
#define STD_LOW     0u /* physical low state 0V */

#define STD_ON      1u
#define STD_OFF     0u

#define E_OK        0u
#define E_NOT_OK    1u
#define E_PENDING   2u


#ifndef NULL_PTR
#define NULL_PTR ((void *) 0)
#endif

typedef unsigned char   boolean;

#ifndef TRUE
#define TRUE    1u
#endif

#ifndef FALSE
#define FALSE   0u
#endif


typedef unsigned char   boolean;
typedef signed char     sint8;
typedef unsigned char   uint8;

typedef signed short    sint16;
typedef unsigned short  uint16;

typedef signed long     sint32;
typedef unsigned long   uint32;


/* not using t_ prefix because this is not a user-type, it's a platform type */
typedef uint8     std_return_type;


#endif /* _STD_TYPES_H_ */
