#include <gtest/gtest.h>

#include "../include/header/qtils.hh"

TEST(SPLIT, normal) {
  std::vector<std::string> result = Qtils::split("a,b,c", ",");
  EXPECT_EQ(result.size(), 3);
  EXPECT_EQ(result[0], "a");
  EXPECT_EQ(result[1], "b");
  EXPECT_EQ(result[2], "c");
}

TEST(SPLIT, empty) {
  std::vector<std::string> result = Qtils::split("", ",");
  EXPECT_EQ(result.size(), 1);
}

TEST(SPLIT, space) {
  std::vector<std::string> result = Qtils::split("a, b, c", ",");
  EXPECT_EQ(result.size(), 3);
  EXPECT_EQ(result[0], "a");
  EXPECT_EQ(result[1], " b");
  EXPECT_EQ(result[2], " c");
}

TEST(READ, normal) {
  std::vector<std::string> result = Qtils::getInput("../test.txt");
  EXPECT_EQ(result.size(), 1);
  EXPECT_EQ(result[0], "HAD $f");
}

TEST(READ, none) {
  std::vector<std::string> result = Qtils::getInput("tests/empty.txt");
  EXPECT_EQ(result.size(), 0);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
