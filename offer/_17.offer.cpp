#include "TreeNode.h"
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;
class Solution
{
public:
    vector<int> printNumbers(int n) {
        vector<int> result;
        workFun("", n, n, result);
        return result;
    }
    void workFun(string index_string, int index_level, int n, vector<int> &result)
    {
        if (index_level<=0) {
            int result_num=stoi(index_string);
            if(result_num!=0)
                result.push_back(result_num);
            return;
        }
        for (int i = 0; i < 10; i++)
            workFun(index_string + to_string(i), index_level - 1, n, result);
    }
};