#include "TreeNode.h"
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int low=0;
        int high=numbers.size()-1;
        while(low<high){
            int piv=(low+high)/2;
            if(numbers[piv]>numbers[high])
                low=piv;
            else
                high=piv;
        }
        return numbers[low];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int a[]={3,3,1,3};
    vector<int> va(a,a+4);
    s.minArray(va);
    return 0;
}
