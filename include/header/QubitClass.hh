#ifndef QUIBITCLASS_H
#define QUIBITCLASS_H

#include <armadillo>
#include <cmath>
#include <complex>
#include <memory>
#include <optional>
#include <utility>

#include "QuditClass.hh"
#include "qtils.hh"

using namespace arma;
using namespace std::complex_literals;

class Qbit {
 public:
  typedef std::unique_ptr<cx_vec> vals;
  explicit Qbit(const cx_vec& values)
      : values(std::make_unique<cx_vec>(values)) {}
  explicit Qbit(Qbit& other)
      : values(std::make_unique<cx_vec>(*other.values)) {}
  explicit Qbit() {
    cx_vec tmp = {1. / std::sqrt(2), 1. / std::sqrt(2)};
    this->values = std::make_unique<cx_vec>(tmp);
  }
  explicit Qbit(std::unique_ptr<cx_vec> values) : values(std::move(values)) {}
  explicit Qbit(const Qbit& other)
      : values(std::make_unique<cx_vec>(*other.values)) {}
  virtual ~Qbit() {}

  Qudit combine(const vals q1);
  Qudit combine(const cx_vec& q1);
  Qudit combine(Qbit& q1);
  Qudit cnot(Qbit& other);
  Qudit cnot(const vals);
  Qbit& haddamard();
  Qbit& pauliX();
  Qbit& pauliY();
  Qbit& pauliZ();
  Qbit& identity();
  Qbit& rx(double angle);
  Qbit& ry(double angle);
  Qbit& rz(double angle);
  Qbit& S();
  Qbit& T();
  Qbit& S_dag();
  Qbit& T_dag();
  Qudit cy(Qbit& other);
  Qudit cy(const cx_vec q1);
  Qudit swap(Qbit& other);
  Qudit swap(const cx_vec& q1);
  // Qbit& cr(double angle) const;
  // Qbit& crk(double angle) const;
  Qudit toffoli(Qbit& other, Qbit& other2);
  Qudit toffoli(const cx_vec& q1, const cx_vec& q2);
  int measure() const;

  void set(std::optional<std::complex<double>> a,
           std::optional<std::complex<double>> b) {
    if (a) this->values->operator()(0) = *a;
    if (b) this->values->operator()(1) = *b;
  }

  void set(const cx_vec& a) { *this->values = a; }

  cx_vec* getValues() const { return this->values.get(); }
  cx_vec get() const { return *this->values; }

  Qbit& operator=(Qbit& other) {
    this->values.swap(other.values);
    return *this;
  }

  Qbit& custom(const cx_vec&);
  Qbit& custom(const mat&);

  friend auto operator<=>(const Qbit&, const Qbit&) = default;

 private:
  std::unique_ptr<cx_vec> values;  // thou shalt always be size two.
};

#endif
