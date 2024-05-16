#ifndef QUIBITCLASS_H
#define QUIBITCLASS_H

#include <armadillo>
#include <memory>

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
  explicit Qbit() : values(std::make_unique<cx_vec>()) {}
  explicit Qbit(std::unique_ptr<cx_vec> values) : values(std::move(values)) {}
  explicit Qbit(const Qbit& other)
      : values(std::make_unique<cx_vec>(*other.values)) {}
  ~Qbit() {}
  Qudit combine(const vals q1);
  Qudit combine(const cx_vec& q1);
  Qudit combine(Qbit& q1);
  valsr cnot(Qbit& other);
  valsr cnot(const vals);
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
  valsr cy(Qbit& other);
  valsr cy(const cx_vec q1);
  valsr swap(Qbit& other);
  valsr swap(const cx_vec& q1);
  valsr cr(double angle) const;
  valsr crk(double angle) const;
  valsr toffoli(Qbit& other, Qbit& other2);
  valsr toffoli(const cx_vec& q1, const cx_vec& q2);
  int measure() const;

  cx_vec* getValues() const { return this->values.get(); }
  cx_vec get() const { return *this->values; }

  // valsr pauliX_qudit() const;
  // valsr pauliY_qudit() const;
  // valsr pauliZ_qudit() const;
  // valsr haddamard_qudit() const;
  // valsr identity_qudit() const;
  // valsr rx_qudit(double angle) const;
  // valsr ry_qudit(double angle) const;
  // valsr rz_qudit(double angle) const;
  // valsr S_qudit() const;
  // valsr T_qudit() const;
  // valsr S_dag_qudit() const;
  // valsr T_dag_qudit() const;
  // valsr cy_qudit(const Qbit& other) const;
  // valsr cy_qudit(const cx_vec q1) const;
  // valsr swap_qudit(const Qbit& other) const;
  // valsr swap_qudit(const cx_vec q1) const;
  // valsr cr_qudit(double angle) const;
  // valsr crk_qudit(double angle) const;
  // valsr toffoli_qudit(const Qbit& other) const;
  // valsr toffoli_qudit(const cx_vec q1) const;

 private:
  std::unique_ptr<cx_vec> values;  // thou shalt always be size two.
};

#endif
