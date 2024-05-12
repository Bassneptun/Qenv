#ifndef QUIBITCLASS_H
#define QUIBITCLASS_H

#include <armadillo>
#include <memory>

#include "qtils.hh"

using namespace arma;

typedef std::shared_ptr<cx_vec> valsr;
typedef std::unique_ptr<cx_vec> vals;

class Qbit {
 public:
  explicit Qbit(const cx_vec& values)
      : values(std::make_unique<cx_vec>(values)) {}
  explicit Qbit() : values(std::make_unique<cx_vec>()) {}
  explicit Qbit(vals values) : values(std::move(values)) {}
  ~Qbit() {}
  valsr combine(const vals q1);
  valsr combine(const cx_vec& q1);
  valsr combine(const Qbit& q1);
  valsr cnot(const Qbit& other);
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
  valsr cx(const Qbit& other) const;
  valsr cx(const cx_vec q1) const;

  valsr pauliX_qudit() const;
  valsr pauliY_qudit() const;
  valsr pauliZ_qudit() const;
  valsr haddamard_qudit() const;

 private:
  vals values;
};

#endif
