#include "../include/header/qtils.hh"

#include <iostream>
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

std::vector<std::string> Qtils::getInput(std::string path) {
  std::ifstream file(path);
  std::string line;
  std::vector<std::string> result;
  while (std::getline(file, line)) {
    result.push_back(line);
  }
  return result;
}

// TEMPORARY
cx_vec Qtils::partial_trace(const cx_mat& M, std::vector<int> indices) {
  cx_vec result = zeros<cx_vec>(M.n_cols);
  for (int i = 0; i < indices.size(); ++i) {
    result = result + M.col(indices[i]);
  }
  return result;
}

cx_mat Qtils::homo_pauliX_operator(int d) {
  arma::cx_mat X_d = arma::zeros<arma::cx_mat>(d, d);
  for (int i = 0; i < d; ++i) {
    X_d(i, (i + 1) % d) = 1;
  }
  return X_d;
}

cx_mat Qtils::homo_pauliZ_operator(int d) {
  using namespace std::complex_literals;
  arma::cx_mat Z_d = arma::zeros<arma::cx_mat>(d, d);
  std::complex<double> omega = std::exp(2.0i * M_PI / std::complex<double>(d));
  for (int i = 0; i < d; ++i) {
    Z_d(i, i) = std::pow(omega, i);
  }
  return Z_d;
}

std::vector<std::string> Qtils::filter(std::vector<std::string>& in) {
  for (int i = in.size() - 1; i > 0; i--) {
    for (int j = in[i].size() - 1; j > 0; j--) {
      if (in[i][j] == ' ' || in[i][j] == '\n') {
        in[i].erase(j);
      }
    }
  }
  for (int i = in.size() - 1; i > 0; i--) {
    if (in[i] == "") in.erase(in.begin() + i);
  }
  return in;
}

void Qtils::print_vec(std::vector<std::string> vec) {
  for (auto w : vec) {
    std::cout << w << "\n";
  }
}
