#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  bool hasGroupsSizeX(vector<int>& deck) {
    unordered_map<int, int> map;
    for (const int& card : deck) {
      if (map.find(card) == map.end()) map[card] = 0;
      map[card]++;
    }
    int picked = deck[0];
    int picked_cards_count = map[picked];
    int ret = picked_cards_count;
    for (const auto& pair : map) {
      if (pair.first == picked) continue;
      ret = gcd(ret, pair.second);
    }
    return ret >= 2;
  }

  int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
  }
};

int main() {
  Solution sol;
  vector<int> deck;

  deck = {1,2,3,4,4,3,2,1};
  assert(sol.hasGroupsSizeX(deck));

  deck = {1,1,1,2,2,2,3,3};
  assert(!sol.hasGroupsSizeX(deck));

  deck = {1};
  assert(!sol.hasGroupsSizeX(deck));

  deck = {1,1};
  assert(sol.hasGroupsSizeX(deck));

  deck = {1,1,2,2,2,2};
  assert(sol.hasGroupsSizeX(deck));

  deck = {1,1,1,1,2,2};
  assert(sol.hasGroupsSizeX(deck));

  deck = {1,1,1,1,2,2,2,2,3,3};
  assert(sol.hasGroupsSizeX(deck));
}
