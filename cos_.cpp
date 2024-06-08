#include <armadillo>
#include <cmath>
#include <complex>

using namespace arma;
using namespace std::complex_literals;

int main(int argc, char *argv[]) {
  cx_mat C = {{cos(0.5), -1i * sin(0.5)}, {-1i * sin(0.5), cos(0.5)}};
  C.print();
  vec B = {1 / sqrt(2), 1 / sqrt(2)};
  B.print();
  cx_mat E = C * B;
  E.print();
  return 0;
}
