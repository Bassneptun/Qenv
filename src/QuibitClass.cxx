#include <armadillo>
#include <complex>
#include <memory>

#include "../include/header/QubitClass.hh"

using std::complex;

Qbit::valsr Qbit::combine(Qbit& q1) {
  auto temp = kron(*this->values, q1.get());
  return std::make_shared<Qbit>(Qbit(temp));
}

Qbit::valsr Qbit::combine(const vals q1) {
  auto temp = kron(*values, *q1);
  return std::make_shared<Qbit>(Qbit(temp));
}

Qbit::valsr Qbit::combine(const cx_vec& q1) {
  auto temp = kron(*values, q1);
  return std::make_shared<Qbit>(Qbit(temp));
}

Qbit::valsr Qbit::cnot(Qbit& other) {
  cx_vec temp;
  if (this->values->n_elem != other.values->n_elem)
    throw std::invalid_argument("Qudits must be the same size");

  mat CNOT = Qtils::homo_cnot_operator(this->values->n_elem);
  auto combined = combine(other);
  temp = CNOT * (*combined->getValues());
  return std::make_shared<Qbit>(Qbit(temp));
}

Qbit::valsr Qbit::cnot(vals other) {
  cx_vec temp;
  Qbit otherQ(std::move(other));  // move other to Qbit other);
  if (this->values->n_elem != otherQ.values->n_elem)
    throw std::invalid_argument("Qudits must be the same size");

  mat CNOT = Qtils::homo_cnot_operator(this->values->n_elem);
  auto combined = combine(otherQ);
  temp = CNOT * (*combined->getValues());
  return std::make_shared<Qbit>(Qbit(temp));
}

Qbit::valsr Qbit::haddamard() const {
  if (this->values->n_elem != 2)
    throw std::invalid_argument("Input must not be Qudit");
  mat h_matrix = {{1 / sqrt(2), 1 / sqrt(2)}, {1 / sqrt(2), -1 / sqrt(2)}};
  cx_vec temp = h_matrix * (*this->values);
  return std::make_shared<Qbit>(Qbit(temp));
}

Qbit::valsr Qbit::pauliX() const {
  if (this->values->n_elem != 2) {
    throw std::invalid_argument("Input must not be Qudit");
  }
  cx_vec temp = {{0, 1}, {1, 0}};
  return std::make_shared<Qbit>(Qbit(temp * (*this->values)));
}

Qbit::valsr Qbit::pauliY() const {
  if (this->values->n_elem != 2) {
    throw std::invalid_argument("Input must not be Qudit");
  }
  cx_mat temp = {{complex(0.0, 0.0), complex(0.0, -1.0)},
                 {complex(0.0, 1.0), complex(0.0, 0.0)}};
  return std::make_shared<Qbit>(Qbit(temp * (*this->values)));
}

Qbit::valsr Qbit::pauliZ() const {
  if (this->values->n_elem != 2) {
    throw std::invalid_argument("Input must not be Qudit");
  }
  cx_vec temp = {{1, 0}, {0, -1}};
  return std::make_shared<Qbit>(Qbit(temp * (*this->values)));
}

Qbit::valsr Qbit::identity() const {
  if (this->values->n_elem != 2) {
    throw std::invalid_argument("Input must not be Qudit");
  }
  cx_vec temp = {{1, 0}, {0, 1}};
  return std::make_shared<Qbit>(Qbit(temp * (*this->values)));
}

Qbit::valsr Qbit::rx(double angle) const {
  if (this->values->n_elem != 2) {
    throw std::invalid_argument("Input must not be Qudit");
  }
  cx_mat temp = {{cos(angle / 2), complex(-1.0, -sin(angle / 2))},
                 {complex(-1.0, -sin(angle / 2)), cos(angle / 2)}};
  return std::make_shared<Qbit>(Qbit(temp * (*this->values)));
}

Qbit::valsr Qbit::ry(double angle) const {
  if (this->values->n_elem != 2) {
    throw std::invalid_argument("Input must not be Qudit");
  }
  cx_vec temp = {{cos(angle / 2), -sin(angle / 2)},
                 {sin(angle / 2), cos(angle / 2)}};
  return std::make_shared<Qbit>(Qbit(temp * (*this->values)));
}

Qbit::valsr Qbit::rz(double angle) const {
  if (this->values->n_elem != 2) {
    throw std::invalid_argument("Input must not be Qudit");
  }
  cx_mat temp = {{exp(complex(-1.0, angle / 2)), complex(0.0, 0.0)},
                 {complex(0.0, 0.0), exp(complex(1.0, angle / 2))}};
  return std::make_shared<Qbit>(Qbit(temp * (*this->values)));
}

// S Gate: Applies a phase of π/2
Qbit::valsr Qbit::S() const {
  if (this->values->n_elem != 2) {
    throw std::invalid_argument("Input must not be Qudit");
  }
  cx_mat S_gate = {{1, 0}, {0, cx_double(0, 1)}};
  return std::make_shared<Qbit>(Qbit(S_gate * (*this->values)));
}

// T Gate: Applies a phase of π/4
Qbit::valsr Qbit::T() const {
  if (this->values->n_elem != 2) {
    throw std::invalid_argument("Input must not be Qudit");
  }
  cx_mat T_gate = {{1, 0}, {0, exp(cx_double(0, M_PI / 4))}};
  return std::make_shared<Qbit>(Qbit(T_gate * (*this->values)));
}

// S^\dagger Gate: Applies a phase of -π/2
Qbit::valsr Qbit::S_dag() const {
  if (this->values->n_elem != 2) {
    throw std::invalid_argument("Input must not be Qudit");
  }
  cx_mat S_dag_gate = {{1, 0}, {0, cx_double(0, -1)}};
  return std::make_shared<Qbit>(Qbit(S_dag_gate * (*this->values)));
}

// T^\dagger Gate: Applies a phase of -π/4
Qbit::valsr Qbit::T_dag() const {
  if (this->values->n_elem != 2) {
    throw std::invalid_argument("Input must not be Qudit");
  }
  cx_mat T_dag_gate = {{1, 0}, {0, exp(cx_double(0, -M_PI / 4))}};
  return std::make_shared<Qbit>(Qbit(T_dag_gate * (*this->values)));
}

// Controlled-Y Gate: Applies a Pauli Y gate to the target if the control is in
// state |1>
Qbit::valsr Qbit::cy(Qbit& other) {
  if (this->values->n_elem != other.values->n_elem) {
    throw std::invalid_argument("Qudits must be the same size");
  }
  cx_mat cy_gate = arma::zeros<cx_mat>(4, 4);
  cy_gate(0, 0) = 1;
  cy_gate(1, 1) = 1;
  cy_gate(2, 3) = cx_double(0, -1);
  cy_gate(3, 2) = cx_double(0, 1);

  auto combined = combine(other);
  cx_vec temp = cy_gate * (*combined->getValues());
  return std::make_shared<Qbit>(Qbit(temp));
}

Qbit::valsr Qbit::swap(Qbit& other) {
  if (this->values->n_elem != 2 || other.values->n_elem != 2) {
    throw std::invalid_argument("Both qubits must be valid");
  }
  cx_mat swap_mat = {{1, 0, 0, 0}, {0, 0, 1, 0}, {0, 1, 0, 0}, {0, 0, 0, 1}};

  auto combined = combine(other);
  cx_vec temp = swap_mat * (*combined->getValues());
  return std::make_shared<Qbit>(Qbit(temp));
}

Qbit::valsr Qbit::swap(const cx_vec& q1) {
  Qbit otherQ(q1);
  return swap(otherQ);
}

Qbit::valsr Qbit::cr(double angle) const {
  if (this->values->n_elem != 2) {
    throw std::invalid_argument("Input must be a qubit");
  }
  cx_double phi = exp(cx_double(0, angle));
  cx_mat cr_mat = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, phi}};

  return std::make_shared<Qbit>(Qbit(cr_mat * (*this->values)));
}

Qbit::valsr Qbit::crk(double k) const {
  double angle = M_PI * k;  // Convert fraction of π to radians
  return cr(angle);         // Reuse the controlled rotation function
}

Qbit::valsr Qbit::toffoli(Qbit& other1, Qbit& other2) {
  if (this->values->n_elem != 2 || other1.values->n_elem != 2 ||
      other2.values->n_elem != 2) {
    throw std::invalid_argument("All inputs must be qubits");
  }
  cx_mat toffoli_mat = arma::eye<cx_mat>(8, 8);
  toffoli_mat(7, 7) = 0;
  toffoli_mat(7, 6) = 1;
  toffoli_mat(6, 6) = 0;
  toffoli_mat(6, 7) = 1;

  auto combined1 = this->combine(other1);
  auto combined = combined1->combine(other2);
  cx_vec temp = toffoli_mat * (*combined->getValues());
  return std::make_shared<Qbit>(Qbit(temp));
}

Qbit::valsr Qbit::toffoli(const cx_vec& q1, const cx_vec& q2) {
  Qbit otherQ1(q1);
  Qbit otherQ2(q2);
  return toffoli(otherQ1, otherQ2);
}
