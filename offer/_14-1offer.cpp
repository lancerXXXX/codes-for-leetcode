#include "TreeNode.h"
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        vector<int> result(n+1);
        result[2]=1;
        for(int index=3; index <= n; index++){
            for(int i=1;i<=index/2;i++){
                result[index] = max(result[index], max(i*result[index-i],i*(index-i)));
            }
        }
        return result[n];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.cuttingRope(5);
    return 0;
}
