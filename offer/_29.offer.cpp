#include "TreeNode.h"
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.size()==0||matrix[0].size()==0) return result;
        int row=matrix.size();
        int col=matrix[0].size();
        int layer=0;
        while(row-1-layer-layer>=1&&col-1-layer-layer>=1){
            for(int i=layer;i<=col-1-1-layer;i++)
                result.push_back(matrix[layer][i]);
            for(int i=layer;i<=row-1-1-layer;i++)
                result.push_back(matrix[i][col-layer-1]);
            for(int i=col-1-layer;i>=1+layer;i--)
                result.push_back(matrix[row-layer-1][i]);
            for(int i=row-1-layer;i>=1+layer;i--)
                result.push_back(matrix[i][layer]);
            layer+=1;
        }
        if(layer==row-1-layer)
            for(int i=layer;i<=col-1-layer;i++)
                result.push_back(matrix[layer][i]);
        else if(layer==col-1-layer)
            for(int i=layer;i<=row-1-layer;i++)
                result.push_back(matrix[i][layer]);
        return result;
    }
};

int main(int argc, char const *argv[])
{
    // int a[3][4] = {
    // {1, 2, 3, 4},
    // {5, 6, 7, 8},
    // {9, 10, 11, 12}};
    // vector<vector<int>> va(3, vector<int>(4));
    // for (size_t i = 0; i < 3; i++)
    //     for (size_t j = 0; j < 4; j++)
    //         va[i][j] = a[i][j];

    int a[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    vector<vector<int>> va(3, vector<int>(3));
    for (size_t i = 0; i < 3; i++)
        for (size_t j = 0; j < 3; j++)
            va[i][j] = a[i][j];

    // int a[1][3] = {
    //     {1, 2, 3}};
    // vector<vector<int>> va(1, vector<int>(3));
    // for (size_t i = 0; i < 1; i++)
    //     for (size_t j = 0; j < 3; j++)
    //         va[i][j] = a[i][j];

    Solution s;
    s.spiralOrder(va);
    return 0;
}
