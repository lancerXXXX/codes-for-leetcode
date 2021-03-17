// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 *
 * [1011] 在 D 天内送达包裹的能力
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
    int shipWithinDays(vector<int>& weights, int D) {
        int l = 1, r = 0;
        for (auto&& i : weights) {
            r += i;
        }
        // 探测 [l,r] 可能完成
        // < l 不能完成, >= r 可以完成
        // 能完成 r = mid
        // 不能完成  l = mid + 1
        while (l < r) {
            int capacity = l + (r - l) / 2;
            if (possible(weights, D, capacity)) {
                r = capacity;
            }
            else {
                l = capacity + 1;
            }
        }
        return l;
    }
    bool possible(vector<int>& weights, int D, int capacity) {
        int count = 0, day = 0;
        for (auto &&i : weights) {
            count += i;
            if (i > capacity) return false; // 如果单个货物超过capacity, 返回false, 否则会算为1次 (因为left 从 1 开始, 如果left从 min 开始就不会出现这种情况)
            if (count > capacity) {
                day++;
                count = i;
            }
        }
        // 3
        // 0 1 2 3
        // 0123超了 day1 结束 3   +1

        //加最后一个正好超了 最后一个单独一天

        // 6
        // 0 1 2 3
        // 0123 day0 结束 +1

        //加最后一个没超 最后一堆单独一天
        day++;
        return day <= D;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> va{1,2,3,1,1};
    s.shipWithinDays(va, 4);
    return 0;
}

