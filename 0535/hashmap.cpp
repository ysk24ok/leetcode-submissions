#include <gtest/gtest.h>

#include <cstdlib>
#include <random>
#include <string>
#include <unordered_map>

using namespace std;

constexpr size_t kCodeSize = 6;
const string ascii_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

class Solution {
 public:
  Solution() : device_(), engine_(device_()), longUrl2code_(), code2longUrl_() {}

  // Encodes a URL to a shortened URL.
  string encode(string longUrl) {
    string code;
    while (longUrl2code_.find(longUrl) == longUrl2code_.end()) {
      code = "";
      for (size_t i = 0; i < kCodeSize; ++i) {
        code += ascii_chars[engine_() % ascii_chars.size()];
        longUrl2code_[longUrl] = code;
        code2longUrl_[code] = longUrl;
      }
    }
    return "http://tinyurl.com/" + code;
  }

  // Decodes a shortened URL to its original URL.
  string decode(string shortUrl) {
    string code = shortUrl.substr(shortUrl.size() - kCodeSize);
    return code2longUrl_[code];
  }

 private:
  random_device device_;
  mt19937 engine_;
  unordered_map<string, string> longUrl2code_;
  unordered_map<string, string> code2longUrl_;
};

int main() {
  Solution sol;
  string longUrl, shortUrl;

  longUrl = "https://leetcode.com/problems/design-tinyurl";
  shortUrl = sol.encode(longUrl);
  EXPECT_EQ(longUrl, sol.decode(shortUrl));

  exit(EXIT_SUCCESS);
}
