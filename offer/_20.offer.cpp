#include "TreeNode.h"
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        for(int i=0,j=nums.size()-1;i<j;){
            while(i<nums.size()&&nums[i]%2==1) 
                i++;
            while(j>=0&&nums[j]%2==0) 
                j--;
            if(i<nums.size()&&j>=0&&i<j)
                swap(nums[i],nums[j]);
        }
        return nums;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    int a[]={1,2,3,4};
    vector<int> va(a,a+4);
    s.exchange(va);
    return 0;
}
