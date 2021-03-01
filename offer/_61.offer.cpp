#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

#include "../TreeNode.h"
#include "../ListNode.h"

using namespace std;

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int pos_1th_no0 = distance(nums.begin(), find_if(nums.begin(), nums.end(), [](auto x) {return x != 0; }));
        int i = pos_1th_no0 + 1, pre = nums[pos_1th_no0], gap = 0;
        for (; i < nums.size() && pre != nums[i]; pre = nums[i], i++)
            gap += (nums[i] - pre - 1);
        return gap <= pos_1th_no0 && i >= nums.size();
    }
};