#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

// time complexity: O(NlogN + N) = O(NlogN) (sorting requires O(NlogN) time)
// space complexity: O(N) (return value requires O(N) space)
class Solution {
 public:
  vector<int> deckRevealedIncreasing(vector<int>& deck) {
    vector<int> ret;
    sort(deck.begin(), deck.end(), greater<int>());
    for (auto& revealed_card : deck) {
      if (ret.size() >= 2) {
        swap(ret);
      }
      ret.insert(ret.begin(), revealed_card);
    }
    return ret;
  }

  void swap(vector<int>& ret) {
    ret.insert(ret.begin(), ret[ret.size()-1]);
    ret.pop_back();
  }
};

int main() {
  Solution sol;
  vector<int> deck;
  vector<int> got;
  vector<int> expected;

  deck = {17,13,11,2,3,5,7};
  expected = {2,13,3,11,5,17,7};
  got = sol.deckRevealedIncreasing(deck);
  assert(got == expected);

  deck = {5};
  expected = {5};
  got = sol.deckRevealedIncreasing(deck);
  assert(got == expected);
}
