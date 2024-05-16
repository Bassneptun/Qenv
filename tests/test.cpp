#include <gtest/gtest.h>

#include "../include/header/Engine.hh"

TEST(Engine, throws) {
  EXPECT_ANY_THROW(Engine("/home/bassneptun/qtest_env/test.txt"));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
