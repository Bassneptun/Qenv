#include "../include/header/Engine.hh"

#include <algorithm>
#include <armadillo>
#include <cassert>
#include <iostream>
#include <regex>
#include <stdexcept>
#include <string>

#include "../include/header/func_wrapper.hh"
#include "../include/header/qtils.hh"

void Engine::execute() {
  auto line = *this->it;
  if (line == "\1")
    throw std::runtime_error("Invalid Syntax_" + (this->it.str().size() > 1
                                                      ? this->it.str()
                                                      : "Empty Line"));
  line = line.substr(line.find(" ") + 1, line.size() - line.find(" ") - 1);
  auto words = Qtils::split(line, " ");
  uniform_input in;

  words = Qtils::filter(words);
  std::reverse(words.begin(), words.end());
  for (auto word : words) {
    if (std::regex_match(word, std::regex("\\$\\w+"))) {
      in.vals.push_back(
          &this->memory
               [this->variables.at(word.substr(1, word.size() - 1)).first]
               [this->variables.at(word.substr(1, word.size() - 1)).second]);
    } else if (std::regex_match(word, std::regex("\\d+"))) {
      in.vals.push_back(std::stoi(word));
    } else if (std::regex_match(word, std::regex("\"\\w+\""))) {
      in.vals.push_back(word.substr(1, words.size() - 3));
    } else if (std::regex_match(word, std::regex("%\\w+"))) {
      in.vals.push_back(
          &this->cache[this->dvariables[word.substr(1, word.size() - 2)]]);
    } else if (word == "&") {
      in.vals.push_back(&this->memory);
    } else if (word == "#") {
      in.vals.push_back(&this->dvariables);
    } else if (word == "$") {
      in.vals.push_back(&this->variables);
    } else if (word == "") {
      continue;  // this shouldn't actually happen, I don't really know why it
                 // does and I am fine with that as long as this prevents the
                 // runtime error.
    } else if (word == "%") {
      in.vals.push_back(&cache);
    } else {
      throw std::runtime_error("Syntax error on word: " + word + ".");
    }
  }

  std::reverse(in.vals.begin(), in.vals.end());

  try {
    auto func =
        this->instructions[(*this->it).substr(0, (*this->it).find(" "))];
    func(in);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}

Maybe::iterator& Engine::operator++() {
  ++this->it;
  return this->it;
}

void Engine::set_it(Maybe::iterator it) { this->it = it; }

void Engine::exe() {
  for (; this->it != this->bytecode.end(); ++it) {
    this->execute();
  }
}

Maybe::iterator& Engine::get_it() { return this->it; }
