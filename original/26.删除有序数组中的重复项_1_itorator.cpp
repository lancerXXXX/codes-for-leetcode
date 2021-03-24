/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto index = nums.begin();
        auto pre = nums.end();
        for (; index != nums.end(); index++) {
            if (pre != nums.end() && *pre == *index) {
                nums.erase(index);
                index = pre;
            }
            pre = index;
        }
        return nums.size();
    }
};
// @lc code=end

