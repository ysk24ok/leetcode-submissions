#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

constexpr int N = 1024;

class MyHashSet {
 public:
  struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
  };

  /** Initialize your data structure here. */
  MyHashSet() : bucket_size_(N) {
    buckets.resize(bucket_size_);
    for (size_t i = 0; i < buckets.size(); i++) {
      buckets[i] = nullptr;
    }
  }

  ~MyHashSet() {
    for (ListNode* node : buckets) {
      deleteNode(node);
    }
  }

  void add(int key) {
    int code = hash(key);
    if (!buckets[code]) buckets[code] = new ListNode(key);
    else if (buckets[code]->val == key) return;
    else {
      ListNode* prev_node = buckets[code];
      ListNode* curr_node = buckets[code]->next;
      while (curr_node) {
        if (curr_node->val == key) return;
        prev_node = curr_node;
        curr_node = curr_node->next;
      }
      prev_node->next = new ListNode(key);
    }
  }

  void remove(int key) {
    int code = hash(key);
    if (!buckets[code]) return;
    ListNode* prev_node = buckets[code];
    ListNode* curr_node = buckets[code]->next;
    if (prev_node->val == key) {
      delete prev_node;
      buckets[code] = curr_node;
      return;
    }
    while (curr_node) {
      if (curr_node->val == key) {
        prev_node->next = curr_node->next;
        delete curr_node;
        break;
      } else {
        prev_node = curr_node;
        curr_node = curr_node->next;
      }
    }
  }

  /** Returns true if this set contains the specified element */
  bool contains(int key) {
    int code = hash(key);
    ListNode* node = buckets[code];
    while (node) {
      if (node->val == key) return true;
      node = node->next;
    }
    return false;
  }

 private:
  int hash(int key) {
    return key % (bucket_size_ - 1);
  }

  void deleteNode(ListNode* node) {
    if (!node) return;
    deleteNode(node->next);
    delete node;
  }

 private:
  size_t bucket_size_;
  std::vector<ListNode*> buckets;
};

int main() {
  MyHashSet* obj = new MyHashSet();
  obj->add(1);
  obj->add(2);
  assert(obj->contains(1));
  assert(!obj->contains(3));
  obj->add(2);
  assert(obj->contains(2));
  obj->remove(2);
  assert(!obj->contains(2));
  obj->add(2);
  assert(obj->contains(2));
  obj->add(2+N);
  obj->add(2+N+N);
  assert(obj->contains(2+N));
  assert(obj->contains(2+N+N));
  obj->remove(2+N);
  assert(obj->contains(2));
  assert(!obj->contains(2+N));
  assert(obj->contains(2+N+N));
  delete obj;
}
