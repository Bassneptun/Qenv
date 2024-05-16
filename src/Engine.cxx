#include "../include/header/Engine.hh"

#include <armadillo>
#include <regex>

#include "../include/header/func_wrapper.hh"
#include "../include/header/qtils.hh"

void Engine::execute() {
  auto line = *this->it;
  auto words = Qtils::split(line, " ");
  uniform_input in;

  reverse(words.begin(), words.end());
  for (auto word : words) {
    if (std::regex_match(word, std::regex("$\\w+"))) {
      if (this->variables.at(word).first == 0) {
        in.vals.push_back(this->registers[this->variables.at(word).second]);
      } else if (this->variables.at(word).first == 1) {
        in.vals.push_back(this->stack[this->variables.at(word).second]);
      } else if (this->variables.at(word).first == 2) {
        in.vals.push_back(this->heap[this->variables.at(word).second]);
      } else if (this->variables.at(word).first == 3) {
        in.vals.push_back(this->globals[this->variables.at(word).second]);
      }
    }
  }

  try {
    auto func = this->instructions[words[0]];
    func(in);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}
