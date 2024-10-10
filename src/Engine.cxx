#include "../include/header/Engine.hh"
#include "../include/header/function.hh"

#include <algorithm>
#include <armadillo>
#include <cassert>
#include <iostream>
#include <regex>
#include <stdexcept>
#include <string>
#include <vector>

#include "../include/header/func_wrapper.hh"
#include "../include/header/qtils.hh"

const std::vector<std::string> non_mutative = {
    "QAL", "CPY", "DCP", "DAL", "SHW", "MES", "GET", "DMES", "DGET"};

bool contains(std::vector<std::string> a, std::string b) {
  for (auto i : a)
    if (i == b)
      return true;
  return false;
}

void Engine::execute(std::vector<std::string> args) {
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
      continue; // this shouldn't actually happen, I don't really know why it
                // does and I am fine with that as long as this prevents the
                // runtime error.
    } else if (word == "%") {
      in.vals.push_back(&cache);
    } else if (std::regex_match(word, std::regex("\\?\\d+"))) {
      in.vals.push_back(std::stoi(args[std::stoi(word.substr(1, word.size() - 1))]));
    } else if (std::regex_match(word, std::regex("\\?\\?\\d+"))) {
      in.vals.push_back((double)std::stod(args[std::stoi(word.substr(2, word.size() - 2))]));
      std::cout << "1_" << std::endl;
    } else {
      throw std::runtime_error("Syntax error on word: " + word + ".");
    }
  }

  std::cout << "1_" << std::endl;
  std::reverse(in.vals.begin(), in.vals.end());
  std::cout << "1_" << std::endl;

  bool is_mutative;
  try {
    std::string func_name = (*this->it).substr(0, (*this->it).find(" "));
    is_mutative = !contains(non_mutative, func_name);
    std::cout << func_name << std::endl;
    auto func = this->instructions[func_name];
    func(in);
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  if (is_mutative) {
    AG_functions::save_state(uniform_input{{&this->memory, &this->cache}});
  }
}

Maybe::iterator &Engine::operator++() {
  ++this->it;
  return this->it;
}

void Engine::set_it(Maybe::iterator it) { this->it = it; }

void Engine::exe(std::vector<std::string> args) {
  for (; this->it != this->bytecode.end(); ++it) {
    try {
      this->execute(args);
    } catch (const std::exception &) {
      return;
    }
  }
}

Maybe::iterator &Engine::get_it() { return this->it; }

void Engine::execute_new(std::vector<std::string> args, Maybe::iterator it) {
  auto line = *it;
  if (line == "\1")
    throw std::runtime_error("Invalid Syntax_" + (it.str().size() > 1
                                                      ? it.str()
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
      continue; // this shouldn't actually happen, I don't really know why it
                // does and I am fine with that as long as this prevents the
                // runtime error.
    } else if (word == "%") {
      in.vals.push_back(&cache);
    } else if (std::regex_match(word, std::regex("\\?\\d+"))) {
      in.vals.push_back(std::stoi(args[std::stoi(word.substr(1, word.size() - 1))]));
    } else if (std::regex_match(word, std::regex("\\?\\?\\d+"))) {
      in.vals.push_back(std::stod(args[std::stoi(word.substr(1, word.size() - 1))]));
    } else {
      throw std::runtime_error("Syntax error on word: " + word + ".");
    }
  }

  std::reverse(in.vals.begin(), in.vals.end());

  bool is_mutative;
  try {
    std::string func_name = (*it).substr(0, (*it).find(" "));
    std::cout << func_name << std::endl;
    is_mutative = !contains(non_mutative, func_name);
    auto func = this->instructions[func_name];
    func(in);
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  if (is_mutative) {
    AG_functions::save_state(uniform_input{{&this->memory, &this->cache}});
  }
}
