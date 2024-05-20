#include "../include/header/QuditClass.hh"

#include <armadillo>
#include <cmath>
#include <complex>
#include <memory>

#include "../include/header/qtils.hh"

using namespace std::complex_literals;

Qudit Qudit::combine(Qudit& other2) noexcept {
  return Qudit(kron(*this->values, other2.get()));
}

Qudit::valsr_ Qudit::cnot(Qudit& other) noexcept {
  cx_vec temp;

  mat CNOT = Qtils::homo_cnot_operator(this->values->n_elem);
  auto combined = combine(other);
  temp = CNOT * combined.get();
  return std::make_shared<Qudit>(Qudit(temp));
}

Qudit::valsr_ Qudit::haddamard() const {
  mat had = {{1., 1.}, {1., -1.}};
  if (this->values->n_elem == 2) {
    return std::make_shared<Qudit>(had * (*this->values));
  }
  auto qb = log(d) / log(2);
  mat temp = kron(had, had);
  for (int i = 2; i < qb; ++i) {
    temp = kron(temp, had);
  }
  return std::make_shared<Qudit>(temp * (*this->values));
}

Qudit::valsr_ Qudit::pauliX() const noexcept {
  arma::cx_mat X_d = arma::zeros<arma::cx_mat>(d, d);
  for (int i = 0; i < d; ++i) {
    X_d(i, (i + 1) % d) = 1;
  }
  return std::make_shared<Qudit>(Qudit(X_d * (*this->values)));
}

Qudit::valsr_ Qudit::pauliZ() const noexcept {
  using namespace std::complex_literals;
  arma::cx_mat Z_d = arma::zeros<arma::cx_mat>(d, d);
  std::complex<double> omega = std::exp(2.0i * M_PI / std::complex<double>(d));
  for (int i = 0; i < d; ++i) {
    Z_d(i, i) = std::pow(omega, i);
  }
  return std::make_shared<Qudit>(Qudit(Z_d * (*this->values)));
}

Qudit::valsr_ Qudit::identity() const noexcept {
  return std::make_shared<Qudit>(*this->values);
}

Qudit::valsr_ Qudit::rx(double angle) const noexcept {
  using namespace std::complex_literals;
  arma::cx_mat X_d = this->pauliX()->get();
  auto temp = arma::expmat(-1i * angle * X_d / 2);
  return std::make_shared<Qudit>(Qudit(temp * (*this->values)));
}

Qudit::valsr_ Qudit::ry(double angle) const noexcept {
  using namespace std::complex_literals;
  arma::cx_mat Y_d = this->pauliY()->get();
  auto temp = arma::expmat(-1i * angle * Y_d / 2);
  return std::make_shared<Qudit>(Qudit(temp * (*this->values)));
}

Qudit::valsr_ Qudit::rz(double angle) const noexcept {
  using namespace std::complex_literals;
  arma::cx_mat R_z = arma::zeros<arma::cx_mat>(d, d);
  for (double k = 0; k < d; ++k) {
    R_z(k, k) = std::exp(1i * angle * k);
  }
  return std::make_shared<Qudit>(Qudit(R_z * (*this->values)));
}

Qudit::valsr_ Qudit::S() const noexcept {
  arma::cx_mat S = arma::zeros<arma::cx_mat>(d, d);
  for (double k = 0; k < d; ++k) {
    S(k, k) = std::exp(1i * M_PI / 2.0 * k);
  }
  return std::make_shared<Qudit>(Qudit(S * (*this->values)));
}

Qudit::valsr_ Qudit::T() const noexcept {
  using namespace std::complex_literals;
  arma::cx_mat T = arma::zeros<arma::cx_mat>(d, d);
  for (double k = 0; k < d; ++k) {
    T(k, k) = std::exp(1i * M_PI / 4. * k);
  }
  return std::make_shared<Qudit>(Qudit(T * (*this->values)));
}

Qudit::valsr_ Qudit::S_dag() const noexcept {
  using namespace std::complex_literals;
  arma::cx_mat S = arma::zeros<arma::cx_mat>(d, d);
  for (double k = 0; k < d; ++k) {
    S(k, k) = std::exp(-1i * M_PI / 2.0 * k);
  }
  return std::make_shared<Qudit>(Qudit(S * (*this->values)));
}

Qudit::valsr_ Qudit::T_dag() const noexcept {
  using namespace std::complex_literals;
  arma::cx_mat T = arma::zeros<arma::cx_mat>(d, d);
  for (double k = 0; k < d; ++k) {
    T(k, k) = std::exp(-1i * M_PI / 4. * k);
  }
  return std::make_shared<Qudit>(Qudit(T * (*this->values)));
}

Qudit::valsr_ Qudit::swap(Qudit& other) noexcept {
  arma::cx_mat Swap = arma::zeros<arma::cx_mat>(d * d, d * d);
  for (int i = 0; i < d; ++i) {
    for (int j = 0; j < d; ++j) {
      Swap(i * d + j, j * d + i) = 1;
    }
  }
  return std::make_shared<Qudit>(Qudit(Swap * (*this->values) * other.get()));
}

Qudit::valsr_ Qudit::cr(double angle) const noexcept {
  using namespace std::complex_literals;
  arma::cx_mat CR = arma::zeros<arma::cx_mat>(d * d, d * d);
  for (int i = 0; i < d; ++i) {
    for (int j = 0; j < d; ++j) {
      double angle = (i * angle);
      std::complex<double> phase = std::exp(1i * angle);
      CR(i * d + j, i * d + j) = phase;
    }
  }
  cx_double phi = exp(cx_double(0, angle));
  return std::make_shared<Qudit>(Qudit(CR * (*this->values)));
}

Qudit::valsr_ Qudit::crk(double k) const noexcept {
  using namespace std::complex_literals;
  arma::cx_mat CRk = arma::zeros<arma::cx_mat>(d * d, d * d);
  double angle = k * M_PI;

  for (int i = 0; i < d; ++i) {
    for (int j = 0; j < d; ++j) {
      std::complex<double> phase = std::exp(1i * angle);
      CRk(i * d + j, i * d + j) = phase;
    }
  }
  return std::make_shared<Qudit>(Qudit(CRk * (*this->values)));
}

Qudit::valsr_ Qudit::toffoli(Qudit& other, Qudit& other2) {
  using namespace std::complex_literals;
  int d3 = d * d * d;
  arma::cx_mat Toffoli = arma::eye<arma::cx_mat>(d3, d3);
  for (int i = 0; i < d; ++i) {
    for (int j = 0; j < d; ++j) {
      for (int k = 0; k < d; ++k) {
        int idx = (i * d + j) * d + k;
        if (i == d - 1 && j == d - 1) {
          Toffoli(idx, idx) = 0;
          Toffoli(idx, (idx + 1) % d3) = 1;
        }
      }
    }
  }
  return std::make_shared<Qudit>(
      Qudit(Toffoli * (*this->values) * other.get() * other2.get()));
}

// DOESN'T WORK. ONLY HERE TO MAKE THE COMPILER SHUT UP
Qudit::valsr_ Qudit::pauliY() const noexcept {
  using namespace std::complex_literals;
  arma::cx_mat Y_d = arma::zeros<arma::cx_mat>(d, d);
  for (int i = 0; i < d; ++i) {
    Y_d(i, (i + 1) % d) = 1i;
  }
  return std::make_shared<Qudit>(Qudit(Y_d * (*this->values)));
}

// THIS AS WELL
Qudit::valsr_ Qudit::cy(Qudit& other) noexcept {
  return std::make_shared<Qudit>(Qudit((*this->values) * other.get()));
}

int Qudit::measure() const {
  int dim = this->values->n_elem;
  std::vector<double> probabilities(dim);

  for (int i = 0; i < dim; ++i) {
    probabilities[i] = std::norm(this->values->at(i));
  }

  double sumProbabilities =
      std::accumulate(probabilities.begin(), probabilities.end(), 0.0);
  for (int i = 0; i < dim; ++i) {
    probabilities[i] /= sumProbabilities;
  }

  double r = randn();
  double cumulativeProbability = 0.0;
  for (int i = 0; i < dim; ++i) {
    cumulativeProbability += probabilities[i];
    if (r < cumulativeProbability) {
      return i;
    }
  }

  return -1;
}
