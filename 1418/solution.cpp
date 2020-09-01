#include <gtest/gtest.h>

#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<string>> displayTable(vector<vector<string>>& orders) {
    unordered_map<string, unordered_map<string, int>> order_by_table;
    set<int> tables;
    set<string> foods;
    for (const auto& order : orders) {
      const string& customer = order[0];
      const string& table_id = order[1];
      const string& food = order[2];
      if (order_by_table.find(table_id) == order_by_table.end()) {
        order_by_table[table_id] = {};
      }
      order_by_table[table_id][food] += 1;
      tables.insert(stoi(table_id));
      foods.insert(food);
    }
    // NOTE: I don't need to sort std::set, because it automatically sorts elements
    //       unlike std::unordered_set
    vector<int> ordered_tables(tables.begin(), tables.end());
    vector<string> ordered_foods(foods.begin(), foods.end());
    sort(ordered_tables.begin(), ordered_tables.end());
    sort(ordered_foods.begin(), ordered_foods.end());

    vector<string> header = {"Table"};
    for (const auto& food : ordered_foods) { header.push_back(food); };
    vector<vector<string>> ret;
    ret.push_back(header);
    for (const int& table_id : ordered_tables) {
      string table = to_string(table_id);
      vector<string> row = {table};
      unordered_map<string, int>& map = order_by_table[table];
      for (const string& food : ordered_foods) {
        if (map.find(food) != map.end()) {
          map[food];
          row.push_back(to_string(map[food]));
        } else {
          row.push_back("0");
        }
      }
      ret.push_back(row);
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<vector<string>> orders, expected;

  orders = {
    {"David","3","Ceviche"},
    {"Corina","10","Beef Burrito"},
    {"David","3","Fried Chicken"},
    {"Carla","5","Water"},
    {"Carla","5","Ceviche"},
    {"Rous","3","Ceviche"}
  };
  expected = {
    {"Table","Beef Burrito","Ceviche","Fried Chicken","Water"},
    {"3","0","2","1","0"},
    {"5","0","1","0","1"},
    {"10","1","0","0","0"}
  };
  EXPECT_EQ(expected, sol.displayTable(orders));

  orders = {
    {"James","12","Fried Chicken"},
    {"Ratesh","12","Fried Chicken"},
    {"Amadeus","12","Fried Chicken"},
    {"Adam","1","Canadian Waffles"},
    {"Brianna","1","Canadian Waffles"}
  };
  expected = {
    {"Table","Canadian Waffles","Fried Chicken"},
    {"1","2","0"},
    {"12","0","3"}
  };
  EXPECT_EQ(expected, sol.displayTable(orders));
}
