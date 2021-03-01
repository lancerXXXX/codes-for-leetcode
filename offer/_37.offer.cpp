#include "TreeNode.h"
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class Codec {
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    queue<TreeNode *> q;
    if (!root)
      return "";
    string result = "";
    q.push(root);
    while (!q.empty()) {
      root = q.front();
      q.pop();
      if (!root) {
        result += "null,";
        continue;
      }
      result += (to_string(root->val) + ",");
      q.push(root->left);
      q.push(root->right);
    }
    result.pop_back();
    return result;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    if (data.size() == 0)
      return nullptr;
    TreeNode *root;
    queue<TreeNode *> q;
    int i = -1;
    root = new TreeNode(stoi(getAnumber(data, i)));
    q.push(root);
    TreeNode *work = nullptr;
    while (i < data.size() && !q.empty()) {
      work = q.front();
      q.pop();
      string temp = getAnumber(data, i);
      if (temp != "null") {
        work->left = new TreeNode(stoi(temp));
        q.push(work->left);
      }
      temp = getAnumber(data, i);
      if (temp != "null") {
        work->right = new TreeNode(stoi(temp));
        q.push(work->right);
      }
    }
    return root;
  }
  string getAnumber(string &data, int &i) {
    string temp = "";
    for (++i; i < data.size() && data[i] != ','; i++)
      temp += data[i];
    return temp;
  }
};

int main(int argc, char const *argv[]) {
  Codec c;
  c.deserialize("1,2,3,null,null,4,5");
  return 0;
}
