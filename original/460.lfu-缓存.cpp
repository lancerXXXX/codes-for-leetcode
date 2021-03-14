/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU 缓存
 */
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <unordered_map>
#include <unordered_set>

#include "../TreeNode.h"
#include "../ListNode.h"

using namespace std;

// @lc code=start
class LFUCache {
public:
    unordered_map<int, int> cache;
    int size;
    LFUCache(int capacity) : size(capacity) {}

    int get(int key) {
        
    }

    void put(int key, int value) {
        auto umit = um.find(key);
        if (umit == um.end()) {
            l.pu
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
 // @lc code=end

