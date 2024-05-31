#include <gtest/gtest.h>

#include <iostream>
#include <vector>

#include "../include/header/QubitClass.hh"
#include "../include/header/func_wrapper.hh"
#include "../include/header/function.hh"

TEST(ALLOC, INIT) {
  std::cout << "0\n";
  std::vector<std::vector<Qbit>> *mem = new std::vector<std::vector<Qbit>>;
  std::cout << "0\n";
  vars *vs = new vars;
  std::cout << "0\n";
  uniform_input in;
  std::cout << "0\n";
  in.vals = {mem, 0, vs, "f"};
  std::cout << "0\n";
  EXPECT_NO_THROW(AG_functions::qalloc(in));
  std::cout << "0\n";
}

TEST(ALLOC, ACCESS) {
  std::vector<std::vector<Qbit>> *mem = new std::vector<std::vector<Qbit>>;
  vars *vs = new vars;
  uniform_input in;
  in.vals = {mem, 0, vs, "f"};
  EXPECT_NO_THROW(AG_functions::qalloc(in));

  EXPECT_NO_THROW(mem->operator[](0)[0].get().raw_print());
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
