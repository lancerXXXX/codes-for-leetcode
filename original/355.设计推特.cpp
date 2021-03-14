/*
 * @lc app=leetcode.cn id=355 lang=cpp
 *
 * [355] 设计推特
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
class Twitter {
private:
    list<pair<int, int>> twee;
    map<int, unordered_set<int>> user;
public:
    /** Initialize your data structure here. */
    Twitter() {

    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        user[userId];
        twee.push_front(make_pair(userId, tweetId));
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        int count = 0;
        vector<int> ans;
        auto u = user.find(userId);
        if (u == user.end()) return ans;
        for (auto&& i : twee) {
            if (count == 10) break;
            if (i.first == userId || u->second.find(i.first) != u->second.end()) {
                count++;
                ans.push_back(i.second);
            }
        }
        return ans;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        user[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        auto target = user[followerId].find(followeeId);
        if (target == user[followerId].end()) return;
        user[followerId].erase(target);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
 // @lc code=end

