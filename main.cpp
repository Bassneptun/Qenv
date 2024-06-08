#include <string>

#include "include/header/Engine.hh"

int main(int argc, char *argv[]) {
  std::string path = argv[1];
  Engine tmp(path);
  tmp.exe();
  return 0;
}
