#ifndef ENGINE_HH
#define ENGINE_HH

#include <array>
#include <functional>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include "Confirm.hh"
#include "QubitClass.hh"

class Engine {
 public:
  Engine();
  ~Engine() {}

 private:
  std::unordered_map<std::string, std::vector<std::function<void>>>
      instructions;

  Maybe bytecode;

  std::array<Qbit, 12> registers;
  std::stack<Qbit> stack;
  std::vector<Qbit> heap;
};

#endif
