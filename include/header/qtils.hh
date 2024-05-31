#ifndef QUTILS_HH
#define QUTILS_HH

#include <armadillo>
#include <string>
#include <vector>

using namespace arma;

class Qtils {
 public:
  static mat homo_cnot_operator(const int);
  static std::vector<std::string> split(std::string, std::string);
  static std::vector<std::string> getInput(std::string path);
  static cx_vec partial_trace(const cx_mat&, std::vector<int>);
  static cx_mat homo_pauliX_operator(int);
  // static cx_mat homo_pauliY_operator(int);
  static cx_mat homo_pauliZ_operator(int);
  static std::vector<std::string> filter(std::vector<std::string>);
};

#endif
