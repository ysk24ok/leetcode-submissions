#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr size_t N = 1024;

class MyHashMap {
 public:
  struct ListNode {
    int key;
    int val;
    ListNode* next;
    ListNode(int key, int val) : key(key), val(val), next(nullptr) {}
  };

  /** Initialize your data structure here. */
  MyHashMap() : bucket_size_(N) {
    buckets_.resize(N, nullptr);
  }

  /** value will always be non-negative. */
  void put(int key, int value) {
    int code = hash(key);
    if (!buckets_[code]) buckets_[code] = new ListNode(key, value);
    else if (buckets_[code]->key == key) buckets_[code]->val = value;
    else {
      ListNode* prev_node = buckets_[code];
      ListNode* curr_node = buckets_[code]->next;
      while (curr_node) {
        if (curr_node->key == key) {
          curr_node->val = value;
          return;
        }
        prev_node = curr_node;
        curr_node = curr_node->next;
      }
      prev_node->next = new ListNode(key, value);
    }
  }

  /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
  int get(int key) {
    int code = hash(key);
    ListNode* node = buckets_[code];
    while (node) {
      if (node->key == key) return node->val;
      node = node->next;
    }
    return -1;
  }

  /** Removes the mapping of the specified value key if this map contains a mapping for the key */
  void remove(int key) {
    int code = hash(key);
    if (!buckets_[code]) return;
    ListNode* prev_node = buckets_[code];
    ListNode* curr_node = buckets_[code]->next;
    if (prev_node->key == key) {
      delete prev_node;
      buckets_[code] = curr_node;
      return;
    }
    while (curr_node) {
      if (curr_node->key == key) {
        prev_node->next = curr_node->next;
        delete curr_node;
        break;
      } else {
        prev_node = curr_node;
        curr_node = curr_node->next;
      }
    }
  }

 private:
  int hash(int key) {
    return key % (bucket_size_ - 1);
  }

 private:
  size_t bucket_size_;
  std::vector<ListNode*> buckets_;
};

int main() {
  MyHashMap* obj = new MyHashMap();
  obj->put(1, 1);
  obj->put(2, 2);
  assert(obj->get(1) == 1);
  assert(obj->get(2) == 2);
  assert(obj->get(3) == -1);
  obj->put(2, 1);
  assert(obj->get(2) == 1);
  obj->remove(2);
  assert(obj->get(2) == -1);
  delete obj;
}
