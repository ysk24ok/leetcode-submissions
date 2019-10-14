#include <cassert>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int balancedStringSplit(string s) {
    vector<string> answer;
    string substr = "";
    int num_L = 0;
    int num_R = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'L') {
        num_L += 1;
      } else {
        num_R += 1;
      }
      substr += s[i];
      if (num_L == num_R) {
        answer.push_back(substr);
        num_L = 0;
        num_R = 0;
      }
    }
    return answer.size();
  }
};

int main() {
  Solution sol;
  string s;

  s = "RLRRLLRLRL";
  assert(sol.balancedStringSplit(s) == 4);

  s = "RLLLLRRRLR";
  assert(sol.balancedStringSplit(s) == 3);

  s = "LLLLRRRR";
  assert(sol.balancedStringSplit(s) == 1);

  s = "L";
  assert(sol.balancedStringSplit(s) == 0);

  s = "";
  assert(sol.balancedStringSplit(s) == 0);
}
