#include "../include/header/Engine.hh"

#include <algorithm>
#include <iostream>
#include <regex>
#include <stdexcept>
#include <string>

#include "../include/header/func_wrapper.hh"
#include "../include/header/qtils.hh"

void Engine::execute() {
  auto line = *this->it;
  auto words = Qtils::split(line, " ");
  uniform_input in;

  words = Qtils::filter(words);
  std::reverse(words.begin(), words.end());
  for (auto word : words) {
    if (std::regex_match(word, std::regex("$\\w+"))) {
      in.vals.push_back(this->memory[this->variables.at(word).first]
                                    [this->variables.at(word).second]);
    } else if (std::regex_match(word, std::regex("\\d+"))) {
      in.vals.push_back(std::stoi(word));
    } else if (std::regex_match(word, std::regex("\"\\w+\""))) {
      in.vals.push_back(word);
    } else {
      throw std::runtime_error("Syntax error on word: " + word);
    }
  }

  std::reverse(in.vals.begin(), in.vals.end());

  try {
    auto func = this->instructions[words[0]];
    func(in);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}

Maybe::iterator& Engine::operator++() {
  ++this->it;
  return this->it;
}
