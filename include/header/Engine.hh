#ifndef ENGINE_HH
#define ENGINE_HH

#include <array>
#include <cstdint>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "Confirm.hh"
#include "Instructions.hh"
#include "QubitClass.hh"

class Engine {
 public:
  Engine(std::string path)
      : instructions(*this),
        bytecode(path,
                 std::make_shared<Instructions<Engine>>(this->instructions)),
        it(bytecode.begin()) {}
  ~Engine() {}

  void execute();

  void append(Qbit qubit, uint8_t place) {
    switch (place) {
      case 0:
        // registers[reg_index++] = std::move(qubit);  // registers[reg_index++]
        // = qubit;
        break;
      case 1:
        stack.push_back(qubit);  // stack[qubit] = qubit;
        break;
      case 2:
        heap.push_back(qubit);  // heap[(int)qubit] = qubit;
        break;
      case 3:
        globals.push_back(qubit);  // globals[qubit] = qubit;
        break;
      default:
        break;
    }
  }

 private:
  Instructions<Engine> instructions;

  Maybe<Engine> bytecode;
  Maybe<Engine>::iterator it;

  std::unordered_map<std::string, std::pair<uint8_t, size_t>>
      variables;  // map variable names to place and index

  int reg_index = 0;
  std::array<Qbit, 12> registers;
  std::vector<Qbit> stack;
  std::vector<Qbit> heap;
  std::vector<Qbit> globals;
};

#endif
