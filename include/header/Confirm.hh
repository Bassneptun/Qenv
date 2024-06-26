#ifndef CONFIRM_HH
#define CONFIRM_HH

#include <memory>
#include <string>
#include <vector>

#include "Instructions.hh"

using std::string;

string operator*(string, int);

class Maybe {
 public:
  Maybe(string path, std::shared_ptr<Instructions> instructions);
  ~Maybe() {}
  std::string operator[](int);
  std::vector<string> operator()();

  class iterator {
   public:
    iterator(Maybe* p, bool isEnd = false);
    ~iterator() {}

    std::string str() const noexcept;
    std::string operator*();
    iterator& operator++();
    iterator& operator=(const iterator& other);
    iterator& operator+(const int);

    std::vector<string>::iterator get();
    bool operator!=(const iterator& other);

   private:
    Maybe* p;
    std::vector<string>::iterator it;
  };

  iterator begin();
  iterator end();

  bool syntax_check(size_t index = 0);
  // bool typecheck(size_t index = 0);

 private:
  std::vector<string> bytecode;
  std::shared_ptr<Instructions> instructions;
};

#endif
