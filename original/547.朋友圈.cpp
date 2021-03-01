#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 朋友圈
 */

// @lc code=start
class Solution
{
public:
    void dfs(vector<vector<int>> &M, int index,vector<int> &visited)
    {
        visited[index]=1;
        for (size_t i = 0; i < M[index].size(); i++)
        {
            if (M[index][i] == 1&&visited[i]==0)
                dfs(M, i,visited);
        }
    }
    int findCircleNum(vector<vector<int>> &M)
    {
        int v_num=M.size();
        vector<int> visited(v_num);
        int count=0;
        for (size_t i = 0; i < v_num; i++)
        {
            if (visited[i]==0)
            {
                dfs(M, i,visited);
                count++;
            }
        }
        return count;
    }
};
// @lc code=end
