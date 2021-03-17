#include <gtest/gtest.h>

#include <cmath>
#include <cstdlib>
#include <random>
#include <vector>

using namespace std;

class Solution {
 public:
  Solution(double radius, double x_center, double y_center)
      : device_(), engine_(device_()), radius_(radius), x_center_(x_center), y_center_(y_center) {}

  vector<double> randPoint() {
    uniform_real_distribution<> x_dist(x_center_ - radius_, x_center_ + radius_);
    uniform_real_distribution<> y_dist(y_center_ - radius_, y_center_ + radius_);
    while (true) {
      double x = x_dist(engine_), y = y_dist(engine_);
      if (pow(x - x_center_, 2) + pow(y - y_center_, 2) < pow(radius_, 2)) {
        return {x, y};
      }
    }
  }
 private:
  random_device device_;
  default_random_engine engine_;
  double radius_;
  double x_center_;
  double y_center_;
};

int main() {
  double radius = 1, x_center = 0, y_center = 0;
  Solution sol(radius, x_center, y_center);
  sol.randPoint();

  exit(EXIT_SUCCESS);
}
