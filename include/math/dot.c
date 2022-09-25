#include "dot.h"

float dot(float *a, float *b, int size) {
  float total = 0;
  for (int i = 0; i < size; ++i) {
    total += a[i] * b[i];
  }
  return total;
}

float dot_simd(float *a, float *b, int size) {
	float total = 0;
	#pragma omp parallel reduction(+ : total)
	{
		#pragma omp simd
	  for (int i = 0; i < size; ++i) {
	    total += a[i] * b[i];
	  }
	}
  return total;
}