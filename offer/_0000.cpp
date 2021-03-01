#include "TreeNode.h"
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
int main(int argc, char const *argv[])
{
    cout << __cplusplus;
    return 0;

    // [4,2,3,4,5,6,7,8,9] [4,8,9]
    TreeNode A(4);
    TreeNode a2(2);
    TreeNode a3(3);
    TreeNode a4(4);
    TreeNode a5(5);
    TreeNode a6(6);
    TreeNode a7(7);
    TreeNode a8(8);
    TreeNode a9(9);
    TreeNode B(4);
    TreeNode b2(8);
    TreeNode b3(9);
    A.left = &a2;
    A.right = &a3;
    a2.left = &a4;
    a2.right = &a5;
    a3.left = &a6;
    a3.right = &a7;
    a4.left = &a8;
    a4.right = &a9;
    B.left = &b2;
    B.right = &b3;

    int a[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {17, 18, 19, 20, 21},
        {22, 23, 24, 25, 26}};
    vector<vector<int>> va(5, vector<int>(5));
    for (size_t i = 0; i < 5; i++)
        for (size_t j = 0; j < 5; j++)
            va[i][j] = a[i][j];
    
    int a[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};
    vector<vector<int>> va(3, vector<int>(4));
    for (size_t i = 0; i < 3; i++)
        for (size_t j = 0; j < 4; j++)
            va[i][j] = a[i][j];

    int a[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    vector<vector<int>> va(3, vector<int>(3));
    for (size_t i = 0; i < 3; i++)
        for (size_t j = 0; j < 3; j++)
            va[i][j] = a[i][j];
}
