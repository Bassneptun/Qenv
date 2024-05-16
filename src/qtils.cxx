#include "../include/header/qtils.hh"

#include <string>
#include <vector>

mat Qtils::homo_cnot_operator(int n) {
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

std::vector<std::string> Qtils::split(std::string s, std::string delimiter) {
  size_t pos = 0;
  std::string token;
  std::vector<std::string> result;
  while ((pos = s.find(delimiter)) != std::string::npos) {
    token = s.substr(0, pos);
    result.push_back(token);
    s.erase(0, pos + delimiter.length());
  }
  result.push_back(s);
  return result;
}
