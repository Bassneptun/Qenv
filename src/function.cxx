#include "../include/header/function.hh"

#include <armadillo>
#include <iostream>
#include <optional>
#include <ostream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#include "../include/header/QubitClass.hh"
#include "../include/header/QuditClass.hh"
#include "../include/header/func_wrapper.hh"
#include "../include/header/function.hh"

uniform_return QB_functions::haddamard(uniform_input in) {
  std::get<Qbit *>(in.vals[0])->haddamard();
  return uniform_return{nullptr, NONE};
}

uniform_return QB_functions::pauliX(uniform_input in) {
  std::get<Qbit *>(in.vals[0])->pauliX();
  return uniform_return{nullptr, NONE};
}

uniform_return QB_functions::pauliY(uniform_input in) {
  std::get<Qbit *>(in.vals[0])->pauliY();
  return uniform_return{nullptr, NONE};
}

uniform_return QB_functions::pauliZ(uniform_input in) {
  std::get<Qbit *>(in.vals[0])->pauliY();
  return uniform_return{nullptr, NONE};
}

uniform_return QB_functions::identity(uniform_input in) {
  std::get<Qbit *>(in.vals[0])->identity();
  return uniform_return{nullptr, NONE};
}

uniform_return QB_functions::toffoli(uniform_input in) {
  Qudit *location = std::get<Qudit *>(in.vals[2]);
  *location = std::get<Qbit *>(in.vals[0])
                  ->toffoli(*std::get<Qbit *>(in.vals[1]),
                            *std::get<Qbit *>(in.vals[2]));
  return uniform_return{nullptr, NONE};
}

uniform_return QB_functions::rx(uniform_input in) {
  std::get<Qbit *>(in.vals[0])->rx(std::get<double>(in.vals[1]));
  return uniform_return{nullptr, NONE};
}

uniform_return QB_functions::ry(uniform_input in) {
  std::get<Qbit *>(in.vals[0])->ry(std::get<double>(in.vals[1]));
  return uniform_return{nullptr, NONE};
}

uniform_return QB_functions::rz(uniform_input in) {
  std::get<Qbit *>(in.vals[0])->rz(std::get<double>(in.vals[1]));
  return uniform_return{nullptr, NONE};
}

uniform_return QB_functions::S(uniform_input in) {
  std::get<Qbit *>(in.vals[0])->S();
  return uniform_return{nullptr, NONE};
}

uniform_return QB_functions::T(uniform_input in) {
  std::get<Qbit *>(in.vals[0])->T();
  return uniform_return{nullptr, NONE};
}

uniform_return QB_functions::S_dag(uniform_input in) {
  std::get<Qbit *>(in.vals[0])->S_dag();
  return uniform_return{nullptr, NONE};
}

uniform_return QB_functions::T_dag(uniform_input in) {
  std::get<Qbit *>(in.vals[0])->S_dag();
  return uniform_return{nullptr, NONE};
}

uniform_return QB_functions::cy(uniform_input in) {
  Qudit *location = std::get<Qudit *>(in.vals[2]);
  *location = std::get<Qbit *>(in.vals[0])->cy(*std::get<Qbit *>(in.vals[1]));
  return uniform_return{nullptr, NONE};
}

uniform_return QB_functions::swap(uniform_input in) {
  Qudit *location = std::get<Qudit *>(in.vals[2]);
  *location = std::get<Qbit *>(in.vals[0])->swap(*std::get<Qbit *>(in.vals[1]));
  return uniform_return{nullptr, NONE};
}

uniform_return QB_functions::measure(uniform_input in) {
  auto temp = std::get<Qbit *>(in.vals[0])->measure();
  return uniform_return{temp, INT};
}

uniform_return QB_functions::get(uniform_input in) {
  return uniform_return{std::get<Qbit *>(in.vals[0])->get(), VEC};
}

uniform_return QB_functions::cnot(uniform_input in) {
  Qudit *location = std::get<Qudit *>(in.vals[2]);
  *location = std::get<Qbit *>(in.vals[0])->cnot(*std::get<Qbit *>(in.vals[1]));
  return uniform_return{nullptr, NONE};
}

uniform_return QD_functions::haddamard(uniform_input in) {
  std::get<Qudit *>(in.vals[0])->haddamard();
  return uniform_return{nullptr, NONE};
}

uniform_return QD_functions::cr(uniform_input in) {
  std::get<Qudit *>(in.vals[0])->cr(std::get<double>(in.vals[1]));
  return uniform_return{nullptr, NONE};
}

uniform_return QD_functions::pauliX(uniform_input in) {
  std::get<Qudit *>(in.vals[0])->pauliX();
  return uniform_return{nullptr, NONE};
}

uniform_return QD_functions::pauliY(uniform_input in) {
  std::get<Qudit *>(in.vals[0])->pauliY();
  return uniform_return{nullptr, NONE};
}

uniform_return QD_functions::pauliZ(uniform_input in) {
  std::get<Qudit *>(in.vals[0])->pauliY();
  return uniform_return{nullptr, NONE};
}

uniform_return QD_functions::identity(uniform_input in) {
  std::get<Qudit *>(in.vals[0])->identity();
  return uniform_return{nullptr, NONE};
}

uniform_return QD_functions::toffoli(uniform_input in) {
  std::get<Qudit *>(in.vals[0])
      ->toffoli(*std::get<Qudit *>(in.vals[1]), *std::get<Qudit *>(in.vals[2]));
  return uniform_return{nullptr, NONE};
}

uniform_return QD_functions::rx(uniform_input in) {
  std::get<Qudit *>(in.vals[0])->rx(std::get<double>(in.vals[1]));
  return uniform_return{nullptr, NONE};
}

uniform_return QD_functions::ry(uniform_input in) {
  std::get<Qudit *>(in.vals[0])->ry(std::get<double>(in.vals[1]));
  return uniform_return{nullptr, NONE};
}

uniform_return QD_functions::rz(uniform_input in) {
  std::get<Qudit *>(in.vals[0])->rz(std::get<double>(in.vals[1]));
  return uniform_return{nullptr, NONE};
}

uniform_return QD_functions::S(uniform_input in) {
  std::get<Qudit *>(in.vals[0])->S();
  return uniform_return{nullptr, NONE};
}

uniform_return QD_functions::T(uniform_input in) {
  std::get<Qudit *>(in.vals[0])->T();
  return uniform_return{nullptr, NONE};
}

uniform_return QD_functions::S_dag(uniform_input in) {
  std::get<Qudit *>(in.vals[0])->S_dag();
  return uniform_return{nullptr, NONE};
}

uniform_return QD_functions::T_dag(uniform_input in) {
  std::get<Qudit *>(in.vals[0])->S_dag();
  return uniform_return{nullptr, NONE};
}

uniform_return QD_functions::cy(uniform_input in) {
  std::get<Qudit *>(in.vals[0])->cy(*std::get<Qudit *>(in.vals[1]));
  return uniform_return{nullptr, NONE};
}

uniform_return QD_functions::swap(uniform_input in) {
  std::get<Qudit *>(in.vals[0])->swap(*std::get<Qudit *>(in.vals[1]));
  return uniform_return{nullptr, NONE};
}

uniform_return QD_functions::measure(uniform_input in) {
  auto temp = std::get<Qudit *>(in.vals[0])->measure();
  return uniform_return{temp, INT};
}

uniform_return QD_functions::crk(uniform_input in) {
  std::get<Qudit *>(in.vals[0])->crk(std::get<double>(in.vals[1]));
  return uniform_return{nullptr, NONE};
}

uniform_return QD_functions::get(uniform_input in) {
  return uniform_return{std::get<Qudit *>(in.vals[0])->get(), VEC};
} // namespace QD_functions

uniform_return AG_functions::qalloc(uniform_input in) {
  std::vector<std::vector<Qbit>> *mem =
      std::get<std::vector<std::vector<Qbit>> *>(in.vals[0]);
  vars *v = std::get<vars *>(in.vals[2]);
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

uniform_return AG_functions::show(uniform_input in) {
  Qbit *tmp = std::get<Qbit *>(in.vals[0]);
  tmp->get().print("");
  return uniform_return{nullptr, NONE};
}

uniform_return AG_functions::set(uniform_input in) {
  Qbit *tmp = std::get<Qbit *>(in.vals[0]);

  std::optional<int> a = std::get<int>(in.vals[1]) == -1
                             ? std::nullopt
                             : std::make_optional(std::get<int>(in.vals[1]));
  std::optional<int> b = std::get<int>(in.vals[2]) == -1
                             ? std::nullopt
                             : std::make_optional(std::get<int>(in.vals[2]));
  tmp->set(a, b);
  return uniform_return{nullptr, NONE};
}

uniform_return AG_functions::custom_gate(uniform_input in) {
  Qbit *q = std::get<Qbit *>(in.vals[0]);
  std::vector<int> g;
  for (int i = 1; i < 5; i++) {
    g.push_back(std::get<int>(in.vals[i]));
  }
  mat gate = {{(double)g[0], (double)g[1]}, {(double)g[2], (double)g[3]}};
  q->custom(gate);
  return uniform_return{nullptr, NONE};
}

uniform_return AG_functions::constant_function_apply(uniform_input in) {
  Qbit *q = std::get<Qbit *>(in.vals[0]);
  mat gate = eye<mat>(4, 4);
  gate(3, 3) = -1;
  q->custom(gate);

  return uniform_return{nullptr, NONE};
}

uniform_return AG_functions::dalloc(uniform_input in) {
  std::vector<Qudit> *mem = std::get<std::vector<Qudit> *>(in.vals[0]);
  dvars *variables = std::get<dvars *>(in.vals[1]);

  variables->insert(
      std::make_pair(std::get<std::string>(in.vals[2]), mem->size()));
  mem->push_back(Qudit());
  return uniform_return{nullptr, NONE};
} // namespace AG_functions

uniform_return AG_functions::dshow(uniform_input in) {
  Qudit *tmp = std::get<Qudit *>(in.vals[0]);
  tmp->get().print(std::get<std::string>(in.vals[1]));
  return uniform_return{nullptr, NONE};
}

uniform_return AG_functions::copy(uniform_input in) {
  Qudit *tmp = std::get<Qudit *>(in.vals[0]);
  Qudit *tmp2 = std::get<Qudit *>(in.vals[1]);
  *tmp = *tmp2;
  return uniform_return{nullptr, NONE};
}

uniform_return AG_functions::dcopy(uniform_input in) {
  Qudit *tmp = std::get<Qudit *>(in.vals[0]);
  Qudit *tmp2 = std::get<Qudit *>(in.vals[1]);
  *tmp = *tmp2;
  return uniform_return{nullptr, NONE};
}

uniform_return AG_functions::free(uniform_input in) {
  memory__ *mem = std::get<memory__ *>(in.vals[0]);
  vars *variables = std::get<vars *>(in.vals[1]);
  auto t = variables->at(std::get<std::string>(in.vals[2]));
  mem->operator[](t.first).erase(mem->operator[](t.first).begin() + t.second);
  variables->erase(std::get<std::string>(in.vals[2]));
  return uniform_return{nullptr, NONE};
}

uniform_return AG_functions::dfree(uniform_input in) {
  std::vector<Qudit> *mem = std::get<std::vector<Qudit> *>(in.vals[0]);
  dvars *variables = std::get<dvars *>(in.vals[1]);
  auto t = variables->at(std::get<std::string>(in.vals[2]));
  mem->erase(mem->begin() + t);
  variables->erase(std::get<std::string>(in.vals[2]));
  return uniform_return{nullptr, NONE};
}

uniform_return AG_functions::save_state(uniform_input in) {
  memory__ *mem = std::get<memory__ *>(in.vals[0]);
  std::vector<Qudit> *mem2 = std::get<std::vector<Qudit> *>(in.vals[1]);
  for (auto it:*mem) {
    for(auto it2:it) {
      it2.get().raw_print("");
    }
  }
  for (auto it:*mem2) {
    it.get().raw_print("");
    std::cout << "e";
  }

  return uniform_return{nullptr, NONE};
}
