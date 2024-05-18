#include <gtest/gtest.h>

#include <armadillo>
#include <cmath>
#include <complex>
#include <iostream>
#include <string>
#include <vector>

#include "../include/header/QubitClass.hh"
#include "../include/header/function.hh"

std::vector<std::complex<double>> to_vector(cx_vec in) {
  std::vector<std::complex<double>> temp;
  for (auto n : in) {
    temp.push_back(n);
  }
  return temp;
}

const double TOLERANCE = 1e-6;

std::string vector_to_string(const std::vector<std::complex<double>>& v) {
  std::string temp;
  for (auto n : v) {
    temp += std::to_string(n.real()) + " " + std::to_string(n.imag()) + " ";
  }
  return temp;
}

bool vectors_are_close(const std::vector<std::complex<double>>& v1,
                       const std::vector<std::complex<double>>& v2,
                       double tolerance) {
  if (v1.size() != v2.size()) return false;
  for (size_t i = 0; i < v1.size(); ++i) {
    if (std::abs(v1[i] - v2[i]) > tolerance) {
      return false;
    }
  }
  return true;
}

TEST(QUBIT, HADDAMARD) {
  auto q = Qbit();
  q.set({1 / sqrt(2), 1 / sqrt(2)});
  q.haddamard();
  EXPECT_EQ(q.measure(), 1) << vector_to_string(to_vector(q.get()));
}

TEST(QUBIT, PAULIX) {
  auto q = Qbit();
  q.set({1 / sqrt(2), 1 / sqrt(2)});
  auto temp = Qbit(q);
  EXPECT_EQ(to_vector(q.pauliX()->get()), to_vector(temp.get()))
      << vector_to_string(to_vector(q.pauliX()->get()));
  EXPECT_EQ(q.measure(), 0);
}

TEST(QUBIT, PAULIY) {
  auto q = Qbit({1 / sqrt(2), 1 / sqrt(2)});
  auto test =
      Qbit({std::complex(0., -1 / sqrt(2)), std::complex(0., 1 / sqrt(2))});
  EXPECT_EQ(to_vector(q.pauliY()->get()), to_vector(test.get()))
      << vector_to_string(to_vector(q.pauliY()->get()));
}

TEST(QUBIT, PAULIZ) {
  auto q = Qbit({1 / sqrt(2), 1 / sqrt(2)});
  auto temp = Qbit({1 / sqrt(2), -1 / sqrt(2)});
  EXPECT_EQ(to_vector(q.pauliZ()->get()), to_vector(temp.get()))
      << vector_to_string(to_vector(q.pauliZ()->get()));
}

TEST(QUBIT, IDENTITY) {
  auto q = Qbit({1 / sqrt(2), 1 / sqrt(2)});
  auto temp = Qbit({1 / sqrt(2), 1 / sqrt(2)});
  EXPECT_EQ(to_vector(q.identity()->get()), to_vector(temp.get()))
      << vector_to_string(to_vector(q.identity()->get()));
}

TEST(QUBIT, T) {
  auto q = Qbit({1 / sqrt(2), 1 / sqrt(2)});
  auto temp =
      Qbit({std::complex<double>(1 / sqrt(2)), std::complex<double>(0.5, 0.5)});
  EXPECT_TRUE(vectors_are_close(to_vector(q.T()->get()), to_vector(temp.get()),
                                TOLERANCE))
      << vector_to_string(to_vector(q.T()->get()));
}

TEST(QUBIT, Td) {
  auto q = Qbit({1 / sqrt(2), 1 / sqrt(2)});
  auto temp = Qbit(
      {std::complex<double>(1 / sqrt(2)), std::complex<double>(0.5, -0.5)});
  EXPECT_TRUE(vectors_are_close(to_vector(q.T_dag()->get()),
                                to_vector(temp.get()), TOLERANCE))
      << vector_to_string(to_vector(q.T_dag()->get()));
}

TEST(QUBIT, S) {
  auto q = Qbit({1 / sqrt(2), 1 / sqrt(2)});
  auto temp = Qbit({std::complex<double>(1 / sqrt(2)),
                    std::complex<double>(0., 1 / sqrt(2))});
  EXPECT_TRUE(vectors_are_close(to_vector(q.S()->get()), to_vector(temp.get()),
                                TOLERANCE))
      << vector_to_string(to_vector(q.S()->get()));
}

TEST(QUBIT, Sd) {
  auto q = Qbit({1 / sqrt(2), 1 / sqrt(2)});
  auto temp = Qbit({std::complex<double>(1 / sqrt(2)),
                    std::complex<double>(0., -1 / sqrt(2))});
  EXPECT_TRUE(vectors_are_close(to_vector(q.S_dag()->get()),
                                to_vector(temp.get()), TOLERANCE))
      << vector_to_string(to_vector(q.S_dag()->get()));
}

TEST(QUBITD, COMBINE_1) {
  auto q1 = Qbit({1 / sqrt(2), 1 / sqrt(2)});
  auto q2 = Qbit({1 / sqrt(2), 1 / sqrt(2)});
  EXPECT_NO_THROW(q1.combine(q2));
  auto temp = q1.combine(q2).get();
  EXPECT_TRUE(temp.n_elem == 4);
  cx_vec comp = {1. / 2, 1. / 2, 1. / 2, 1. / 2};
  EXPECT_TRUE(vectors_are_close(to_vector(temp), to_vector(comp), TOLERANCE))
      << vector_to_string(to_vector(temp)) << "\n"
      << vector_to_string(to_vector(comp));
}

TEST(QUBITD, COMBINE_2) {
  auto q1 = Qbit({1 / sqrt(2), 1 / sqrt(2)});
  const cx_vec q2{1 / sqrt(2), 1 / sqrt(2)};
  EXPECT_NO_THROW(q1.combine(q2));
  EXPECT_TRUE(q1.combine(q2).get().n_elem == 4);
  cx_vec comp = {1. / 2, 1. / 2, 1. / 2, 1. / 2};
  EXPECT_TRUE(vectors_are_close(to_vector(q1.combine(q2).get()),
                                to_vector(comp), TOLERANCE))
      << vector_to_string(to_vector(q1.combine(q2).get())) << "\n"
      << vector_to_string(to_vector(comp));
}

TEST(QUBITD, CNOT) {
  auto q1 = Qbit({1 / sqrt(2), 1 / sqrt(2)});
  auto q2 = Qbit({1 / sqrt(2), 1 / sqrt(2)});
  EXPECT_NO_THROW(q1.cnot(q2));
  EXPECT_TRUE(q1.cnot(q2).get().n_elem == 4);
  std::cout << vector_to_string(to_vector(q1.cnot(q2).get()));
  EXPECT_EQ(q1.cnot(q2).measure(), 1);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}