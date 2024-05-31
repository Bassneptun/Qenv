#include <functional>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#include "QubitClass.hh"
#include "QuditClass.hh"
#include "func_wrapper.hh"

namespace QB_functions {
static uniform_return haddamard(uniform_input in) {
  std::get<Qbit*>(in.vals[0])->haddamard();
  return uniform_return{nullptr, NONE};
}

static uniform_return pauliX(uniform_input in) {
  std::get<Qbit*>(in.vals[0])->pauliX();
  return uniform_return{nullptr, NONE};
}

static uniform_return pauliY(uniform_input in) {
  std::get<Qbit*>(in.vals[0])->pauliY();
  return uniform_return{nullptr, NONE};
}

static uniform_return pauliZ(uniform_input in) {
  std::get<Qbit*>(in.vals[0])->pauliY();
  return uniform_return{nullptr, NONE};
}

static uniform_return identity(uniform_input in) {
  std::get<Qbit*>(in.vals[0])->identity();
  return uniform_return{nullptr, NONE};
}

static uniform_return toffoli(uniform_input in) {
  std::get<Qbit*>(in.vals[0])
      ->toffoli(*std::get<Qbit*>(in.vals[1]), *std::get<Qbit*>(in.vals[2]));
  return uniform_return{nullptr, NONE};
}

static uniform_return rx(uniform_input in) {
  std::get<Qbit*>(in.vals[0])->rx(std::get<double>(in.vals[1]));
  return uniform_return{nullptr, NONE};
}

static uniform_return ry(uniform_input in) {
  std::get<Qbit*>(in.vals[0])->ry(std::get<double>(in.vals[1]));
  return uniform_return{nullptr, NONE};
}

static uniform_return rz(uniform_input in) {
  std::get<Qbit*>(in.vals[0])->rz(std::get<double>(in.vals[1]));
  return uniform_return{nullptr, NONE};
}

static uniform_return S(uniform_input in) {
  std::get<Qbit*>(in.vals[0])->S();
  return uniform_return{nullptr, NONE};
}

static uniform_return T(uniform_input in) {
  std::get<Qbit*>(in.vals[0])->T();
  return uniform_return{nullptr, NONE};
}

static uniform_return S_dag(uniform_input in) {
  std::get<Qbit*>(in.vals[0])->S_dag();
  return uniform_return{nullptr, NONE};
}

static uniform_return T_dag(uniform_input in) {
  std::get<Qbit*>(in.vals[0])->S_dag();
  return uniform_return{nullptr, NONE};
}

static uniform_return cy(uniform_input in) {
  std::get<Qbit*>(in.vals[0])->cy(*std::get<Qbit*>(in.vals[1]));
  return uniform_return{nullptr, NONE};
}

static uniform_return swap(uniform_input in) {
  std::get<Qbit*>(in.vals[0])->swap(*std::get<Qbit*>(in.vals[1]));
  return uniform_return{nullptr, NONE};
}

static uniform_return measure(uniform_input in) {
  auto temp = std::get<Qbit*>(in.vals[0])->measure();
  return uniform_return{temp, INT};
}

static uniform_return get(uniform_input in) {
  return uniform_return{std::get<Qbit*>(in.vals[0])->get(), VEC};
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

namespace AG_functions {
static uniform_return qalloc(uniform_input in) {
  std::vector<std::vector<Qbit>>* mem =
      std::get<std::vector<std::vector<Qbit>>*>(in.vals[0]);
  vars* v = std::get<vars*>(in.vals[2]);
  int t = std::get<int>(in.vals[1]);
  if (t > mem->size())
    throw std::out_of_range("Out of bounds");
  else if (mem->size() != 0 && mem->operator[](0).size() != 0) {
    v->insert(std::make_pair(std::get<std::string>(in.vals[3]),
                             std::make_pair(t, mem->operator[](t).size())));
    mem->operator[](t).push_back(Qbit());
    return uniform_return{nullptr, NONE};
  } else {
    mem->push_back({});
    if (mem->operator[](t).empty()) {
      v->insert(std::make_pair(std::get<std::string>(in.vals[3]),
                               std::make_pair(t, 0)));
    } else {
      v->insert(std::make_pair(std::get<std::string>(in.vals[3]),
                               std::make_pair(t, mem->operator[](t).size())));
    }
    mem->operator[](t).push_back(Qbit());
    return uniform_return{nullptr, NONE};
  }
  return uniform_return{nullptr, NONE};
}
}  // namespace AG_functions
