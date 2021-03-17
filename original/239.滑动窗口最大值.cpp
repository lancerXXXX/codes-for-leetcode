// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>


using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (q.empty()) {
                q.push_back(nums[i]);
            }
            else {
                while (!q.empty() && nums[i] > q.back()) {
                    q.pop_back();
                }
                q.push_back(nums[i]);
            }
            if (i >= k && q.front() == nums[i - k]) {
                q.pop_front();
            }
            if (i >= k - 1) {
                ans.push_back(q.front());
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char const* argv[]) {
    Solution s;
    vector<int> v = { 1,3,-1,-3,5,3,6,7 };
    s.maxSlidingWindow(v, 3);
    return 0;
}

