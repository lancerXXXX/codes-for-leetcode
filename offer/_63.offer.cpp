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

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int min_v = INT32_MAX, max_r = 0;
        for (auto&& i : prices) {
            min_v = min(min_v, i);
            max_r = max(max_r, i - min_v);
        }
        return max_r;
    }
};