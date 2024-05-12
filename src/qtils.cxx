#include "../include/header/qtils.hh"

mat Q::homo_cnot_operator(int n) {
  mat CNOT = zeros<mat>(n * n, n * n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int new_j = (j + i) % n;
      int row_index = i * n + j;
      int col_index = i * n + new_j;
      CNOT(row_index, col_index) = 1;
    }
  }
  return CNOT;
}
