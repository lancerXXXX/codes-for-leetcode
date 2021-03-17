// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// 3 堆
// 3 4 5
// 3h 5 -> 3h


// 3 4 12
// 3h 12 -> 3h
// 4h 4 -> 5h

// 3 4 12
// [12]
// 3

// 3 4 5
// [4]
// 3 4 1 -> 1 3 4    --1
// 1 3 4   -- 1
// size --2

// 3 4 12
// [4]
// 3 4 8 --1
// 3 4 4 --1
// size = -- 3

// @lc code=start
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int _min = 1, _max = INT32_MIN;
        for (auto&& i : piles) {
            _max = max(_max, i);
        }
        while (_min < _max) {
            int mid = _min + (_max - _min) / 2;
            if (!possible(piles, h, mid)) {
                _min = mid + 1;
            }
            else {
                _max = mid;
            }
        }
        return _min;
    }
    bool possible(vector<int>& piles, int h, int speed) {
        int hour = 0;
        for (auto&& i : piles) {
            hour += (i - 1) / speed + 1;
        }
        return hour <= h;
    }
};
// @lc code=end

int main(int argc, char const* argv[]) {
    vector<int> va{ 3, 6, 7 ,11 };
    Solution s;
    s.minEatingSpeed(va, 8);
    return 0;
}

