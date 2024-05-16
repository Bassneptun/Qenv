#ifndef QUDITCLASS_H
#define QUDITCLASS_H

#include <armadillo>
#include <memory>

using namespace arma;

class Qudit {
 public:
  typedef std::shared_ptr<Qudit> valsr_;

  explicit Qudit(const cx_vec& values) {}
  explicit Qudit() {}
  explicit Qudit(std::unique_ptr<cx_vec> values) {}

  valsr_ cnot(Qudit& other) noexcept;
  valsr_ haddamard() const noexcept;
  valsr_ pauliX() const noexcept;
  valsr_ pauliY() const noexcept;
  valsr_ pauliZ() const noexcept;
  valsr_ identity() const noexcept;
  valsr_ rx(double angle) const noexcept;
  valsr_ ry(double angle) const noexcept;
  valsr_ rz(double angle) const noexcept;
  valsr_ S() const noexcept;
  valsr_ T() const noexcept;
  valsr_ S_dag() const noexcept;
  valsr_ T_dag() const noexcept;
  valsr_ cy(Qudit& other) noexcept;
  valsr_ swap(Qudit& other) noexcept;
  valsr_ cr(double angle) const noexcept;
  valsr_ crk(double angle) const noexcept;
  valsr_ toffoli(Qudit& other, Qudit& other2) noexcept;
  Qudit combine(Qudit& other) noexcept;
  int measure() const;
  int measure_qudit() const;

  valsr_ getValues() const noexcept { return std::make_shared<Qudit>(*values); }
  cx_vec& get() noexcept { return *values; }

 private:
  std::unique_ptr<cx_vec>
      values;  // thou may be of any size. Size 2'd be kinda pointless tho...
  int d;
};

#endif
