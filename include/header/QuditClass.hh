#ifndef QUDITCLASS_H
#define QUDITCLASS_H

#include <armadillo>
#include <memory>

using namespace arma;
using namespace std::complex_literals;

class Qudit {
 public:
  using valsr_ = cx_mat;

  // Constructors
  Qudit(const cx_vec& values)
      : values(std::make_unique<cx_vec>(values)), d(values.n_elem) {}
  Qudit() : values(std::make_unique<cx_vec>()), d(0) {}
  Qudit(std::unique_ptr<cx_vec> values)
      : values(std::move(values)), d(this->values->n_elem) {}

  // Copy constructor (deep copy)
  Qudit(const Qudit& other) 
      : values(std::make_unique<cx_vec>(*other.values)), d(other.d) {}

  // Move constructor
  Qudit(Qudit&& other) noexcept
      : values(std::move(other.values)), d(other.d) {
      other.d = 0;  // Reset other's dimension
  }

  // Copy assignment operator (deep copy)
  Qudit& operator=(const Qudit& other) {
      if (this != &other) {
          values = std::make_unique<cx_vec>(*other.values);
          d = other.d;
      }
      return *this;
  }

  // Move assignment operator
  Qudit& operator=(Qudit&& other) noexcept {
      if (this != &other) {
          values = std::move(other.values);
          d = other.d;
          other.d = 0;  // Reset other's dimension
      }
      return *this;
  }

  // Destructor
  ~Qudit() = default;

  // Example member functions
  valsr_ cnot(Qudit& other) noexcept;
  valsr_ haddamard() const;
  valsr_ pauliX() noexcept;
  valsr_ pauliY() const noexcept;
  valsr_ pauliZ() const noexcept;
  valsr_ identity() const noexcept;
  valsr_ rx(double angle);
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
  valsr_ toffoli(Qudit& other, Qudit& other2);
  Qudit combine(Qudit& other) noexcept;
  int measure() const;

  // Accessors
  valsr_ getValues() const noexcept { return valsr_(*this->values); }  // Changed to match declared type
  cx_vec get() const noexcept { return *this->values; }
  int get_d() const noexcept { return this->d; }

 private:
  std::unique_ptr<cx_vec> values;  // Use `cx_vec` consistently
  int d;
};

#endif
