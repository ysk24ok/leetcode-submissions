#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  int scheduleCourse(vector<vector<int>>& courses) {
    auto compare = [] (const vector<int>& l, const vector<int>& r) {
      return l[1] < r[1];
    };
    sort(courses.begin(), courses.end(), compare);
    int current_time = 0;
    priority_queue<int> pq;
    for (auto& course : courses) {
      int duration = course[0];
      int end_time = course[1];
      if (current_time + duration <= end_time) {
        current_time += duration;
        pq.push(duration);
      } else if (pq.size() > 0) {
        int diff_duration = pq.top() - duration;
        if (diff_duration > 0) {
          current_time -= diff_duration;
          pq.pop();
          pq.push(duration);
        }
      }
    }
    return pq.size();
  }
};

int main() {
  Solution sol;
  vector<vector<int>> courses;

  courses = {{100, 200}, {200, 1300}, {1000, 1250}, {2000, 3200}};
  assert(sol.scheduleCourse(courses) == 3);

  courses = {{1000, 2100}, {200, 500}, {900, 1300}};
  assert(sol.scheduleCourse(courses) == 3);

  courses = {{1, 2}, {2, 3}};
  assert(sol.scheduleCourse(courses) == 2);

  courses = {{5,5},{4,6},{2,6}};
  assert(sol.scheduleCourse(courses) == 2);

  courses = {{2,5},{4,7},{3,8}};
  assert(sol.scheduleCourse(courses) == 2);

  courses = {{5,7},{3,5},{10,18},{4,16},{10,14}};
  assert(sol.scheduleCourse(courses) == 3);

  courses = {{5,15},{3,19},{6,7},{2,10},{5,16},{8,14},{10,11},{2,19}};
  //courses = {{6,7},{2,10},{10,11},{8,14},{5,15},{5,16},{2,19},{3,19}};
  assert(sol.scheduleCourse(courses) == 5);

  courses = {{100,2},{32,50}};
  assert(sol.scheduleCourse(courses) == 1);
}
