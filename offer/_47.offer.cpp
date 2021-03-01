#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        int all_row = grid.size();
        int all_col = grid[0].size();
        for(int i=1;i<all_col;i++) //处理第一行
            grid[0][i]+=grid[0][i-1];
        for(int i=1;i<all_row;i++) //处理第一列
            grid[i][0]+=grid[i-1][0];
        for(int i=1;i<all_row;i++)
            for(int j=1;j<all_col;j++)
                grid[i][j]+=max(grid[i-1][j],grid[i][j-1]);
        return grid[all_row-1][all_col-1];
    }
};

int main(int argc, char const* argv[]) {
    Solution s;
    int a[][3]={{1,3,1},{1,5,1},{4,2,1}};
    vector<vector<int>> va(3, vector<int>(3));
    for (size_t i = 0; i < 3; i++)
        for (size_t j = 0; j < 3; j++)
            va[i][j] = a[i][j];
    s.maxValue(va);
    return 0;
}
