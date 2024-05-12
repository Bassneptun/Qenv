#include <armadillo>
#include <complex>
#include <memory>

#include "../include/header/QubitClass.hh"

using std::complex;

valsr Qbit::combine(const vals q1) {
  auto temp = kron(*values, *q1);
  this->values = std::make_unique<cx_vec>(temp);
  return std::make_shared<cx_vec>(temp);
}

valsr Qbit::combine(const Qbit& other) {
  auto temp = kron(*this->values, *other.values);
  this->values = std::make_unique<cx_vec>(temp);
  return std::make_shared<cx_vec>(temp);
}

valsr Qbit::combine(const cx_vec& q1) {
  auto temp = kron(*values, q1);
  this->values = std::make_unique<cx_vec>(temp);
  return std::make_shared<cx_vec>(temp);
}

valsr Qbit::cnot(const Qbit& other) {
  cx_vec temp;
  if (this->values->n_elem != other.values->n_elem)
    throw std::invalid_argument("Qudits must be the same size");

  mat CNOT = Qtils::homo_cnot_operator(this->values->n_elem);
  auto combined = combine(other);
  temp = CNOT * (*combined);
  return std::make_shared<cx_vec>(temp);
}

valsr Qbit::cnot(vals other) {
  cx_vec temp;
  Qbit otherQ(std::move(other));  // move other to Qbit other);
  if (this->values->n_elem != otherQ.values->n_elem)
    throw std::invalid_argument("Qudits must be the same size");

  mat CNOT = Qtils::homo_cnot_operator(this->values->n_elem);
  auto combined = combine(otherQ);
  temp = CNOT * (*combined);
  return std::make_shared<cx_vec>(temp);
}

valsr Qbit::haddamard() const {
  if (this->values->n_elem != 2)
    throw std::invalid_argument("Input must not be Qudit");
  mat h_matrix = {{1 / sqrt(2), 1 / sqrt(2)}, {1 / sqrt(2), -1 / sqrt(2)}};
  cx_vec temp = h_matrix * (*this->values);
  return std::make_shared<cx_vec>(temp);
}

valsr Qbit::pauliX() const {
  if (this->values->n_elem != 2) {
    throw std::invalid_argument("Input must not be Qudit");
  }
  cx_vec temp = {{0, 1}, {1, 0}};
  return std::make_shared<cx_vec>(temp * (*this->values));
}

valsr Qbit::pauliY() const {
  if (this->values->n_elem != 2) {
    throw std::invalid_argument("Input must not be Qudit");
  }
  cx_mat temp = {{complex(0.0, 0.0), complex(0.0, -1.0)},
                 {complex(0.0, 1.0), complex(0.0, 0.0)}};
  return std::make_shared<cx_vec>(temp * (*this->values));
}

valsr Qbit::pauliZ() const {
  if (this->values->n_elem != 2) {
    throw std::invalid_argument("Input must not be Qudit");
  }
  cx_vec temp = {{1, 0}, {0, -1}};
  return std::make_shared<cx_vec>(temp * (*this->values));
}

valsr Qbit::identity() const {
  if (this->values->n_elem != 2) {
    throw std::invalid_argument("Input must not be Qudit");
  }
  cx_vec temp = {{1, 0}, {0, 1}};
  return std::make_shared<cx_vec>(temp * (*this->values));
}

valsr Qbit::rx(double angle) const {
  if (this->values->n_elem != 2) {
    throw std::invalid_argument("Input must not be Qudit");
  }
  cx_mat temp = {{cos(angle / 2), complex(-1.0, sin(angle / 2))},
                 {complex(-1.0, sin(angle / 2)), cos(angle / 2)}};
  return std::make_shared<cx_vec>(temp * (*this->values));
}

valsr Qbit::ry(double angle) const {
  if (this->values->n_elem != 2) {
    throw std::invalid_argument("Input must not be Qudit");
  }
  cx_vec temp = {{cos(angle / 2), -sin(angle / 2)},
                 {sin(angle / 2), cos(angle / 2)}};
  return std::make_shared<cx_vec>(temp * (*this->values));
}

valsr Qbit::rz(double angle) const {
  if (this->values->n_elem != 2) {
    throw std::invalid_argument("Input must not be Qudit");
  }
  cx_mat temp = {{exp(complex(-1.0, angle / 2)), complex(0.0, 0.0)},
                 {complex(0.0, 0.0), exp(complex(1.0, angle / 2))}};
  return std::make_shared<cx_vec>(temp * (*this->values));
}
