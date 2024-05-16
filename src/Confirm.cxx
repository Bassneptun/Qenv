#include "../include/header/Confirm.hh"

#include <algorithm>
#include <iterator>
#include <memory>
#include <regex>
#include <stdexcept>
#include <string>
#include <vector>

#include "../include/header/Instructions.hh"
#include "../include/header/qtils.hh"

using std::string;

template <class Engine>
Maybe<Engine>::Maybe(string path,
                     std::shared_ptr<Instructions<Engine>> instructions)
    : bytecode(Qtils::getInput(path)), instructions(instructions) {}

template <class Engine>
std::string Maybe<Engine>::operator[](int index) {
  if (index >= bytecode.size()) {
    throw std::out_of_range("Index out of range");
  }
  return bytecode[index];
}

template <class Engine>
std::vector<string> Maybe<Engine>::operator()() {
  return bytecode;
}

template <class Engine>
Maybe<Engine>::iterator::iterator(Maybe* p, bool isEnd)
    : p(p), it(isEnd ? p->bytecode.end() : p->bytecode.begin()) {}

template <class Engine>
std::string Maybe<Engine>::iterator::operator*() {
  return (this->p->syntx_check(std::distance(p->bytecode.begin(), it))) ? *it
                                                                        : "\1";
}

template <class Engine>
typename Maybe<Engine>::iterator& Maybe<Engine>::iterator::operator++() {
  if (it == p->bytecode.end()) {
    throw std::out_of_range("Index out of range");
  }
  if (!this->p->syntx_check(std::distance(p->bytecode.begin(), it) + 1)) {
    throw std::runtime_error("Syntax error");
  }
  it++;
  return *this;
}

template <class Engine>
typename Maybe<Engine>::iterator Maybe<Engine>::begin() {
  return iterator(this);
}

template <class Engine>
typename Maybe<Engine>::iterator Maybe<Engine>::end() {
  return iterator(this, true);
}

/*
bool Maybe::confirm() {
  for (size_t i = 0; i < bytecode.size(); i++) {
    if (!std::regex_match(
            bytecode[i],
            std::regex(
                string("\\w+ ") +
                string("($\\w+)|\\d+") *
                    this->instructions->getArgs(bytecode[i].substr(
                        0, std::distance(std::find(bytecode[i].begin(),
                                                   bytecode[i].end(), ' '),
                                         bytecode[i].end()))).size()))) {

      return false;
    }
  }
  return true;
}
*/

template <class Engine>
bool Maybe<Engine>::syntx_check(size_t i) {
  const auto& code = this->bytecode[i];
  auto firstSpacePos = std::find(code.begin(), code.end(), ' ');
  std::string operation(code.begin(), firstSpacePos);

  size_t numArgs = this->instructions->getArgs(operation).size();

  std::string pattern = "\\w+ (\\$\\w+|\\d+){" + std::to_string(numArgs) + "}";

  if (!std::regex_match(code, std::regex(pattern))) {
    return false;
  }
  return true;
}

/*
bool Maybe::typecheck(size_t i) {
  const auto& code = this->bytecode[i];
  auto all_arguments =
      this->instructions->getArgs(code.substr(0, code.find(' ')));
  auto arguments = all_argume
}
*/
