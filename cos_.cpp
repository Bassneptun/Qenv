#include <armadillo>
#include <cmath>

using namespace arma;

int main(int argc, char *argv[]) {
  mat C = {{cos(0.5), -sin(0.5)}, {sin(0.5), cos(0.5)}};
  C.print();
  vec B = {1 / sqrt(2), 1 / sqrt(2)};
  B.print();
  vec E = C * B;
  E.print();
  return 0;
}
