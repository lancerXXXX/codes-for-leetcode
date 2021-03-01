#include "TreeNode.h"
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        if(n<4)
            return n-1;
        if(n%3==0)
            return (int)((long long)pow(3,n/3)%(int)(1e9+7));
        else if(n%3==1)
            return (int)((long long)pow(3,n/3-1)*4)%(int)(1e9+7);
        else
            return (int)((long long)pow(3,n/3)*2)%(int)(1e9+7);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.cuttingRope(120);
    return 0;
}
