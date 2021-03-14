// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem146.h"

using namespace std;
// @before-stub-for-debug-end

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
    unordered_map<int, list<pair<int, int>>::iterator> um;
    list<pair<int, int>> l;
    int size = 0;
    LRUCache(int capacity) {
        size = capacity;
    }

    int get(int key) {
        auto umit = um.find(key);
        if (umit == um.end()) {
            return -1;
        }else {
            auto temp = (*((*umit).second));
            l.erase((*umit).second);
            l.push_front(temp);
            um[key] = l.begin();
            return temp.second;
        }
    }

    void put(int key, int value) {
        auto umit = um.find(key);
        if (umit != um.end()) {
            l.erase((*umit).second);
        }
        else if (l.size()==size) {
            um.erase(um.find(l.back().first));
            l.pop_back();
        }
        l.push_front(make_pair(key, value));
        um[key] = l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
 // @lc code=end

 int main(int argc, char const *argv[])
 {
    //  LRUCache lc(2);
    //  lc.put(1,1);
    //  lc.put(2,2);
    //  lc.get(1);
    //  lc.put(3,3);
    //  lc.get(2);
    //  lc.put(4,4);
    //  lc.get(1);
    //  lc.get(3);
    //  lc.get(4);

     LRUCache lc(2);
     lc.put(2,1);
     lc.put(1,1);
     cout << lc.get(2);
     lc.put(4,1);
     cout << lc.get(1);
     cout << lc.get(2);

     return 0;
 }
 