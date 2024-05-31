#ifndef QUIBITCLASS_H
#define QUIBITCLASS_H

#include <armadillo>
#include <cmath>
#include <complex>
#include <memory>
#include <utility>

#include "QuditClass.hh"
#include "qtils.hh"

using namespace arma;
using namespace std::complex_literals;

class Qbit {
 public:
  typedef std::shared_ptr<Qbit> valsr;
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
  valsr haddamard() const;
  valsr pauliX() const;
  valsr pauliY() const;
  valsr pauliZ() const;
  valsr identity() const;
  valsr rx(double angle) const;
  valsr ry(double angle) const;
  valsr rz(double angle) const;
  valsr S() const;
  valsr T() const;
  valsr S_dag() const;
  valsr T_dag() const;
  Qudit cy(Qbit& other);
  Qudit cy(const cx_vec q1);
  valsr swap(Qbit& other);
  valsr swap(const cx_vec& q1);
  // valsr cr(double angle) const;
  // valsr crk(double angle) const;
  Qudit toffoli(Qbit& other, Qbit& other2);
  Qudit toffoli(const cx_vec& q1, const cx_vec& q2);
  int measure() const;

  void set(const cx_vec& values) { *this->values = values; }

  cx_vec* getValues() const { return this->values.get(); }
  cx_vec get() const { return *this->values; }

  Qbit& operator=(Qbit& other) {
    this->values.swap(other.values);
    return *this;
  }

  friend auto operator<=>(const Qbit&, const Qbit&) = default;

 private:
  std::unique_ptr<cx_vec> values;  // thou shalt always be size two.
};

#endif
