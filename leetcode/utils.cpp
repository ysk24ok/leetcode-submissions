#include "utils.hpp"

#include <cassert>

void assert_2dvector_equal(const std::vector<std::vector<int>>& expected,
                           const std::vector<std::vector<int>>& got) {
  assert(expected.size() == got.size());
  for (size_t i = 0; i < expected.size(); i++) {
    for (size_t j = 0; j < expected[i].size(); j++) {
      assert(expected[i][j] == got[i][j]);
    }
  }
}
