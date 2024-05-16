#ifndef FUNCTION_HH
#define FUNCTION_HH

#include <functional>

#include "QubitClass.hh"
#include "QuditClass.hh"
#include "func_wrapper.hh"

namespace QB_functions {
static uniform_return haddamard(uniform_input in) {
  std::get<std::reference_wrapper<Qbit>>(in.vals[0]).get().haddamard();
  return uniform_return{nullptr, NONE};
}

static uniform_return cr(uniform_input in) {
  std::get<std::reference_wrapper<Qbit>>(in.vals[0])
      .get()
      .cr(std::get<double>(in.vals[1]));
  return uniform_return{nullptr, NONE};
}

static uniform_return pauliX(uniform_input in) {
  std::get<std::reference_wrapper<Qbit>>(in.vals[0]).get().pauliX();
  return uniform_return{nullptr, NONE};
}

static uniform_return pauliY(uniform_input in) {
  std::get<std::reference_wrapper<Qbit>>(in.vals[0]).get().pauliY();
  return uniform_return{nullptr, NONE};
}

static uniform_return pauliZ(uniform_input in) {
  std::get<std::reference_wrapper<Qbit>>(in.vals[0]).get().pauliY();
  return uniform_return{nullptr, NONE};
}

static uniform_return identity(uniform_input in) {
  std::get<std::reference_wrapper<Qbit>>(in.vals[0]).get().identity();
  return uniform_return{nullptr, NONE};
}

static uniform_return toffoli(uniform_input in) {
  std::get<std::reference_wrapper<Qbit>>(in.vals[0])
      .get()
      .toffoli(std::get<std::reference_wrapper<Qbit>>(in.vals[1]),
               std::get<std::reference_wrapper<Qbit>>(in.vals[2]));
  return uniform_return{nullptr, NONE};
}

static uniform_return rx(uniform_input in) {
  std::get<std::reference_wrapper<Qbit>>(in.vals[0])
      .get()
      .rx(std::get<double>(in.vals[1]));
  return uniform_return{nullptr, NONE};
}

static uniform_return ry(uniform_input in) {
  std::get<std::reference_wrapper<Qbit>>(in.vals[0])
      .get()
      .ry(std::get<double>(in.vals[1]));
  return uniform_return{nullptr, NONE};
}

static uniform_return rz(uniform_input in) {
  std::get<std::reference_wrapper<Qbit>>(in.vals[0])
      .get()
      .rz(std::get<double>(in.vals[1]));
  return uniform_return{nullptr, NONE};
}

static uniform_return S(uniform_input in) {
  std::get<std::reference_wrapper<Qbit>>(in.vals[0]).get().S();
  return uniform_return{nullptr, NONE};
}

static uniform_return T(uniform_input in) {
  std::get<std::reference_wrapper<Qbit>>(in.vals[0]).get().T();
  return uniform_return{nullptr, NONE};
}

static uniform_return S_dag(uniform_input in) {
  std::get<std::reference_wrapper<Qbit>>(in.vals[0]).get().S_dag();
  return uniform_return{nullptr, NONE};
}

static uniform_return T_dag(uniform_input in) {
  std::get<std::reference_wrapper<Qbit>>(in.vals[0]).get().S_dag();
  return uniform_return{nullptr, NONE};
}

static uniform_return cy(uniform_input in) {
  std::get<std::reference_wrapper<Qbit>>(in.vals[0])
      .get()
      .cy(std::get<std::reference_wrapper<Qbit>>(in.vals[1]));
  return uniform_return{nullptr, NONE};
}

static uniform_return swap(uniform_input in) {
  std::get<std::reference_wrapper<Qbit>>(in.vals[0])
      .get()
      .swap(std::get<std::reference_wrapper<Qbit>>(in.vals[1]));
  return uniform_return{nullptr, NONE};
}

static uniform_return measure(uniform_input in) {
  auto temp =
      std::get<std::reference_wrapper<Qbit>>(in.vals[0]).get().measure();
  return uniform_return{temp, INT};
}

static uniform_return crk(uniform_input in) {
  std::get<std::reference_wrapper<Qbit>>(in.vals[0])
      .get()
      .crk(std::get<double>(in.vals[1]));
  return uniform_return{nullptr, NONE};
}

static uniform_return get(uniform_input in) {
  return uniform_return{
      std::get<std::reference_wrapper<Qbit>>(in.vals[0]).get().get(), VEC};
}
}  // namespace QB_functions

namespace QD_functions {
static uniform_return haddamard(uniform_input in) {
  std::get<std::reference_wrapper<Qudit>>(in.vals[0]).get().haddamard();
  return uniform_return{nullptr, NONE};
}

static uniform_return cr(uniform_input in) {
  std::get<std::reference_wrapper<Qudit>>(in.vals[0])
      .get()
      .cr(std::get<double>(in.vals[1]));
  return uniform_return{nullptr, NONE};
}

static uniform_return pauliX(uniform_input in) {
  std::get<std::reference_wrapper<Qudit>>(in.vals[0]).get().pauliX();
  return uniform_return{nullptr, NONE};
}

static uniform_return pauliY(uniform_input in) {
  std::get<std::reference_wrapper<Qudit>>(in.vals[0]).get().pauliY();
  return uniform_return{nullptr, NONE};
}

static uniform_return pauliZ(uniform_input in) {
  std::get<std::reference_wrapper<Qudit>>(in.vals[0]).get().pauliY();
  return uniform_return{nullptr, NONE};
}

static uniform_return identity(uniform_input in) {
  std::get<std::reference_wrapper<Qudit>>(in.vals[0]).get().identity();
  return uniform_return{nullptr, NONE};
}

static uniform_return toffoli(uniform_input in) {
  std::get<std::reference_wrapper<Qudit>>(in.vals[0])
      .get()
      .toffoli(std::get<std::reference_wrapper<Qudit>>(in.vals[1]),
               std::get<std::reference_wrapper<Qudit>>(in.vals[2]));
  return uniform_return{nullptr, NONE};
}

static uniform_return rx(uniform_input in) {
  std::get<std::reference_wrapper<Qudit>>(in.vals[0])
      .get()
      .rx(std::get<double>(in.vals[1]));
  return uniform_return{nullptr, NONE};
}

static uniform_return ry(uniform_input in) {
  std::get<std::reference_wrapper<Qudit>>(in.vals[0])
      .get()
      .ry(std::get<double>(in.vals[1]));
  return uniform_return{nullptr, NONE};
}

static uniform_return rz(uniform_input in) {
  std::get<std::reference_wrapper<Qudit>>(in.vals[0])
      .get()
      .rz(std::get<double>(in.vals[1]));
  return uniform_return{nullptr, NONE};
}

static uniform_return S(uniform_input in) {
  std::get<std::reference_wrapper<Qudit>>(in.vals[0]).get().S();
  return uniform_return{nullptr, NONE};
}

static uniform_return T(uniform_input in) {
  std::get<std::reference_wrapper<Qudit>>(in.vals[0]).get().T();
  return uniform_return{nullptr, NONE};
}

static uniform_return S_dag(uniform_input in) {
  std::get<std::reference_wrapper<Qudit>>(in.vals[0]).get().S_dag();
  return uniform_return{nullptr, NONE};
}

static uniform_return T_dag(uniform_input in) {
  std::get<std::reference_wrapper<Qudit>>(in.vals[0]).get().S_dag();
  return uniform_return{nullptr, NONE};
}

static uniform_return cy(uniform_input in) {
  std::get<std::reference_wrapper<Qudit>>(in.vals[0])
      .get()
      .cy(std::get<std::reference_wrapper<Qudit>>(in.vals[1]));
  return uniform_return{nullptr, NONE};
}

static uniform_return swap(uniform_input in) {
  std::get<std::reference_wrapper<Qudit>>(in.vals[0])
      .get()
      .swap(std::get<std::reference_wrapper<Qudit>>(in.vals[1]));
  return uniform_return{nullptr, NONE};
}

static uniform_return measure(uniform_input in) {
  auto temp =
      std::get<std::reference_wrapper<Qudit>>(in.vals[0]).get().measure();
  return uniform_return{temp, INT};
}

static uniform_return crk(uniform_input in) {
  std::get<std::reference_wrapper<Qudit>>(in.vals[0])
      .get()
      .crk(std::get<double>(in.vals[1]));
  return uniform_return{nullptr, NONE};
}

static uniform_return get(uniform_input in) {
  return uniform_return{
      std::get<std::reference_wrapper<Qudit>>(in.vals[0]).get().get(), VEC};
}
}  // namespace QD_functions

namespace G_functions {
template <class Engine>
static uniform_return declare(uniform_input in) {
  auto reference = std::get<std::reference_wrapper<Engine>>(in.vals[0]).get();
  auto nQ = Qbit();
  reference.append(nQ, 1);
  return uniform_return{nullptr, NONE};
}
}  // namespace G_functions

#endif
