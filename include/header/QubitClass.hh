#ifndef QUIBITCLASS_H
#define QUIBITCLASS_H

#include <armadillo>
#include <memory>

#include "qtils.hh"

using namespace arma;

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
  virtual ~Qbit() {}
  valsr combine(const vals q1);
  valsr combine(const cx_vec& q1);
  valsr combine(Qbit& q1);
  virtual valsr cnot(Qbit& other);
  virtual valsr cnot(const vals);
  virtual valsr haddamard() const;
  virtual valsr pauliX() const;
  virtual valsr pauliY() const;
  virtual valsr pauliZ() const;
  virtual valsr identity() const;
  virtual valsr rx(double angle) const;
  virtual valsr ry(double angle) const;
  virtual valsr rz(double angle) const;
  virtual valsr S() const;
  virtual valsr T() const;
  virtual valsr S_dag() const;
  virtual valsr T_dag() const;
  virtual valsr cy(Qbit& other);
  virtual valsr cy(const cx_vec q1);
  virtual valsr swap(Qbit& other);
  virtual valsr swap(const cx_vec& q1);
  virtual valsr cr(double angle) const;
  virtual valsr crk(double angle) const;
  virtual valsr toffoli(Qbit& other, Qbit& other2);
  virtual valsr toffoli(const cx_vec& q1, const cx_vec& q2);
  virtual int measure() const;
  virtual int measure_qudit() const;

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

class Qudit : public Qbit {
 public:
  explicit Qudit(const cx_vec& values) : Qbit(values) {}
  explicit Qudit() : Qbit() {}
  explicit Qudit(std::unique_ptr<cx_vec> values) : Qbit(std::move(values)) {}
  explicit Qudit(Qbit& other) : Qbit(other) {}

  valsr cnot(Qbit& other) noexcept override;
  valsr cnot(const vals) noexcept override;
  valsr haddamard() const noexcept override;
  valsr pauliX() const noexcept override;
  valsr pauliY() const noexcept override;
  valsr pauliZ() const noexcept override;
  valsr identity() const noexcept override;
  valsr rx(double angle) const noexcept override;
  valsr ry(double angle) const noexcept override;
  valsr rz(double angle) const noexcept override;
  valsr S() const noexcept override;
  valsr T() const noexcept override;
  valsr S_dag() const noexcept override;
  valsr T_dag() const noexcept override;
  valsr cy(Qbit& other) noexcept override;
  valsr cy(const cx_vec q1) noexcept override;
  valsr swap(Qbit& other) noexcept override;
  valsr swap(const cx_vec& q1) noexcept override;
  valsr cr(double angle) const noexcept override;
  valsr crk(double angle) const noexcept override;
  valsr toffoli(Qbit& other, Qbit& other2) noexcept override;
  valsr toffoli(const cx_vec& q1, const cx_vec& q2) noexcept override;
  int measure() const override;
  int measure_qudit() const override;

 private:
  vals values;  // thou may be of any size. Size 2'd be kinda pointless tho...
};

#endif
