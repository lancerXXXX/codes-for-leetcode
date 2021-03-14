/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// @lc code=start
class LRUCache {
public:
    list<pair<int, int>> l;
    int size = 0;
    LRUCache(int capacity) {
        size = capacity;
    }

    int get(int key) {
        auto temp = find(key);
        return temp == l.end() ? -1 : changePos(temp).second;
    }

    void put(int key, int value) {
        auto temp = find(key);
        if (temp == l.end()) {
            if (l.size() == size) {
                l.pop_back();
            }
            l.push_front(make_pair(key, value));
        }
        else {
            (*temp).second = value;
            changePos(temp);
        }
    }

    list<pair<int, int>>::iterator find(int key) {
        auto it = l.begin();
        while (it != l.end()) {
            if ((*it).first == key) {
                break;
            }
            it++;
        }
        return it;
    }
    pair<int,int> changePos(list<pair<int, int>>::iterator it) {
        auto t = (*it);
        l.erase(it);
        l.push_front(t);
        return t;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
 // @lc code=end