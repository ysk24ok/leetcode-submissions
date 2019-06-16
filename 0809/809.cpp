#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int expressiveWords(string S, vector<string>& words) {
    int count = 0;
    for (const auto& W : words) {
      if (check(S, W)) {
        count++;
      }
    }
    return count;
  }

  bool check(const string& S, const string& W) {
    // W: hello
    // S: heeellooo
    int s_idx = 0;
    int w_idx = 0;
    while (true) {
      // W: helo
      //        x
      // S: heeellooo
      //             x
      if (s_idx == S.size() && w_idx == W.size()) {
        //printf("\n");
        return true;
      }
      // W: helo
      //     x
      // S: heeellooo
      //     x
      if (w_idx < W.size() && W[w_idx] == S[s_idx]) {
        //printf("w_idx: %d, s_idx: %d, w_idx++\n", w_idx, s_idx);
        w_idx++;
      }
      // W: helo
      //      x
      // S: heeellooo
      //      x
      else if (s_idx > 0 && S[s_idx] == S[s_idx+1] && s_idx < S.size() && S[s_idx] == S[s_idx-1]) {
        //printf("w_idx: %d, s_idx: %d, s_idx++\n", w_idx, s_idx);
        s_idx++;
      }
      // W: helo
      //       x
      // S: heeellooo
      //        x
      else if (!(s_idx > 1 && S[s_idx] == S[s_idx-1] && S[s_idx] == S[s_idx-2])) {
        //printf("w_idx: %d, s_idx: %d, break\n", w_idx, s_idx);
        break;
      }
      //printf("w_idx: %d, s_idx: %d, s_idx++\n", w_idx, s_idx);
      s_idx++;
    }
    //printf("\n");
    return false;
  }
};


int main() {
  Solution * sol = new Solution();
  string S = "heeellooo";
  int got;
  vector<string> words;

  words = {"hello"};
  got = sol->expressiveWords(S, words);
  assert(got == 1);

  words = {"hi"};
  got = sol->expressiveWords(S, words);
  assert(got == 0);

  words = {"helo"};
  got = sol->expressiveWords(S, words);
  assert(got == 0);

  words = {"e"};
  got = sol->expressiveWords(S, words);
  assert(got == 0);

  words = {"helllo"};
  got = sol->expressiveWords(S, words);
  assert(got == 0);
  delete sol;
}
