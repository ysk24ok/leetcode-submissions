#include <gtest/gtest.h>

#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

unordered_map<string, string> special = {
  {"&quot;", "\""},
  {"&apos;", "'"},
  {"&amp;", "&"},
  {"&gt;", ">"},
  {"&lt;", "<"},
  {"&frasl;", "/"}
};

class Solution {
 public:
  string entityParser(string text) {
    string word = "";
    ostringstream oss;
    for (size_t i = 0; i < text.size(); ++i) {
      if (text[i] == '&') {
        string cand = GetSpecial(text, i);
        if (cand.size() > 0) {
          oss << special[cand];
          i += cand.size() - 1;
          assert(text[i] == ';');
        } else {
          oss << text[i];
        }
      } else {
        oss << text[i];
      }
    }
    return oss.str();
  }

  string GetSpecial(const string& text, int start) {
    for (const auto& pair : special) {
      size_t len = pair.first.size();
      if (text.substr(start, len) == pair.first) return pair.first;
    }
    return "";
  }
};

int main() {
  Solution sol;
  string text, got, expected;

  text = "&amp; is an HTML entity but &ambassador; is not.";
  got = sol.entityParser(text);
  expected = "& is an HTML entity but &ambassador; is not.";
  EXPECT_EQ(expected, got);

  text = "A & B";
  got = sol.entityParser(text);
  expected = "A & B";
  EXPECT_EQ(expected, got);

  text = "and I quote: &quot;...&quot;";
  got = sol.entityParser(text);
  expected = "and I quote: \"...\"";
  EXPECT_EQ(expected, got);

  text = "Stay home! Practice on Leetcode :)";
  got = sol.entityParser(text);
  EXPECT_EQ(text, got);

  text = "x &gt; y &amp;&amp; x &lt; y is always false";
  got = sol.entityParser(text);
  expected = "x > y && x < y is always false";
  EXPECT_EQ(expected, got);

  text = "leetcode.com&frasl;problemset&frasl;all";
  got = sol.entityParser(text);
  expected = "leetcode.com/problemset/all";
  EXPECT_EQ(expected, got);
}
