#include <iostream>
#include <string>
#include <sstream>
#include <vector>

namespace LeetCode {

template <typename T>
std::string Vector2String(const std::vector<T> vec) {
  std::ostringstream oss;
  oss << "[";
  for (size_t i = 0; i < vec.size() - 1; ++i) {
    oss << vec[i] << ",";
  }
  oss << vec[vec.size() - 1] << "]";
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

}  // namespace LeetCode
