#include <gtest/gtest.h>

#include <cstdlib>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  bool closeStrings(string word1, string word2) {
    unordered_map<char, int> freq_per_char1 = countFrequencyPerCharacter(word1);
    unordered_map<char, int> freq_per_char2 = countFrequencyPerCharacter(word2);
    if (!checkFrequencyPerCharacter(freq_per_char1, freq_per_char2) ||
        !checkFrequencyPerCharacter(freq_per_char2, freq_per_char1)) {
      return false;
    }
    unordered_map<int, int> freq1 = countFrequencyPerCharacterFrequency(freq_per_char1);
    unordered_map<int, int> freq2 = countFrequencyPerCharacterFrequency(freq_per_char2);
    return checkFrequencyPerCharacterFrequency(freq1, freq2) &&
           checkFrequencyPerCharacterFrequency(freq2, freq1);
  }

  unordered_map<char, int> countFrequencyPerCharacter(const string& word) {
    unordered_map<char, int> freq;
    for (const char& c: word) {
      freq[c]++;
    }
    return freq;
  }

  unordered_map<int, int> countFrequencyPerCharacterFrequency(const unordered_map<char, int>& map) {
    unordered_map<int, int> freq;
    for (const auto& pair : map) {
      freq[pair.second]++;
    }
    return freq;
  }

  bool checkFrequencyPerCharacter(const unordered_map<char, int>& freq1,
                                  const unordered_map<char, int>& freq2) {
    if (freq1.size() != freq2.size()) { return false; }
    for (const auto& pair : freq1) {
      if (freq2.find(pair.first) == freq2.end()) { return false; }
    }
    return true;
  }

  bool checkFrequencyPerCharacterFrequency(const unordered_map<int, int>& freq1,
                                           const unordered_map<int, int>& freq2) {
    if (freq1.size() != freq2.size()) { return false; }
    for (const auto& pair : freq1) {
      if (freq2.find(pair.first) == freq2.end()) { return false; }
      if (freq2.at(pair.first) != pair.second) { return false; }
    }
    return true;
  }
};

int main() {
  Solution sol;
  string word1, word2;
  bool expected;

  word1 = "abc", word2 = "bca", expected = true;
  EXPECT_EQ(expected, sol.closeStrings(word1, word2));

  word1 = "a", word2 = "aa", expected = false;
  EXPECT_EQ(expected, sol.closeStrings(word1, word2));

  word1 = "cabbba", word2 = "abbccc", expected = true;
  EXPECT_EQ(expected, sol.closeStrings(word1, word2));

  word1 = "cabbba", word2 = "aabbss", expected = false;
  EXPECT_EQ(expected, sol.closeStrings(word1, word2));

  word1 = "uau", word2 = "ssx", expected = false;
  EXPECT_EQ(expected, sol.closeStrings(word1, word2));

  exit(EXIT_SUCCESS);
}
