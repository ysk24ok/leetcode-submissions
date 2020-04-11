#include <vector>

template <typename T>
void assert_vector_equal(const std::vector<T>& expected,
                         const std::vector<T>& actual) {
  assert(expected.size() == actual.size());
  for (size_t i = 0; i < expected.size(); ++i) {
    assert(expected[i] == actual[i]);
  }
}

void assert_2dvector_equal(const std::vector<std::vector<int>>& expected,
                           const std::vector<std::vector<int>>& got);
