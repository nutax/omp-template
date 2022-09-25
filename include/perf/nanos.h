#ifndef __NANOS_H
#define __NANOS_H
#include <time.h>

#define NANOS(_res, _fun) long _res = get_nanos(); _fun; _res = get_nanos() - _res

long get_nanos(void);

#endif


