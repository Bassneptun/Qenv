#include <gtest/gtest.h>

#include <armadillo>
#include <cmath>

#include "../include/header/qtils.hh"

arma::cx_mat generateGeneralizedX(int d, double theta) {
  using namespace std::complex_literals;
  arma::cx_mat X_d = arma::zeros<arma::cx_mat>(d, d);

  for (int i = 0; i < d; ++i) {
    int next = (i + 1) % d;
    X_d(next, i) = 1.0;  // |next><i|
  }

  X_d = cos(theta / 2) * arma::eye<arma::cx_mat>(d, d) -
        1i * sin(theta / 2) * X_d;
  return X_d;
}

arma::cx_mat generateRXGateQudit(int d, double theta) {
  using namespace std::complex_literals;
  arma::cx_mat RX = arma::eye<arma::cx_mat>(d, d);
  for (int i = 0; i < d - 1; i += 2) {
    std::complex<double> cosTheta = std::cos(theta / 2);
    std::complex<double> sinTheta = -1i * std::sin(theta / 2);
    RX(i, i) = cosTheta;
    RX(i, i + 1) = sinTheta;
    RX(i + 1, i) = sinTheta;
    RX(i + 1, i + 1) = cosTheta;
  }
  if (d % 2 != 0) {
    RX(d - 1, d - 1) = 1;
  }
  return RX;
}

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

TEST(OPERATORS, PAULIX) {
  cx_mat temp = Qtils::homo_pauliX_operator(2);
  EXPECT_EQ(temp.size(), 4);
  temp.print();
}

// works
TEST(OPERATORS, RX2) {
  cx_mat temp = generateGeneralizedX(3, 1);
  EXPECT_EQ(temp.size(), 9);
  temp.print();
}

// Doesn't work
TEST(OPERATORS, RX) {
  cx_mat temp = generateRXGateQudit(3, 1);
  EXPECT_EQ(temp.size(), 9);
  temp.print();
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
