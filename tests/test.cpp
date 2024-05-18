#include <gtest/gtest.h>

#include "../include/header/Engine.hh"

TEST(Engine, throws) {
  EXPECT_NO_FATAL_FAILURE(Engine temp("/home/bassneptun/qtest_env/test.txt");
                          temp.execute(););
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
