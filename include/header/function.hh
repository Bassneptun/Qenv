#ifndef FUNCTION_HH
#define FUNCTION_HH

#include <armadillo>
#include <optional>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#include "QubitClass.hh"
#include "QuditClass.hh"
#include "func_wrapper.hh"

class QB_functions {
 public:
  static uniform_return haddamard(uniform_input in);

  static uniform_return pauliX(uniform_input in);

  static uniform_return pauliY(uniform_input in);

  static uniform_return pauliZ(uniform_input in);

  static uniform_return identity(uniform_input in);

  static uniform_return toffoli(uniform_input in);

  static uniform_return rx(uniform_input in);

  static uniform_return ry(uniform_input in);

  static uniform_return rz(uniform_input in);

  static uniform_return S(uniform_input in);

  static uniform_return T(uniform_input in);

  static uniform_return S_dag(uniform_input in);

  static uniform_return T_dag(uniform_input in);

  static uniform_return cy(uniform_input in);

  static uniform_return swap(uniform_input in);

  static uniform_return measure(uniform_input in);

  static uniform_return get(uniform_input in);

  static uniform_return cnot(uniform_input in);
};  // namespace QB_functions

class QD_functions {
 public:
  static uniform_return haddamard(uniform_input in);

  static uniform_return cr(uniform_input in);

  static uniform_return pauliX(uniform_input in);

  static uniform_return pauliY(uniform_input in);

  static uniform_return pauliZ(uniform_input in);

  static uniform_return identity(uniform_input in);

  static uniform_return toffoli(uniform_input in);

  static uniform_return rx(uniform_input in);

  static uniform_return ry(uniform_input in);

  static uniform_return rz(uniform_input in);

  static uniform_return S(uniform_input in);

  static uniform_return T(uniform_input in);

  static uniform_return S_dag(uniform_input in);

  static uniform_return T_dag(uniform_input in);

  static uniform_return cy(uniform_input in);

  static uniform_return swap(uniform_input in);

  static uniform_return measure(uniform_input in);

  static uniform_return crk(uniform_input in);

  static uniform_return get(uniform_input in);
};  // namespace QD_functions

class AG_functions {
 public:
  static uniform_return qalloc(uniform_input in);

  static uniform_return show(uniform_input in);

  static uniform_return set(uniform_input in);

  static uniform_return custom_gate(uniform_input in);

  static uniform_return constant_function_apply(uniform_input in);

  static uniform_return dalloc(uniform_input in);

  static uniform_return dshow(uniform_input in);
};  // namespace AG_functions

#endif
