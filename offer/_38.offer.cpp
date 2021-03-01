#include "TreeNode.h"
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <unordered_set>
#include <vector>
using namespace std;

// class Solution {
// private:
//   vector<string> result;

// public:
//   vector<string> permutation(string s) {
//     dfs(s, s.size() - 1);
//     return result;
//   }
//   void dfs(string& s, int level) {
//     if (level == -1) {
//       result.push_back(s);
//     }
//     set<char> st;
//     for (int i = level; i >= 0; i--) {
//       if (st.find(s[i]) == st.end()) {
//         swap(s[i], s[level]);
//         dfs(s, level - 1);
//         swap(s[i], s[level]);
//       }
//       st.insert(s[i]);
//     }
//   }
// };

class Solution {
private:
  vector<string> result;

public:
  vector<string> permutation(string s) {
    dfs(s, s.size() - 1);
    return result;
  }
  void dfs(string& s, int level) {
    if (level == -1) {
      result.push_back(s);
    }
    for (int i = level; i >= 0; i--) {
      int flag=true;
      for(int j=i+1;j<=level;j++){
        if(s[j]==s[i]){
          flag=false;
          break;
        }
      }
      if (flag) {
        swap(s[i], s[level]);
        dfs(s, level - 1);
        swap(s[i], s[level]);
      }
    }
  }
};
int main(int argc, char const *argv[]) {
  Solution s;
  s.permutation("aab");
  return 0;
}
