#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

using namespace std;

class Iterator {
 public:
  struct Data;
  Data* data;
  Iterator(const vector<int>& nums) : nums_(nums), idx_(0) {}
  Iterator(const Iterator& iter);

  // Returns the next element in the iteration.
  int next() {
    int ret = nums_[idx_++];
    return ret;
  }

  // Returns true if the iteration has more elements.
  bool hasNext() const {
    return idx_ < nums_.size();
  }

 private:
  const vector<int> nums_;
  size_t idx_;
};

class PeekingIterator : public Iterator {
 public:
  PeekingIterator(const vector<int>& nums) : Iterator(nums), iter_(Iterator(nums)), next_(0), has_next_(false) {
    // Initialize any member here.
    // **DO NOT** save a copy of nums and manipulate it directly.
    // You should only use the Iterator interface methods.
    if (iter_.hasNext()) {
      next_ = iter_.next();
      has_next_ = true;
    }
  }

  // Returns the next element in the iteration without advancing the iterator.
  int peek() {
    return next_;
  }

  // hasNext() and next() should behave the same as in the Iterator interface.
  // Override them if needed.
  int next() {
    int ret = next_;
    if (iter_.hasNext()) {
      next_ = iter_.next();
    } else {
      has_next_ = false;
    }
    return ret;
  }

  bool hasNext() const {
    return has_next_;
  }

 private:
  Iterator iter_;
  int next_;
  bool has_next_;
};

int main() {
  PeekingIterator iterator1({1, 2, 3});
  EXPECT_EQ(1, iterator1.peek());
  EXPECT_EQ(1, iterator1.peek());
  EXPECT_EQ(1, iterator1.next());
  EXPECT_EQ(2, iterator1.peek());
  EXPECT_EQ(2, iterator1.peek());
  EXPECT_EQ(2, iterator1.next());
  EXPECT_EQ(3, iterator1.next());
  EXPECT_FALSE(iterator1.hasNext());

  exit(EXIT_SUCCESS);
}
