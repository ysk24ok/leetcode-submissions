#include <gtest/gtest.h>

#include <cstdlib>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Say M is the length of each word and N is the size of `wordList`.
// time complexity: O(M^2 * N)
class Solution {
 public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    queue<pair<string, int>> q;
    unordered_map<string, bool> visited;
    for (const string& word : wordList) {
      visited[word] = false;
    }
    q.push({beginWord, 1});
    while (!q.empty()) {
      pair<string, int> p = q.front();
      q.pop();
      string& currWord = p.first;
      int count = p.second;
      // O(M ^ 2)
      for (size_t i = 0; i < beginWord.size(); ++i) {
        const char origChar = currWord[i];
        for (size_t c = 0; c < 26; ++c) {
          currWord[i] = 'a' + c;
          if (visited.find(currWord) == visited.end()) {
            continue;
          }
          if (currWord == endWord) {
            return count + 1;
          }
          if (!visited[currWord]) {
            visited[currWord] = true;
            q.push({currWord, count + 1});
          }
        }
        currWord[i] = origChar;
      }
      // got TLE because this requires O(M * N) time
      /*
      for (string& nextWord : wordList) {
        if (visited[nextWord]) { continue; }
        int diff = getDiff(currWord, nextWord);
        if (diff == 1) {
          if (nextWord == endWord) {
            return count + 1;
          }
          visited[nextWord] = true;
          q.push({nextWord, count + 1});
        }
      }
      */
    }
    return 0;
  }

  int getDiff(const string& word1, const string& word2) {
    int diff = 0;
    for (size_t i = 0; i < word1.size(); ++i) {
      if (word1[i] != word2[i]) { diff++; }
    }
    return diff;
  }
};

int main() {
  Solution sol;
  string beginWord, endWord;
  vector<string> wordList;
  int expected;

  beginWord = "hit", endWord = "cog", wordList = {"hot", "dot", "dog", "lot", "log", "cog"}, expected = 5;
  EXPECT_EQ(expected, sol.ladderLength(beginWord, endWord, wordList));

  beginWord = "hit", endWord = "cog", wordList = {"hot", "dot", "dog", "lot", "log"}, expected = 0;
  EXPECT_EQ(expected, sol.ladderLength(beginWord, endWord, wordList));

  exit(EXIT_SUCCESS);
}
