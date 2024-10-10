#include <string>
#include <vector>

#include "include/header/Engine.hh"

int main(int argc, char *argv[]) {
  std::string path = argv[1];
  Engine tmp(path);
  std::vector<std::string> res;
  if(argc > 2){
    res = std::vector<std::string>(argv + 2, argv + argc);
  } else {
    res = {};
  }
  tmp.exe(res);
  for (auto i: tmp.memory){
    for (auto j: i){
      j.getValues()->print();
    }
  }
  return 0;
}
