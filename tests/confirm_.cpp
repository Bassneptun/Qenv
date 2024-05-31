#include <gtest/gtest.h>

#include <armadillo>
#include <memory>
#include <vector>

#include "../include/header/Confirm.hh"
#include "../include/header/Instructions.hh"
#include "../include/header/QubitClass.hh"

TEST(CONFIRM, INIT) {
  std::vector<std::vector<Qbit>> tmp;
  vars tmp2;
  EXPECT_NO_THROW(Maybe("file.txt", std::make_shared<Instructions>(
                                        Instructions(tmp, tmp2))););
}

TEST(CONFIRM, SYNTAX_CHECK) {
  std::vector<std::vector<Qbit>> tmp;
  vars tmp2;
  EXPECT_NO_THROW(Maybe("file.txt", std::make_shared<Instructions>(
                                        Instructions(tmp, tmp2))););
  auto a = Maybe("/home/bassneptun/qtest_env/tests/file.txt",
                 std::make_shared<Instructions>(Instructions(tmp, tmp2)));
  EXPECT_NO_THROW(Maybe::iterator b = a.begin());
  Maybe::iterator b = a.begin();

  EXPECT_NE(*b, "\1");
  EXPECT_NO_THROW(++b);
}

TEST(CONFIRM, SYNTAX_CHECK_FALSE) {
  std::vector<std::vector<Qbit>> tmp;
  vars tmp2;
  EXPECT_NO_THROW(Maybe("file.txt", std::make_shared<Instructions>(
                                        Instructions(tmp, tmp2))););
  auto a = Maybe("/home/bassneptun/qtest_env/tests/file.txt",
                 std::make_shared<Instructions>(Instructions(tmp, tmp2)));
  EXPECT_NO_THROW(Maybe::iterator b = a.begin());
  Maybe::iterator b = a.begin() + 2;

  EXPECT_EQ(*b, "\1");
  EXPECT_ANY_THROW(++b);
}

TEST(MAYBE_ITERATOR, INIT) {
  std::vector<std::vector<Qbit>> tmp;
  vars tmp2;
  EXPECT_NO_THROW(Maybe("file.txt", std::make_shared<Instructions>(
                                        Instructions(tmp, tmp2))););
  auto a = Maybe("file.txt",
                 std::make_shared<Instructions>(Instructions(tmp, tmp2)));
  EXPECT_NO_THROW(Maybe::iterator b = a.begin());
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
  return 0;
}
