#ifndef QUTILS_HH
#define QUTILS_HH

#include <armadillo>

using namespace arma;

class Qtils {
 public:
  static mat homo_cnot_operator(const int);
};

#endif
