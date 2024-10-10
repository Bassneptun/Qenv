#ifndef ENGINE_HH
#define ENGINE_HH

#include <cstdint>
#include <memory>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "Confirm.hh"
#include "Instructions.hh"
#include "QubitClass.hh"

extern const std::vector<std::string> non_mutative;

class Engine {
 public:
  Engine(std::string path)
      : instructions(this->memory, this->variables),
        bytecode(path, std::make_shared<Instructions>(this->instructions)),
        it(bytecode.begin()) {}
  ~Engine() {}

  void execute(std::vector<std::string>);
  Maybe::iterator& operator++();

  void set_it(Maybe::iterator);

  Maybe::iterator& get_it();

  void exe(std::vector<std::string>);
  void execute_new(std::vector<std::string>, Maybe::iterator it);

 public:
  Instructions instructions;

  Maybe bytecode;
  Maybe::iterator it;

  std::unordered_map<std::string, std::pair<uint8_t, size_t>>
      variables;  // map variable names to place and index
  std::unordered_map<std::string, size_t> dvariables;

  std::vector<std::vector<Qbit>> memory;
  std::vector<Qudit> cache;
};

#endif
