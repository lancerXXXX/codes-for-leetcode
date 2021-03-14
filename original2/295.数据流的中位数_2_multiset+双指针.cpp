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
    multiset<int> ms;
    multiset<int>::iterator pre, next;
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        ms.insert(num);
        if (ms.size() - 1 == 0) {
            pre = ms.begin();
            next = ms.begin();
        }
        else {
            if ((ms.size() - 1) & 1) {
                if (num < *pre) {
                    pre--;
                }
                else {
                    next++;
                }
            }
            else {
                if (num < *pre) {
                    next--;
                }
                else if (num < *next) {
                    next--;
                    pre++;
                }
                else {
                    pre++;
                }
            }
        }
    }

    double findMedian() {
        return (*pre + *next) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
 // @lc code=end
