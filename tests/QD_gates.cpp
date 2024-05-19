#include <gtest/gtest.h>

#include <armadillo>

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

const double TOLERANCE = 1e-6;

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

TEST(QUDIT, INIT) {
  EXPECT_NO_THROW(
      { auto q = std::make_shared<Qudit>(arma::randu<arma::cx_mat>(2, 2)); });
  auto q = std::make_shared<Qudit>(arma::randu<arma::cx_mat>(2, 2));
  EXPECT_EQ(q->get().n_elem, 4);
}

TEST(QUDIT, IDENTITY) {
  auto s = Qudit({1 / sqrt(2), 1 / sqrt(2), 1 / sqrt(2), 1 / sqrt(2)});
  EXPECT_EQ(s.get().n_elem, 4);
  EXPECT_NO_THROW(s.identity());
  auto temp = Qudit({0.353553, 0.353553, 0.353553, 0.353553});
  EXPECT_EQ(temp.get().n_elem, 4);
  EXPECT_NO_THROW(temp.identity());
  EXPECT_TRUE(
      vectors_are_close(to_vector(s.get()), to_vector(temp.get()), TOLERANCE));
}

TEST(QUDIT, HAD) {
  auto s = Qudit({1 / sqrt(2), 1 / sqrt(2), 1 / sqrt(2), 1 / sqrt(2)});
  EXPECT_EQ(s.get().n_elem, 4);
  EXPECT_NO_THROW(s.haddamard());
  auto temp = Qudit({0.707107, 0.707107, 0.707107, -0.707107});
  EXPECT_EQ(temp.get().n_elem, 4);
  EXPECT_NO_THROW(temp.haddamard());
  EXPECT_TRUE(
      vectors_are_close(to_vector(s.get()), to_vector(temp.get()), TOLERANCE));
}

TEST(QUDIT, PAULIX) {
  auto s = Qudit({1 / sqrt(2), 1 / sqrt(2), 1 / sqrt(2), 1 / sqrt(2)});
  EXPECT_EQ(s.get().n_elem, 4);
  EXPECT_NO_THROW(s.pauliX());
  auto temp = Qudit({0, 1, 1, 0});
  EXPECT_EQ(temp.get().n_elem, 4);
  EXPECT_NO_THROW(temp.pauliX());
  EXPECT_TRUE(
      vectors_are_close(to_vector(s.get()), to_vector(temp.get()), TOLERANCE));
}

TEST(QUDIT, PAULIY) {
  auto s = Qudit({1 / sqrt(2), 1 / sqrt(2), 1 / sqrt(2), 1 / sqrt(2)});
  EXPECT_EQ(s.get().n_elem, 4);
  EXPECT_NO_THROW(s.pauliY());
  auto temp = Qudit({0, -1i, 1i, 0});
  EXPECT_EQ(temp.get().n_elem, 4);
  EXPECT_NO_THROW(temp.pauliY());
  EXPECT_TRUE(
      vectors_are_close(to_vector(s.get()), to_vector(temp.get()), TOLERANCE));
}

TEST(QUDIT, PAULIZ) {
  auto s = Qudit({1 / sqrt(2), 1 / sqrt(2), 1 / sqrt(2), 1 / sqrt(2)});
  EXPECT_EQ(s.get().n_elem, 4);
  EXPECT_NO_THROW(s.pauliZ());
  auto temp = Qudit({1, 0, 0, 0});
  EXPECT_EQ(temp.get().n_elem, 4);
  EXPECT_NO_THROW(temp.pauliZ());
  EXPECT_TRUE(
      vectors_are_close(to_vector(s.get()), to_vector(temp.get()), TOLERANCE));
}

TEST(QUDIT, S) {
  auto s = Qudit({1 / sqrt(2), 1 / sqrt(2), 1 / sqrt(2), 1 / sqrt(2)});
  EXPECT_EQ(s.get().n_elem, 4);
  EXPECT_NO_THROW(s.S());
  auto temp = Qudit({1, 0, 0, 0});
  EXPECT_EQ(temp.get().n_elem, 4);
  EXPECT_NO_THROW(temp.S());
  EXPECT_TRUE(
      vectors_are_close(to_vector(s.get()), to_vector(temp.get()), TOLERANCE));
}

TEST(QUDIT, T) {
  auto s = Qudit({1 / sqrt(2), 1 / sqrt(2), 1 / sqrt(2), 1 / sqrt(2)});
  EXPECT_EQ(s.get().n_elem, 4);
  EXPECT_NO_THROW(s.T());
  auto temp = Qudit({1, 0, 0, 0});
  EXPECT_EQ(temp.get().n_elem, 4);
  EXPECT_NO_THROW(temp.T());
  EXPECT_TRUE(
      vectors_are_close(to_vector(s.get()), to_vector(temp.get()), TOLERANCE));
}

TEST(QUDIT, SDAG) {
  auto s = Qudit({1 / sqrt(2), 1 / sqrt(2), 1 / sqrt(2), 1 / sqrt(2)});
  EXPECT_EQ(s.get().n_elem, 4);
  EXPECT_NO_THROW(s.S_dag());
  auto temp = Qudit({1, 0, 0, 0});
  EXPECT_EQ(temp.get().n_elem, 4);
  EXPECT_NO_THROW(temp.S_dag());
  EXPECT_TRUE(
      vectors_are_close(to_vector(s.get()), to_vector(temp.get()), TOLERANCE));
}

TEST(QUDIT, T_DAG) {
  auto s = Qudit({1 / sqrt(2), 1 / sqrt(2), 1 / sqrt(2), 1 / sqrt(2)});
  EXPECT_EQ(s.get().n_elem, 4);
  EXPECT_NO_THROW(s.T_dag());
  auto temp = Qudit({1, 0, 0, 0});
  EXPECT_EQ(temp.get().n_elem, 4);
  EXPECT_NO_THROW(temp.T_dag());
  EXPECT_TRUE(
      vectors_are_close(to_vector(s.get()), to_vector(temp.get()), TOLERANCE));
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
