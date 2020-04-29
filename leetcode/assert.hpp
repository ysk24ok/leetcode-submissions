#include <iostream>
#include <string>
#include <sstream>
#include <vector>

namespace LeetCode {

template <typename T>
std::string Vector2String(const std::vector<T>& vec) {
  std::ostringstream oss;
  size_t m = vec.size();
  if (m == 0) { return "[]"; }
  oss << "[";
  for (size_t i = 0; i < m - 1; ++i) {
    oss << vec[i] << ",";
  }
  oss << vec[m - 1] << "]";
  return oss.str();
}

template<typename T>
std::string Matrix2String(const std::vector<std::vector<T>>& mat) {
  std::ostringstream oss;
  size_t m = mat.size();
  if (m == 0) { return "[]"; }
  size_t n = mat[0].size();
  oss << "[";
  for (size_t i = 0; i < m; ++i) {
    oss << "[";
    for (size_t j = 0; j < n - 1; ++j) {
      oss << mat[i][j] << ",";
    }
    oss << mat[i][n - 1] << "]";
  }
  oss << "]";
  return oss.str();
}

template <typename T>
bool ExpectEqual(const T& expected, const T& actual) {
  if (expected == actual) return true;
  else {
    std::cerr << "ExpectEqual failed, expected: " << expected
              << ", actual: " << actual << std::endl;
    return false;
  }
}

template <typename T>
bool ExpectVectorEqual(const std::vector<T>& expected,
                       const std::vector<T>& actual) {
  if (expected.size() != actual.size()) {
    std::cerr << "ExpectVectorEqual failed, expected size: " << expected.size()
              << ", actual size: " << actual.size()
              << ", actual vector: " << Vector2String(actual) << std::endl;
    return false;
  }
  bool ret = true;
  for (size_t i = 0; i < expected.size(); ++i) {
    if (expected[i] != actual[i]) { ret = false; }
  }
  if (!ret) {
    std::cerr << "ExpectVectorEqual failed, expected: " << Vector2String(expected)
              << ", actual: " << Vector2String(actual) << std::endl;
  }
  return ret;
}

template <typename T>
bool ExpectVectorUnorderedEqual(const std::vector<T>& expected,
                                const std::vector<T>& actual) {
  if (expected.size() != actual.size()) {
    std::cerr << "ExpectVectorUnorderedEqual failed, expected size: " << expected.size()
              << ", actual size: " << actual.size()
              << ", actual vector: " << Vector2String(actual) << std::endl;
    return false;
  }
  bool ret = true;
  for (const T& val : expected) {
    if (std::find(actual.begin(), actual.end(), val) == actual.end()) { ret = false; }
  }
  if (!ret) {
    std::cerr << "ExpectVectorUnorderedEqual failed, expected: " << Vector2String(expected)
              << ", actual: " << Vector2String(actual) << std::endl;
  }
  return ret;
}

template <typename T>
bool ExpectMatrixEqual(const std::vector<std::vector<T>>& expected,
                         const std::vector<std::vector<T>>& actual) {
  if (expected.size() != actual.size()) {
    std::cerr << "ExpectMatrixEqual failed, expected size: " << expected.size()
              << ", actual size: " << actual.size()
              << ", actual vector: " << Matrix2String(actual) << std::endl;
    return false;
  }
  bool ret = true;
  for (size_t i = 0; i < expected.size(); ++i) {
    for (size_t j = 0; j < expected[i].size(); ++j) {
      if (expected[i][j] != actual[i][j]) { ret = false; }
    }
  }
  if (!ret) {
    std::cerr << "ExpectMatrixEqual failed, expected: " << Matrix2String(expected)
              << ", actual: " << Matrix2String(actual) << std::endl;
  }
  return ret;
}

}  // namespace LeetCode
