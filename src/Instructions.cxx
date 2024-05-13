#include "../include/header/Instructions.hh"

#include <functional>
#include <vector>

std::vector<std::function<struct ret_vals>> Instructions::operator[](
    std::string name) {
  return this->_instructions[name];
}

std::vector<std::tuple<std::string, std::string>> Instructions::getArgs(
    std::string name) {
  return this->arguments[name];
}

std::unordered_map<std::string, std::vector<std::function<>>>
    Instructions::_instructions = {
        {"HADD", {std::bind(&Qbit::haddamard, std::placeholders::_1)}},
};
