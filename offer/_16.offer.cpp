#include "TreeNode.h"
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;


class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        double temp=myPow(x,n/2);
        return (n%2==0?1:(n>0?x:1/x))*temp*temp;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout<<s.myPow(2,-2);
    // int n=-1;
    // cout << (n>>1);
    return 0;
}
