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
    vector<int> singleNumbers(vector<int>& nums) {
        //设a，b是两个single的: 全部异或，dual的都消掉
        int  a_b= 0;
        for(int num : nums)
            a_b^=num;
        /**
         * 将a和b从a_b中剥离
         * a_b二进制中第一个1则是 a和b不相同的位(异或：同0异1) 以此作为 a和b的区分 
         * (其他的无论和a分为一组还是和b分为一组，两组分别全部异或，都会消掉)
         **/
        //拿到第一个1
        int first1 = a_b&(-a_b);

        int a=0;
        for(int num : nums)
            if(first1&num)
                a^=num;
        int b=a_b^a;
        return vector<int> {a,b};
    }
};

int main(int argc, char const *argv[])
{
    int a[] = {4,1,4,6};
    vector<int> va(a,a+4);
    Solution s;
    s.singleNumbers(va);
    return 0;
}
