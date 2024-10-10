#include "../include/header/QubitContainer.hh"

#include <vector>

std::vector<Qbit *> &QubitContainer::getQubits() { return _qubits; }

Qbit *QubitContainer::getQubit(int index) { return _qubits[index]; }

Qbit *QubitContainer::operator[](int index) { return _qubits[index]; }

void QubitContainer::setQubits(const std::vector<Qbit *> &qubits) {
  _qubits = qubits;
}

std::vector<Qbit *> QubitContainer::operator[](std::string range) {
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
  return std::vector<Qbit *>(this->_qubits.begin() + start,
                             this->_qubits.begin() + end);
}

void QubitContainer::erase(int index) {
  _qubits.erase(_qubits.begin() + index);
}

void QubitContainer::clear() { _qubits.clear(); }

int QubitContainer::size() { return _qubits.size(); }

void QubitContainer::push_back(Qbit *qubit) { _qubits.push_back(qubit); }

Qbit *QubitContainer::pop_back() {
  Qbit *qubit = _qubits.back();
  _qubits.pop_back();
  return qubit;
}

Qbit *QubitContainer::back() { return _qubits.back(); }

Qbit *QubitContainer::front() { return _qubits.front(); }

Qbit *QubitContainer::at(int index) { return _qubits.at(index); }
