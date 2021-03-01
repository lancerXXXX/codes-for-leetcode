#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

#include "../TreeNode.h"
#include "../ListNode.h"

using namespace std;

// class Solution {
// public:
//     string reverseLeftWords(string s, int n) {
//         return s.substr(n)+s.substr(0,n);
//     }
// };

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string res = "";
        int length = s.size();
        for (size_t i = 0; i < length; i++)
            res += s[(i+n)%length];
        return res;
    }
};