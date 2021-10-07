#include "dot.hpp"

double dot(int N, double *a, double *b) {
  double sum = 0.0;
  for (int i = 0; i < N; ++i) {
    sum += a[i] * b[i];
  }
  return sum;
}
