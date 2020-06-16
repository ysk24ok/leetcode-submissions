#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

vector<string> Split(const string& S, char delim) {
  vector<string> strs;
  stringstream ss(S);
  string str;
  while (getline(ss, str, delim)) {
    strs.push_back(str);
  }
  if (S.size() > 0 && S[S.size()-1] == delim) { strs.push_back(""); }
  return strs;
}

class Solution {
 public:
  string validIPAddress(string IP) {
    vector<string> strs;
    if (checkIPv4(IP)) { return "IPv4"; }
    else if (checkIPv6(IP)) { return "IPv6"; }
    else { return "Neither"; }
  }

  bool checkIPv4(const string& IP) {
    vector<string> strs = Split(IP, '.');
    if (strs.size() != 4) { return false; }
    for (const auto& str : strs) {
      if (str.size() == 0 || str.size() >= 4) { return false; }
      if (str.size() > 1 && str[0] == '0') { return false; }
      int val = atoi(str.c_str());
      for (const auto& c : str) {
        if (!isdigit(c)) { return false;}
      }
      if (val < 0 || val >= 256) { return false; }
    }
    return true;
  }

  bool checkIPv6(const string& IP) {
    vector<string> strs = Split(IP, ':');
    if (strs.size() != 8) { return false; }
    for (const auto& str : strs) {
      if (str.size() == 0 || str.size() >= 5) { return false; }
      int val = atoi(str.c_str());
      for (const auto& c : str) {
        if (!isxdigit(c)) { return false;}
      }
    }
    return true;
  }
};

int main() {
  Solution sol;
  string IP, expected;

  IP = "172.16.254.1";
  expected = "IPv4";
  EXPECT_EQ(expected, sol.validIPAddress(IP));

  IP = "172.16.254.01";
  expected = "Neither";
  EXPECT_EQ(expected, sol.validIPAddress(IP));

  IP = "1e1.4.5.6";
  expected = "Neither";
  EXPECT_EQ(expected, sol.validIPAddress(IP));

  IP = "1.0.1.";
  expected = "Neither";
  EXPECT_EQ(expected, sol.validIPAddress(IP));

  IP = "2001:0db8:85a3:0:0:8A2E:0370:7334";
  expected = "IPv6";
  EXPECT_EQ(expected, sol.validIPAddress(IP));

  IP = "2001:0db8:85a3:0000:0000:8A2E:0370:7334";
  expected = "IPv6";
  EXPECT_EQ(expected, sol.validIPAddress(IP));

  IP = "02001:0db8:85a3:0000:0000:8A2E:0370:7334";
  expected = "Neither";
  EXPECT_EQ(expected, sol.validIPAddress(IP));

  IP = "2001:0db8:85a3:::8A2E:0370:7334";
  expected = "Neither";
  EXPECT_EQ(expected, sol.validIPAddress(IP));

  IP = "2001:0db8:85a3:0:0:8A2E:0370:7334:";
  expected = "Neither";
  EXPECT_EQ(expected, sol.validIPAddress(IP));

  IP = "256.256.256.256";
  expected = "Neither";
  EXPECT_EQ(expected, sol.validIPAddress(IP));

  IP = "";
  expected = "Neither";
  EXPECT_EQ(expected, sol.validIPAddress(IP));

  exit(EXIT_SUCCESS);
}
