/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */
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

// @lc code=start
class MedianFinder {
private:
    priority_queue<int> small;//大根堆  3 2 1
    priority_queue<int, vector<int>, greater<int>> big;//小根堆  4 5 6
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        if (num > (small.empty() ? INT32_MIN : small.top())) {
            big.push(num);
            if (big.size() - small.size() > 1) {
                small.push(big.top());
                big.pop();
            }
        }
        else {
            small.push(num);
            if (small.size() - big.size() > 1) {
                big.push(small.top());
                small.pop();
            }
        }
    }

    double findMedian() {
        if (big.size() == small.size()) {
            return ((big.empty() ? 0 : big.top()) + (small.empty() ? 0 : small.top())) / 2.0;
        }
        else if (big.size() > small.size()){
            return big.empty() ? 0 : big.top();
        }else {
            return small.empty() ? 0 : small.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
 // @lc code=end

int main(int argc, char const* argv[]) {
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    mf.findMedian();
    mf.addNum(3);
    mf.findMedian();
    return 0;
}

