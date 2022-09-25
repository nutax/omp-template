#ifndef __DOT_H
#define __DOT_H

#include <omp.h>

float dot(float *a, float *b, int size);
float dot_simd(float *a, float *b, int size);

#endif