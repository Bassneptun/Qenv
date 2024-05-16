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
};

#endif
