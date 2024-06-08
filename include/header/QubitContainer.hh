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
  QubitContainer(const std::vector<Qbit*>& qubits) : _qubits(qubits) {}
  QubitContainer& operator=(const QubitContainer&) = default;
  QubitContainer& operator=(QubitContainer&&) = default;
  ~QubitContainer() = default;

  std::vector<Qbit*>& getQubits();

  Qbit* getQubit(int index);

  Qbit* operator[](int index);

  void setQubits(const std::vector<Qbit*>& qubits);

  std::vector<Qbit*> operator[](std::string range);

  int size();

  void push_back(Qbit* qubit);

  void clear();

  void erase(int index);

  Qbit* pop_back();

  Qbit* front();

  Qbit* back();

  Qbit* at(int index);

 private:
  std::vector<Qbit*> _qubits;
};

#endif
