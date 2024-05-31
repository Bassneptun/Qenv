#ifndef INSTRUCTIONS_HH
#define INSTRUCTIONS_HH

#include <functional>
#include <string>
#include <tuple>
#include <unordered_map>

#include "func_wrapper.hh"

using std::string;

using memory_ = std::vector<std::vector<Qbit>>;

using vars = std::unordered_map<std::string, std::pair<uint8_t, size_t>>;

class Instructions {
 public:
  Instructions(memory_& memory, vars& var_register)
      : memory(&memory), var_register(&var_register) {}
  ~Instructions() {}
  std::function<uniform_return(uniform_input)> operator[](std::string name);

  std::vector<std::tuple<std::string, std::string>> getArgs(std::string name);

  memory_* memory;

 private:
  static std::unordered_map<std::string,
                            std::function<uniform_return(uniform_input)>>
      _instructions;

  static std::unordered_map<std::string,
                            std::vector<std::tuple<std::string, std::string>>>
      arguments;
  vars* var_register;
};

#endif
