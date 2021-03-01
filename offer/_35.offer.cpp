#include "TreeNode.h"
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};
// class Solution {
// public:
//   Node *copyRandomList(Node *head) {
//     Node *new_list = new Node(-1), *new_list_work = new_list,
//          *old_list_work = head;
//     map<Node *, Node *> m;
//     for (; old_list_work; new_list_work = new_list_work->next,
//                           old_list_work = old_list_work->next) {
//       new_list_work->next = new Node(old_list_work->val);
//       m.insert(make_pair(old_list_work, new_list_work->next));
//     }
//     for (; head; head = head->next)
//       m[head]->random = m[head->random];
//     return new_list->next;
//   }
// };


class Solution {
private:
  unordered_map<Node *, Node *> u_map;

public:
  Node *copyRandomList(Node *head) { return dfs(head); }
  Node *dfs(Node *old_list_current_head) {
    if (!old_list_current_head||u_map.find(old_list_current_head) != u_map.end())
      return u_map[old_list_current_head];
    Node *new_list_current_head = new Node(old_list_current_head->val);
    u_map.insert(make_pair(old_list_current_head, new_list_current_head));
    new_list_current_head->next = dfs(old_list_current_head->next);
    new_list_current_head->random = dfs(old_list_current_head->random);
    return new_list_current_head;
  }
};

int main(int argc, char const *argv[]) {
  Node a1(1);
  Node a2(2);
  Node a3(3);
  a3.random=&a1;
  a1.next = &a2;
  a2.next = &a3;
  Solution s;
  Node* res=s.copyRandomList(&a1);
  while(res){
    cout<<res->val;
    res=res->next;
  }
  return 0;
}
