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

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> anss;
        int front = 1, back = 1;
        int sum = front;
        deque<int> ans_q{ front };
        while (back < target) {
            if (sum < target) {
                back++;
                sum += back;
                ans_q.push_back(back);
            }
            else {
                if (sum == target)
                    anss.push_back(vector<int>(ans_q.begin(), ans_q.end()));
                sum -= front;
                front++;
                ans_q.pop_front();
            }
        }
        return anss;
    }
};

int main(int argc, char const* argv[]) {
    Solution s;
    s.findContinuousSequence(9);
    return 0;
}
