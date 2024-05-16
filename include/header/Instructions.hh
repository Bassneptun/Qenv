#ifndef INSTRUCTIONS_HH
#define INSTRUCTIONS_HH

#include <functional>
#include <string>
#include <unordered_map>

#include "func_wrapper.hh"

using std::string;

extern std::unordered_map<string, std::function<uniform_return(uniform_input)>>
    instructions;

template <typename Engine>
class Instructions {
 public:
  Instructions(Engine& engine) : engine(engine) {}
  ~Instructions() {}
  std::function<uniform_return(uniform_input)> operator[](std::string name);

  std::vector<std::tuple<std::string, std::string>> getArgs(std::string name);

 private:
  Engine& engine;
  static std::unordered_map<std::string,
                            std::function<uniform_return(uniform_input)>>
      _instructions;

  static std::unordered_map<std::string,
                            std::vector<std::tuple<std::string, std::string>>>
      arguments;
};

#endif
