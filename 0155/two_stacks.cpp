#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>

using namespace std;

struct Node {
  int val;
  Node* next;
  Node(int v) : val(v), next(nullptr) {};
};

class MinStack {
 public:
  /** initialize your data structure here. */
  MinStack() : top_(nullptr), min_(nullptr) {}

  ~MinStack() {
    Node* tmp;
    while (top_) {
      tmp = top_->next;
      delete top_;
      top_ = tmp;
      tmp = min_->next;
      delete min_;
      min_ = tmp;
    }
  }

  void push(int x) {
    Node* tmp;
    tmp = new Node(x);
    tmp->next = top_;
    top_ = tmp;
    if (!min_) {
      tmp = new Node(x);
    } else {
      int cur_min = getMin();
      tmp = (top() < cur_min) ? new Node(x) : new Node(cur_min);
    }
    tmp->next = min_;
    min_ = tmp;
  }

  void pop() {
    if (!top_) return;
    Node* tmp;
    tmp = top_;
    top_ = top_->next;
    delete tmp;
    tmp = min_;
    min_ = min_->next;
    delete tmp;
  }

  int top() {
    // RuntimeError when there is no element
    return top_->val;
  }

  int getMin() {
    // RuntimeError when there is no element
    return min_->val;
  }

 private:
  Node* top_;
  Node* min_;
};

int main() {
  MinStack* obj = new MinStack();
  obj->push(3);
  obj->push(-4);
  obj->push(1);
  assert(obj->top() == 1);
  assert(obj->getMin() == -4);
  obj->pop();
  assert(obj->top() == -4);
  assert(obj->getMin() == -4);
  obj->pop();
  assert(obj->top() == 3);
  assert(obj->getMin() == 3);
  delete obj;
}
