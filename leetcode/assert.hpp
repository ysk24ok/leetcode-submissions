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
  oss << "[\n";
  for (size_t i = 0; i < m; ++i) {
    oss << "  [";
    for (size_t j = 0; j < n - 1; ++j) {
      oss << mat[i][j] << ",";
    }
    oss << mat[i][n - 1] << "],\n";
  }
  oss << "]";
  return oss.str();
}

}  // namespace LeetCode
