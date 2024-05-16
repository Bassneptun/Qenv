#ifndef QUBITCONTAINER_HH
#define QUBITCONTAINER_HH

#include <regex>
#include <string>

#include "/home/bassneptun/General-Purpose-Interpreter/include/header/enumerate.hh"
#include "QubitClass.hh"

class QubitContainer {
 public:
  QubitContainer() = default;
  QubitContainer(const QubitContainer&) = default;
  QubitContainer(QubitContainer&&) = default;
  QubitContainer(const std::vector<std::shared_ptr<Qbit>>& qubits)
      : _qubits(qubits) {}
  QubitContainer& operator=(const QubitContainer&) = default;
  QubitContainer& operator=(QubitContainer&&) = default;
  ~QubitContainer() = default;

  std::vector<std::shared_ptr<Qbit>>& getQubits() { return _qubits; }

  std::shared_ptr<Qbit> getQubit(int index) { return _qubits[index]; }

  std::shared_ptr<Qbit> operator[](int index) { return _qubits[index]; }

  void setQubits(const std::vector<std::shared_ptr<Qbit>>& qubits) {
    _qubits = qubits;
  }

  std::vector<std::shared_ptr<Qbit>> operator[](std::string range) {
    int start = 0, end = 0;
    bool hold = false;
    for (auto [i, ch] : Enumerate(range)) {
      if (std::regex_match(std::string(1, ch), std::regex("\\d+")) && !hold) {
        if (i == 0)
          start = std::stoi(std::string(1, ch));
        else
          end = std::stoi(std::string(1, ch));
      } else if (std::regex_match(std::string(1, ch), std::regex(":"))) {
        if (i == range.size() - 1)
          end = this->size();
        else
          hold = true;
      } else if (std::regex_match(std::string(1, ch), std::regex("\\d+")) &&
                 hold) {
        end = std::stoi(std::string(1, ch));
        hold = false;
      } else {
        throw std::runtime_error("Syntax error");
      }
    }
    return std::vector<std::shared_ptr<Qbit>>(this->_qubits.begin() + start,
                                              this->_qubits.begin() + end);
  }

  int size() { return _qubits.size(); }

  void push_back(std::shared_ptr<Qbit> qubit) { _qubits.push_back(qubit); }

  void clear() { _qubits.clear(); }

  void erase(int index) { _qubits.erase(_qubits.begin() + index); }

  std::shared_ptr<Qbit> pop_back() { return _qubits.back(); }

  std::shared_ptr<Qbit> front() { return _qubits.front(); }

  std::shared_ptr<Qbit> back() { return _qubits.back(); }

  std::shared_ptr<Qbit> at(int index) { return _qubits.at(index); }

 private:
  std::vector<std::shared_ptr<Qbit>> _qubits;
};

#endif
