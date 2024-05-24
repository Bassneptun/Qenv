#include "../include/header/Engine.hh"

#include <gtest/gtest.h>

TEST(ENGINE, INIT) {
  EXPECT_NO_THROW(Engine("/home/bassneptun/qtest_env/tests/file.txt"));
}

TEST(ENGINE, RUN_WORKS) {
  EXPECT_NO_THROW(Engine("/home/bassneptun/qtest_env/tests/file.txt"));
  Engine tmp("/home/bassneptun/qtest_env/tests/file.txt");
  EXPECT_NO_THROW(tmp.execute(););
  EXPECT_NO_THROW(++tmp;);
  EXPECT_NO_THROW(tmp.execute(););
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
