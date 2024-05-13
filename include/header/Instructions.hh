#ifndef INSTRUCTIONS_HH
#define INSTRUCTIONS_HH

#include <cstdint>
#include <functional>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

#include "QubitClass.hh"

using std::string;

struct ret_vals {
  union value {
    void* none;
    Qbit::valsr ret;
    Qbit::vals why;
    Qbit qbit;
  };
  uint8_t discriminator;
};

extern std::unordered_map<string, std::vector<std::function<void>>>
    instructions;

class Instructions {
 public:
  Instructions();
  ~Instructions() {}
  std::vector<std::function<struct ret_vals>> operator[](std::string name);

  std::vector<std::tuple<string, string>> getArgs(std::string name);

 private:
  static std::unordered_map<std::string,
                            std::vector<std::function<struct ret_vals>>>
      _instructions;

  static std::unordered_map<std::string,
                            std::vector<std::tuple<std::string, std::string>>>
      arguments;
};

#endif
