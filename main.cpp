#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "header/qtils.hh"
#include "include/header/Engine.hh"

int main(int argc, char *argv[]) {
  std::string path = argv[1];
  Engine tmp(path);
  std::vector<std::string> res;
  std::stringstream buff;
  std::cout << "enter your constants just now, \njust be reminded that piping "
               "is the intended purpose of this.\nexiting with ctrl+d\n on "
               "unix systems, otherwise ctrl+z\n";
  buff << std::cin.rdbuf();
  std::string s = buff.str();
  auto tmp2 = Qtils::split(s, "\n");
  for (auto w : tmp2) {
    for (auto w2 : Qtils::split(w, " ")) {
      res.push_back(w2);
    }
  }

  tmp.exe(res);

  return 0;
}
