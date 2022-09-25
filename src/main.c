#include <stdio.h>
#include <stdlib.h>
#include "math/dot.h"
#include "perf/nanos.h"

#define SIZE 1000
float a[SIZE], b[SIZE], total;

int main(int argc, char **argv) {
  {
    for (int i = 0; i < SIZE; ++i)
      a[i] = b[i] = i;

    NANOS(et_auto, float x = dot(a, b, SIZE));
    NANOS(et_omp, float y = dot_simd(a, b, SIZE));

    printf("[ Auto simd: %ld ns ]  vs  [ Forced simd: %ld ns ] \n", et_auto, et_omp);
    printf("[ Auto simd: %f ]  vs  [ Forced simd: %f ] \n", x, y);
  }

  return EXIT_SUCCESS;
}