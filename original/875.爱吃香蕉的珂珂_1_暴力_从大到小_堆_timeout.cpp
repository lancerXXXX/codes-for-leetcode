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
        int temp_h, temp_k, count = 0;

        while (true) {
            priority_queue<int> pq(piles.begin(), piles.end());
            temp_k = pq.top() - count;
            temp_h = 0;
            while (true) {
                if (temp_k >= pq.top()) {
                    temp_h += pq.size();
                    break;
                }
                else {
                    int temp = pq.top();
                    pq.pop();
                    temp -= temp_k;
                    temp_h++;
                    pq.push(temp);
                }
            }
            if (temp_h > h) {
                break;
            }
            temp_k--;
            count++;
        }
        return temp_k+1;
    }
};
// @lc code=end

int main(int argc, char const* argv[]) {
    vector<int> va{ 3,4,7,11 };
    Solution s;
    s.minEatingSpeed(va, 8);
    return 0;
}

