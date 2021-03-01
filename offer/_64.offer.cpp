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
    int sumNums(int n) {
        int sum = n;
        n && (sum += sumNums(n - 1));
        return sum;
    }
};

class Solution {
public:
    int sumNums(int n) {
        bool a[n][n + 1];
        return sizeof(a) >> 1;
    }
};

int main(int argc, char const* argv[]) {
    Solution s;
    s.sumNums(3);
    return 0;
}
