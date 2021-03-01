#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i){
                if(nums[nums[i]]==nums[i])
                    return nums[i];
                else
                    swap(nums[i],nums[nums[i]]);
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int a[7]={2,3,1,0,4,5,3};
    vector<int> va(a,a+7);
    s.findRepeatNumber(va);
    return 0;
}
