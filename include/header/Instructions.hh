#ifndef INSTRUCTIONS_HH
#define INSTRUCTIONS_HH

#include <functional>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

#include "func_wrapper.hh"

using std::string;

extern std::unordered_map<string, std::function<uniform_return(uniform_input)>>
    instructions;

class Instructions {
 public:
  Instructions();
  ~Instructions() {}
  std::function<uniform_return(uniform_input)> operator[](std::string name);

  std::vector<std::tuple<string, string>> getArgs(std::string name);

 private:
  static std::unordered_map<std::string,
                            std::function<uniform_return(uniform_input)>>
      _instructions;

  static std::unordered_map<std::string,
                            std::vector<std::tuple<std::string, std::string>>>
      arguments;
};

#endif
