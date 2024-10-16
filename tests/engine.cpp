#include "../include/header/Engine.hh"

#include <gtest/gtest.h>

#include "gtest/gtest.h"

TEST(ENGINE, INIT) {
  EXPECT_NO_THROW(Engine("/home/bassneptun/qtest_env/tests/file.txt"));
}

TEST(ENGINE, RUN_DEATH) {
  EXPECT_NO_THROW(Engine("/home/bassneptun/qtest_env/tests/file.txt"));
  Engine tmp("/home/bassneptun/qtest_env/tests/file.txt");
  EXPECT_ANY_THROW(tmp.execute({}););
  ++tmp;
  EXPECT_ANY_THROW(tmp.execute({}););
}

TEST(ENGINE, RUN_EXCEPTION) {
  EXPECT_NO_THROW(Engine("/home/bassneptun/qtest_env/tests/file.txt"));
  Engine tmp("/home/bassneptun/qtest_env/tests/file.txt");
  Maybe::iterator it2 = tmp.get_it() + 2;
  tmp.set_it(it2);

  EXPECT_EQ(*it2, "\1");
  EXPECT_ANY_THROW(tmp.execute({}););
  EXPECT_ANY_THROW(++tmp);
  tmp.set_it(tmp.get_it() + 1);
  EXPECT_ANY_THROW(tmp.execute({}););
}

TEST(ENGINE, RUN_SUCCESFUL) {
  EXPECT_NO_THROW(Engine("/home/bassneptun/qtest_env/tests/file2.txt"););
  auto tmp = Engine("/home/bassneptun/qtest_env/tests/file2.txt");
  EXPECT_NO_THROW(tmp.execute({}););
  EXPECT_NO_THROW(++tmp;);
  EXPECT_NO_THROW(tmp.execute({}););
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
