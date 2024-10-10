#ifndef QUBIT_ASSOCIATIVE_CONTAINER_HH
#define QUBIT_ASSOCIATIVE_CONTAINER_HH

#include <optional>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "Instructions.hh"
#include "QubitClass.hh"
#include "func_wrapper.hh"

class QubitAssociativeContainer {
 public:
  QubitAssociativeContainer() = default;
  ~QubitAssociativeContainer() {}

  void execute(int start, int end, string instruction,
               std::optional<uniform_input> extra_arguments = std::nullopt) {
    auto func = instructions->operator[](instruction);
    for (auto [i, j] : std::vector<std::pair<int, int>>(qubits.begin() + start,
                                                        qubits.begin() + end)) {
      Qbit* q = &memory->at(i).at(j);
      uniform_input in{{q}, {}};
      if (extra_arguments) {
        for (auto w : (*extra_arguments).vals) {
          in.vals.push_back(w);
        }
      }
      func(uniform_input{{q}, {QUBIT}});
    }
  }

  void push_back(std::pair<int, int> qubit) { qubits.push_back(qubit); }

 private:
  std::vector<std::pair<int, int>> qubits;

  std::unordered_map<std::string, std::pair<uint8_t, size_t>>*
      variables;  // map variable names to place and index

  std::vector<std::vector<Qbit>>* memory;
  Instructions* instructions;
};

#endif
