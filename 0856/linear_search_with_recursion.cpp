#include <cassert>
#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  int scoreOfParentheses(string S) {
    int start = 0;
    int score = 0;
    while (start < S.size() - 1) {
      score += dfs(S, start);
      start++;
    }
    return score;
  }

  int dfs(const string& S, int& start) {
    int sum = 0;
    int score = 0;
    while (true) {
      if (S[start] == '(') {
        if (sum > 0) {
          score += dfs(S, start);
        } else {
          sum++;
        }
      } else {
        sum--;
        if (S[start-1] == '(') {
          score += 1;
        } else {
          score *= 2;
        }
      }
      assert(sum >= 0);
      if (sum == 0) break;
      start++;
    }
    return score;
  }
};

int main() {
  Solution sol;
  string S;

  S = "()";
  assert(sol.scoreOfParentheses(S) == 1);

  S = "(())";
  assert(sol.scoreOfParentheses(S) == 2);

  S = "()()";
  assert(sol.scoreOfParentheses(S) == 2);

  S = "(()(()))";
  assert(sol.scoreOfParentheses(S) == 6);

  S = "(()())";
  assert(sol.scoreOfParentheses(S) == 4);
}
