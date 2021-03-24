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
        if (nums.size() == 0) return 0;
        int unique = 0; // 下一个位置存放下一个不重复数字;
        int index = 1; // 遍历数组
        while (index < nums.size())
        {
            if (nums[index] != nums[unique]) { // 找到下一个不重复元素
                nums[++unique] = nums[index];
                index++;
            }
            else { // 如果index和是重复的则跳过
                index++;
            }
        }
        return unique + 1;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    
    s.removeDuplicates(vector<int>() = {1, 1, 2});
    return 0;
}

