// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] 常数时间插入、删除和获取随机元素
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
class RandomizedSet {
private:
    unordered_map<int, int> unmap;
    vector<int> repository;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto it = unmap.find(val);
        if (it != unmap.end()) {
            return false;
        }
        repository.push_back(val);
        unmap[val] = repository.size() - 1;
        return true;
    }
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it = unmap.find(val);
        if (it != unmap.end()) {
            repository[it->second] = repository.back();
            unmap[repository.back()] = it->second;
            repository.pop_back();
            unmap.erase(it);
            return true;
        }
        return false;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return repository[rand() % repository.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
 // @lc code=end

int main(int argc, char const* argv[]) {
    RandomizedSet rs;
    rs.insert(3);
    rs.insert(3);
    rs.getRandom();
    rs.getRandom();
    rs.insert(1);
    rs.remove(3);
    rs.getRandom();
    rs.getRandom();
    rs.insert(0);
    rs.remove(0);
}

