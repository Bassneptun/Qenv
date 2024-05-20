#include <gtest/gtest.h>

#include <armadillo>
#include <cmath>
#include <complex>
#include <iostream>

#include "../include/header/QuditClass.hh"

using namespace arma;
using namespace std::complex_literals;

std::vector<std::complex<double>> to_vector(const cx_vec& in) {
  std::vector<std::complex<double>> temp;
  for (auto n : in) {
    temp.push_back(n);
  }
  return temp;
}

const double TOLERANCE = 1e-5;

std::string vector_to_string(const std::vector<std::complex<double>>& v) {
  std::string temp;
  for (const auto& n : v) {
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

TEST(L, L) {
  int d = 2;
  int d3 = d * d * d;
  arma::cx_mat Toffoli = arma::eye<arma::cx_mat>(d3, d3);
  for (int i = 0; i < d; ++i) {
    for (int j = 0; j < d; ++j) {
      for (int k = 0; k < d; ++k) {
        int idx = (i * d + j) * d + k;
        if (i == d - 1 && j == d - 1) {
          Toffoli(idx, idx) = 0;
          Toffoli(idx, (idx + 1) % d3) = 1;
        }
      }
    }
  }
  cx_mat toffoli_mat = arma::eye<cx_mat>(8, 8);
  toffoli_mat(7, 7) = 0;
  toffoli_mat(7, 6) = 1;
  toffoli_mat(6, 6) = 0;
  toffoli_mat(6, 7) = 1;
  EXPECT_TRUE(
      vectors_are_close(to_vector(Toffoli), to_vector(toffoli_mat), TOLERANCE));
  std::cout << vector_to_string(to_vector(Toffoli)) << std::endl;
}

TEST(QUDIT, INIT) {
  EXPECT_NO_THROW({
    auto q = std::make_shared<Qudit>(
        Qudit({1 / sqrt(2), 1 / sqrt(2), 1 / sqrt(2), 1 / sqrt(2)}));
  });
  auto q = std::make_shared<Qudit>(
      Qudit({1 / sqrt(2), 1 / sqrt(2), 1 / sqrt(2), 1 / sqrt(2)}));
  EXPECT_EQ(q->get().n_elem, 4);
}

TEST(QUDIT, IDENTITY) {
  auto s = Qudit({0.353553, 0.353553, 0.353553, 0.353553});
  EXPECT_EQ(s.get().n_elem, 4);
  EXPECT_NO_THROW(s.identity());
  auto temp = Qudit({0.353553, 0.353553, 0.353553, 0.353553});
  EXPECT_EQ(temp.get().n_elem, 4);
  EXPECT_TRUE(vectors_are_close(to_vector(s.identity()->get()),
                                to_vector(temp.get()), TOLERANCE))
      << vector_to_string(to_vector(s.identity()->get()));
}

TEST(QUDIT, HAD) {
  cx_vec in = {.25, .25, .25, .25};
  auto s = Qudit(in);
  EXPECT_EQ(s.get().n_elem, 4);
  EXPECT_NO_THROW(s.haddamard());
  auto temp = Qudit({1., 0., 0., 0.});
  EXPECT_EQ(temp.get().n_elem, 4);
  EXPECT_TRUE(vectors_are_close(to_vector(s.haddamard()->get()),
                                to_vector(temp.get()), TOLERANCE))
      << vector_to_string(to_vector(s.haddamard()->get()));
}

TEST(QUDIT, PAULIX) {
  auto s = Qudit({.5, .5, .5, .5});
  EXPECT_EQ(s.get().n_elem, 4);
  EXPECT_NO_THROW(s.pauliX());
  auto temp = Qudit({.5, .5, .5, .5});
  EXPECT_EQ(temp.get().n_elem, 4);
  EXPECT_TRUE(vectors_are_close(to_vector(s.pauliX()->get()),
                                to_vector(temp.get()), TOLERANCE))
      << vector_to_string(to_vector(s.pauliX()->get()));
}

/*
TEST(QUDIT, PAULIY) {
  auto s = Qudit({1 / sqrt(2), 1 / sqrt(2), 1 / sqrt(2), 1 / sqrt(2)});
  EXPECT_EQ(s.get().n_elem, 4);
  EXPECT_NO_THROW(s.pauliY());
  auto temp = Qudit({0, -1i, 1i, 0});
  EXPECT_EQ(temp.get().n_elem, 4);
  EXPECT_NO_THROW(temp.pauliY());
  EXPECT_TRUE(
      vectors_are_close(to_vector(s.get()), to_vector(temp.get()), TOLERANCE))
      << vector_to_string(to_vector(s.pauliY()->get()));
}
*/

TEST(QUDIT, PAULIZ) {
  using namespace std::complex_literals;
  auto s = Qudit({.5, .5, .5, .5});
  EXPECT_EQ(s.get().n_elem, 4);
  EXPECT_NO_THROW(s.pauliZ());
  auto temp = Qudit({.5, .5i, -.5, -.5i});
  EXPECT_EQ(temp.get().n_elem, 4);
  EXPECT_TRUE(vectors_are_close(to_vector(s.pauliZ()->get()),
                                to_vector(temp.get()), TOLERANCE))
      << vector_to_string(to_vector(s.pauliZ()->get()));
}

TEST(QUDIT, S) {
  using namespace std::complex_literals;
  auto s = Qudit({.5, .5, .5, .5});
  EXPECT_EQ(s.get().n_elem, 4);
  EXPECT_NO_THROW(s.S());
  auto temp = Qudit({.5, .5i, -.5, -.5i});
  EXPECT_EQ(temp.get().n_elem, 4);
  EXPECT_TRUE(vectors_are_close(to_vector(s.S()->get()), to_vector(temp.get()),
                                TOLERANCE))
      << vector_to_string(to_vector(s.S()->get()));
}

TEST(QUDIT, T) {
  using namespace std::complex_literals;
  auto s = Qudit({.5, .5, .5, .5});
  EXPECT_EQ(s.get().n_elem, 4);
  EXPECT_NO_THROW(s.T());
  auto temp = Qudit({.5, std::complex(sqrt(2) / 4, sqrt(2) / 4), .5i,
                     std::complex((sqrt(2) / 4) * -1, sqrt(2) / 4)});
  EXPECT_EQ(temp.get().n_elem, 4);
  EXPECT_TRUE(
      vectors_are_close(to_vector(s.T()->get()), to_vector(temp.get()), 0.01))
      << vector_to_string(to_vector(s.T()->get()));
}

TEST(QUDIT, S_DAG) {
  using namespace std::complex_literals;
  auto s = Qudit({.5, .5, .5, .5});
  EXPECT_EQ(s.get().n_elem, 4);
  EXPECT_NO_THROW(s.S_dag());
  auto temp = Qudit({.5, -.5i, -.5, .5i});
  EXPECT_EQ(temp.get().n_elem, 4);
  EXPECT_TRUE(vectors_are_close(to_vector(s.S_dag()->get()),
                                to_vector(temp.get()), TOLERANCE))
      << vector_to_string(to_vector(s.S_dag()->get()));
}

TEST(QUDIT, T_DAG) {
  auto s = Qudit({.5, .5, .5, .5});
  EXPECT_EQ(s.get().n_elem, 4);
  EXPECT_NO_THROW(s.T_dag());
  auto temp = Qudit({.5, std::complex<double>(sqrt(2) / 4, -sqrt(2) / 4), -0.5i,
                     std::complex<double>(-sqrt(2) / 4, -sqrt(2) / 4)});
  EXPECT_EQ(temp.get().n_elem, 4);
  EXPECT_NO_THROW(temp.T_dag());
  EXPECT_TRUE(vectors_are_close(to_vector(s.T_dag()->get()),
                                to_vector(temp.get()), TOLERANCE))
      << vector_to_string(to_vector(s.T_dag()->get()));
}

TEST(QUDITD, TOFFOLI) {
  auto q1 = Qudit({1 / sqrt(2), 1 / sqrt(2)});
  auto q2 = Qudit({1 / sqrt(2), 1 / sqrt(2)});
  auto q3 = Qudit({1 / sqrt(2), 1 / sqrt(2)});
  auto comp = Qudit({0.353553, 0.353553, 0.353553, 0.353553, 0.353553, 0.353553,
                     0.353553, 0.353553});
  EXPECT_NO_THROW(q1.toffoli(q2, q3));
  EXPECT_TRUE(q1.toffoli(q2, q3).get()->get().n_elem == 8);
  EXPECT_TRUE(vectors_are_close(to_vector(q1.toffoli(q2, q3).get()->get()),
                                to_vector(comp.get()), TOLERANCE))
      << vector_to_string(to_vector(q1.toffoli(q2, q3).get()->get()));
}

TEST(QUDITD, CY) {
  auto q1 = Qudit({1 / sqrt(2), 1 / sqrt(2)});
  auto q2 = Qudit({1 / sqrt(2), 1 / sqrt(2)});
  auto comp = Qudit({0.353553, 0.353553, 0.353553, 0.353553, 0.353553, 0.353553,
                     0.353553, 0.353553});
  EXPECT_NO_THROW(q1.cy(q2));
  EXPECT_TRUE(q1.cy(q2).get()->get().n_elem == 8);
  EXPECT_TRUE(vectors_are_close(to_vector(q1.cy(q2).get()->get()),
                                to_vector(comp.get()), TOLERANCE))
      << vector_to_string(to_vector(q1.cy(q2).get()->get()));
}

TEST(QUDITD, CNOT) {
  auto q1 = Qudit({1 / sqrt(2), 1 / sqrt(2)});
  auto q2 = Qudit({1 / sqrt(2), 1 / sqrt(2)});
  auto comp = Qudit({0.353553, 0.353553, 0.353553, 0.353553, 0.353553, 0.353553,
                     0.353553, 0.353553});
  EXPECT_NO_THROW(q1.cnot(q2));
  EXPECT_TRUE(q1.cnot(q2).get()->get().n_elem == 8);
  EXPECT_TRUE(vectors_are_close(to_vector(q1.cnot(q2).get()->get()),
                                to_vector(comp.get()), TOLERANCE))
      << vector_to_string(to_vector(q1.cnot(q2).get()->get()));
}

TEST(QUDITD, SWAP) {
  auto q1 = Qudit({1 / sqrt(2), 1 / sqrt(2)});
  auto q2 = Qudit({1 / sqrt(2), 1 / sqrt(2)});
  auto comp = Qudit({0.353553, 0.353553, 0.353553, 0.353553, 0.353553, 0.353553,
                     0.353553, 0.353553});
  EXPECT_NO_THROW(q1.swap(q2));
  EXPECT_TRUE(q1.swap(q2).get()->get().n_elem == 8);
  EXPECT_TRUE(vectors_are_close(to_vector(q1.swap(q2).get()->get()),
                                to_vector(comp.get()), TOLERANCE))
      << vector_to_string(to_vector(q1.swap(q2).get()->get()));
}

TEST(QUDITD, COMBINE) {
  auto q1 = Qudit({1 / sqrt(2), 1 / sqrt(2)});
  auto q2 = Qudit({1 / sqrt(2), 1 / sqrt(2)});
  auto comp = Qudit({0.353553, 0.353553, 0.353553, 0.353553, 0.353553, 0.353553,
                     0.353553, 0.353553});
  EXPECT_NO_THROW(q1.combine(q2));
  EXPECT_TRUE(q1.combine(q2).get().n_elem == 8);
  EXPECT_TRUE(vectors_are_close(to_vector(q1.combine(q2).get()),
                                to_vector(comp.get()), TOLERANCE))
      << vector_to_string(to_vector(q1.combine(q2).get()));
}

TEST(QUDITF, RX) {
  auto q1 = Qudit({1 / sqrt(2), 1 / sqrt(2)});
  auto comp = Qudit({0.353553, 0.353553, 0.353553, 0.353553, 0.353553, 0.353553,
                     0.353553, 0.353553});
  EXPECT_NO_THROW(q1.rx(0.5));
  EXPECT_TRUE(q1.rx(0.5).get()->get().n_elem == 8);
  EXPECT_TRUE(vectors_are_close(to_vector(q1.rx(0.5).get()->get()),
                                to_vector(comp.get()), TOLERANCE))
      << vector_to_string(to_vector(q1.rx(0.5).get()->get()));
}

TEST(QUDITF, RY) {
  auto q1 = Qudit({1 / sqrt(2), 1 / sqrt(2)});
  auto comp = Qudit({0.353553, 0.353553, 0.353553, 0.353553, 0.353553, 0.353553,
                     0.353553, 0.353553});
  EXPECT_NO_THROW(q1.ry(0.5));
  EXPECT_TRUE(q1.ry(0.5).get()->get().n_elem == 8);
  EXPECT_TRUE(vectors_are_close(to_vector(q1.ry(0.5).get()->get()),
                                to_vector(comp.get()), TOLERANCE))
      << vector_to_string(to_vector(q1.ry(0.5).get()->get()));
}

TEST(QUDITF, RZ) {
  auto q1 = Qudit({1 / sqrt(2), 1 / sqrt(2)});
  auto comp = Qudit({0.353553, 0.353553, 0.353553, 0.353553, 0.353553, 0.353553,
                     0.353553, 0.353553});
  EXPECT_NO_THROW(q1.rz(0.5));
  EXPECT_TRUE(q1.rz(0.5).get()->get().n_elem == 8);
  EXPECT_TRUE(vectors_are_close(to_vector(q1.rz(0.5).get()->get()),
                                to_vector(comp.get()), TOLERANCE))
      << vector_to_string(to_vector(q1.rz(0.5).get()->get()));
}

TEST(QUDITF, CR) {
  auto q1 = Qudit({1 / sqrt(2), 1 / sqrt(2)});
  auto comp = Qudit({0.353553, 0.353553, 0.353553, 0.353553, 0.353553, 0.353553,
                     0.353553, 0.353553});
  EXPECT_NO_THROW(q1.cr(0.5));
  EXPECT_TRUE(q1.cr(0.5).get()->get().n_elem == 8);
  EXPECT_TRUE(vectors_are_close(to_vector(q1.cr(0.5).get()->get()),
                                to_vector(comp.get()), TOLERANCE))
      << vector_to_string(to_vector(q1.cr(0.5).get()->get()));
}

TEST(QUDITF, CRK) {
  auto q1 = Qudit({1 / sqrt(2), 1 / sqrt(2)});
  auto comp = Qudit({0.353553, 0.353553, 0.353553, 0.353553, 0.353553, 0.353553,
                     0.353553, 0.353553});
  EXPECT_NO_THROW(q1.crk(0.5));
  EXPECT_TRUE(q1.crk(0.5).get()->get().n_elem == 8);
  EXPECT_TRUE(vectors_are_close(to_vector(q1.crk(0.5).get()->get()),
                                to_vector(comp.get()), TOLERANCE))
      << vector_to_string(to_vector(q1.crk(0.5).get()->get()));
}
