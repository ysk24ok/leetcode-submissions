#include <gtest/gtest.h>

#include <string>

using namespace std;

class Solution {
 public:
  string complexNumberMultiply(string num1, string num2) {
    pair<int, int> p1 = parse(num1);
    pair<int, int> p2 = parse(num2);
    int real = p1.first * p2.first - p1.second * p2.second;
    int imaginary = p1.first * p2.second + p1.second * p2.first;
    return to_string(real) + "+" + to_string(imaginary) + "i";
  }
  
  pair<int, int> parse(const string& num) {
    size_t n = num.size();
    size_t i;
    for (i = 0; i < n; ++i) {
      if (num[i] == '+') {
        break;
      }
    }
    int real = stoi(num.substr(0, i));
    int imaginary = stoi(num.substr(i + 1, n - 1 - (i + 1)));
    return {real, imaginary};
  }
};

int main() {
  Solution sol;
  string num1, num2, expected;

  num1 = "1+1i", num2 = "1+1i", expected = "0+2i";
  EXPECT_EQ(expected, sol.complexNumberMultiply(num1, num2));

  num1 = "1+-1i", num2 = "1+-1i", expected = "0+-2i";
  EXPECT_EQ(expected, sol.complexNumberMultiply(num1, num2));

  num1 = "1+-1i", num2 = "0+0i", expected = "0+0i";
  EXPECT_EQ(expected, sol.complexNumberMultiply(num1, num2));

  exit(EXIT_SUCCESS);
}
