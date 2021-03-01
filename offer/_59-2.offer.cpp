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

class MaxQueue {
private:
    queue<int> q_val;
    deque<int> q_max;
public:
    MaxQueue() {

    }

    int max_value() {
        return q_max.empty() ? -1 : q_max.front();
    }

    void push_back(int value) {
        q_val.push(value);
        if (q_max.size() > 0 && value > q_max.back()) {
            while (!q_max.empty() && value > q_max.back())
                q_max.pop_back();
        }
        q_max.push_back(value);
    }

    int pop_front() {
        if (q_val.size() == 0)
            return -1;
        int front = q_val.front();
        q_val.pop();
        if (front == q_max.front())
            q_max.pop_front();
        return front;
    }
};

int main(int argc, char const* argv[]) {
    MaxQueue mq;
    cout << mq.max_value();
    mq.push_back(6);
    mq.push_back(2);
    mq.push_back(4);
    mq.push_back(7);
    mq.pop_front();
    mq.pop_front();
    mq.pop_front();
    mq.pop_front();
    return 0;
}
