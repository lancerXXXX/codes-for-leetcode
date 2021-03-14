// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem295.h"

using namespace std;
// @before-stub-for-debug-end

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
public:
    multiset<int> cache;
    /** initialize your data structure here. */
    MedianFinder() {
    }

    void addNum(int num) {
        cache.insert(num);
    }

    double findMedian() {
        vector<int> v(cache.begin(), cache.end());
        int length = cache.size();
        if (length & 1) {
            return v[length / 2];
        }
        else {
            return (v[length / 2] + v[length / 2 - 1]) / 2.0;
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

    return 0;
}

