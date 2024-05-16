#ifndef FUNC_WRAPPER_HH
#define FUNC_WRAPPER_HH

#include <armadillo>
#include <functional>
#include <variant>
#include <vector>

#include "QubitClass.hh"
#include "QuditClass.hh"

enum types { BOOL, INT, QBIT, QUDIT, QBITVALS, QBITVALSR, NONE, VEC };

struct uniform_return {
  std::variant<bool, int, Qbit, Qudit, Qbit::vals, Qbit::valsr, void*, cx_vec>
      val;
  types typ;
};

enum in_types { DOUBLE, QUBIT, QUDIT_, CX_VEC };

struct uniform_input {
  std::vector<std::variant<double, std::reference_wrapper<Qudit>,
                           std::reference_wrapper<Qbit>,
                           std::reference_wrapper<cx_vec>>>
      vals;
  std::vector<in_types> types;
};

#endif
