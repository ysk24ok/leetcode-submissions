#include <cassert>
#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  string reverseWords(string s) {
    if (s.size() == 0) return s;
    string reversed;
    size_t start_idx;
    size_t end_idx = s.size() - 1;
    for (size_t i = s.size() - 1; i >= 1; i--) {
      // In a word
      if (s[i-1] != ' ' and s[i] != ' ') {
        continue;
      // In an interval
      } else if (s[i-1] == ' ' and s[i] == ' ') {
        continue;
      // first char of word
      } else if (s[i-1] == ' ' and s[i] != ' ') {
        start_idx = i;
        if (reversed.size() != 0) {
          reversed += " ";
        }
        reversed += s.substr(start_idx, end_idx - start_idx + 1);
      // last char of word
      } else if (s[i-1] != ' ' and s[i] == ' ') {
        end_idx = i-1;
      }
    }
    if (s[0] != ' ') {
      if (reversed.size() != 0) {
        reversed += " ";
      }
      reversed += s.substr(0, end_idx + 1);
    }
    return reversed;
  }
};

int main() {
  Solution sol;
  string s;
  s = "the sky is blue";
  assert(sol.reverseWords(s) == "blue is sky the");
  s = "  hello world!  ";
  assert(sol.reverseWords(s) == "world! hello");
  s = "a good   example";
  assert(sol.reverseWords(s) == "example good a");
  s = "   good   ";
  assert(sol.reverseWords(s) == "good");
  s = "a";
  assert(sol.reverseWords(s) == "a");
  s = "";
  assert(sol.reverseWords(s) == "");
}
