#ifndef FUNC_WRAPPER_HH
#define FUNC_WRAPPER_HH

#include <armadillo>
#include <functional>
#include <string>
#include <variant>
#include <vector>

#include "QubitClass.hh"
#include "QuditClass.hh"

typedef std::vector<std::vector<Qbit>> memory__;

using vars = std::unordered_map<std::string, std::pair<uint8_t, size_t>>;
using dvars = std::unordered_map<std::string, size_t>;

enum types { BOOL, INT, QBIT, QUDIT, QBITVALS, QBITVALSR, NONE, VEC, MEM };

struct uniform_return {
  std::variant<bool, int, Qbit, Qudit, void*, cx_vec> val;
  types typ;
};

enum in_types { DOUBLE, QUBIT, QUDIT_, CX_VEC };

struct uniform_input {
  std::vector<std::variant<double, int, std::string, Qudit*, Qbit*, vars*,
                           std::reference_wrapper<cx_vec>, memory__*,
                           std::vector<Qudit>*, dvars*>>
      vals;
  std::vector<in_types> types;
};

#endif
