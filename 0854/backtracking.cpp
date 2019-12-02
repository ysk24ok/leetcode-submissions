#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  int kSimilarity(string A, string B) {
    unordered_map<string, int> map;
    map[A] = 0;
    int ret = recursion(A, B, map, 0);
    return ret;
  }

  int recursion(const string& A, string& B, unordered_map<string, int>& map, int i) {
    if (A == B) return 0;
    if (map.find(B) != map.end()) return map[B];
    int ret = numeric_limits<int>::max();
    while (i < A.size() && A[i] == B[i]) i++;
    for (int j = i+1; j < B.size(); j++) {
      if (A[i] != B[j]) continue;
      // case where A[i] == B[j]
      swap(B, i, j);
      ret = min(recursion(A, B, map, i+1), ret);
      swap(B, i, j);
    }
    /* I was get stuck with this additional external for loop
    for (int i = idx; i < A.size()-1; i++) {
      if (A[i] == B[i]) continue;
      // case where A[i] != B[i]
      for (int j = i+1; j < B.size(); j++) {
        if (A[i] != B[j]) continue;
        // case where A[i] == B[j]
        swap(B, i, j);
        ret = min(recursion(A, B, map, i+1), ret);
        swap(B, i, j);
      }
    }
    */
    if (ret != numeric_limits<int>::max()) ret += 1;
    map[B] = ret;
    return ret;
  }

  void swap(string& s, int i, int j) {
    char tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
  }
};

int main() {
  Solution sol;
  string A, B;

  A = "ab";
  B = "ba";
  assert(sol.kSimilarity(A, B) == 1);

  A = "abc";
  B = "bca";
  assert(sol.kSimilarity(A, B) == 2);

  A = "abac";
  B = "baca";
  assert(sol.kSimilarity(A, B) == 2);

  A = "aabc";
  B = "abca";
  assert(sol.kSimilarity(A, B) == 2);

  A = "abcbca";
  B = "ababcc";
  assert(sol.kSimilarity(A, B) == 1);

  A = "abcabcabc";
  B = "aaabbbccc";
  assert(sol.kSimilarity(A, B) == 3);

  A = "abcdabcdabcd";
  B = "aaabbbcccddd";
  assert(sol.kSimilarity(A, B) == 4);

  A = "abcdeabcdeabcdeabcde";
  B = "aaaabbbbccccddddeeee";
  assert(sol.kSimilarity(A, B) == 8);

  A = "aabbccddee";
  B = "dcacbedbae";
  assert(sol.kSimilarity(A, B) == 5);
}
