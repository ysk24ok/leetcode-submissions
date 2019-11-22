#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
    unordered_map<char, int> map;
    createMap(map, letters);
    // first check a word is valid (a char is contained in letters)
    vector<bool> is_valid_words;
    is_valid_words.reserve(words.size());
    for (auto& word : words) {
      bool is_valid = true;
      for (auto& c : word) {
        if (map.find(c) == map.end()) {
          is_valid = false;
        }
      }
      is_valid_words.push_back(is_valid);
    }
    // search best combinations
    int s1 = recursive(words, is_valid_words, 0, true, map, score);
    int s2 = recursive(words, is_valid_words, 0, false, map, score);
    return max(s1, s2);
  }

  string tab(int count) {
    string s;
    for (int i = 0; i < count; i++) {
      s += " ";
    }
    return s;
  }

  int recursive(const vector<string>& words, const vector<bool>& is_valid_words, int current_idx, bool use, unordered_map<char, int> map, const vector<int>& score) {
    const string& word = words[current_idx];
    if (!is_valid_words[current_idx] || !use || !checkWordCharExistsInMap(map, word))  {
      if (current_idx == words.size() - 1) return 0;
      int s1 = recursive(words, is_valid_words, current_idx+1, true, map, score);
      int s2 = recursive(words, is_valid_words, current_idx+1, false, map, score);
      return max(s1, s2);
    }
    int total_score = 0;
    for (auto& c : word) {
      total_score += score[getIndexOfAlphabet(c)];
      map[c]--;
    }
    if (current_idx == words.size() - 1) return total_score;
    int s1 = recursive(words, is_valid_words, current_idx+1, true, map, score);
    int s2 = recursive(words, is_valid_words, current_idx+1, false, map, score);
    return max(s1, s2) + total_score;
  }

  void createMap(unordered_map<char, int>& map, vector<char>& letters) {
    for (auto& c : letters) {
      if (map.find(c) == map.end()) {
        map[c] = 0;
      }
      map[c] += 1;
    }
  }

  bool checkWordCharExistsInMap(unordered_map<char, int>& map, const string& word) {
    unordered_map<char, int> count_map_of_word;
    for (auto& c : word) {
      if (count_map_of_word.find(c) == count_map_of_word.end()) {
        count_map_of_word[c] = 0;
      }
      count_map_of_word[c] += 1;
    }
    for (auto& pair : count_map_of_word) {
      if (count_map_of_word[pair.first] > map[pair.first]) {
        return false;
      }
    }
    return true;
  }

  int getIndexOfAlphabet(const char& c) {
    if (c == 'a') {
      return 0;
    } else if (c == 'b') {
      return 1;
    } else if (c == 'c') {
      return 2;
    } else if (c == 'd') {
      return 3;
    } else if (c == 'e') {
      return 4;
    } else if (c == 'f') {
      return 5;
    } else if (c == 'g') {
      return 6;
    } else if (c == 'h') {
      return 7;
    } else if (c == 'i') {
      return 8;
    } else if (c == 'j') {
      return 9;
    } else if (c == 'k') {
      return 10;
    } else if (c == 'l') {
      return 11;
    } else if (c == 'm') {
      return 12;
    } else if (c == 'n') {
      return 13;
    } else if (c == 'o') {
      return 14;
    } else if (c == 'p') {
      return 15;
    } else if (c == 'q') {
      return 16;
    } else if (c == 'r') {
      return 17;
    } else if (c == 's') {
      return 18;
    } else if (c == 't') {
      return 19;
    } else if (c == 'u') {
      return 20;
    } else if (c == 'v') {
      return 21;
    } else if (c == 'w') {
      return 22;
    } else if (c == 'x') {
      return 23;
    } else if (c == 'y') {
      return 24;
    } else {
      return 25;
    }
  }
};

int main() {
  Solution sol;
  vector<string> words;
  vector<char> letters;
  vector<int> score;
  int got;

  words = {"dog","cat","dad","good"};
  letters = {'a','a','c','d','d','d','g','o','o'};
  score = {1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0};
  got = sol.maxScoreWords(words, letters, score);
  assert(got == 23);

  words = {"xxxz","ax","bx","cx"};
  letters = {'z','a','b','c','x','x','x'};
  score = {4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10};
  got = sol.maxScoreWords(words, letters, score);
  assert(got == 27);

  words = {"leetcode"};
  letters = {'l','e','t','c','o','d'};
  score = {0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0};
  got = sol.maxScoreWords(words, letters, score);
  assert(got == 0);
}
