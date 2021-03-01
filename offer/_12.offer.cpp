#include "TreeNode.h"
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#include "string"
#include <iomanip>

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int row = board.size();
        int column = board[0].size();
        vector<vector<bool>> vflag(row, vector<bool>(column, false));
        for (size_t i = 0; i < row; i++)
        {
            for (size_t j = 0; j < column; j++)
            {
                if (board[i][j] == word[0])
                {
                    if(DFS(i, j, row, column, word, board, vflag, 0))
                        return true;
                }
            }
        }
        return false;
    }
    bool DFS(int row_index, int col_index, int row, int column, string &word, vector<vector<char>> &board, vector<vector<bool>> &vflag, int index)
    {
        if (index == word.length() - 1)
            return true;
        bool flag = false;
        vflag[row_index][col_index] = true;
        if (col_index + 1 < column && !vflag[row_index][col_index + 1] && board[row_index][col_index + 1] == word[index+1])
        {
            flag = DFS(row_index, col_index + 1, row, column, word, board, vflag, index + 1);
        }
        if (col_index - 1 >= 0 && !vflag[row_index][col_index - 1] && board[row_index][col_index - 1] == word[index+1])
        {
            flag = DFS(row_index, col_index - 1, row, column, word, board, vflag, index + 1);
        }
        if (row_index + 1 < row && !vflag[row_index + 1][col_index] && board[row_index + 1][col_index] == word[index+1])
        {
            flag = DFS(row_index + 1, col_index, row, column, word, board, vflag, index + 1);
        }
        if (row_index - 1 >= 0 && !vflag[row_index - 1][col_index] && board[row_index - 1][col_index] == word[index+1])
        {
            flag = DFS(row_index - 1, col_index, row, column, word, board, vflag, index + 1);
        }
        if (!flag)
            vflag[row_index][col_index] = false;
        return flag;
    }
};
int main(int argc, char const *argv[])
{
    // char a[4][4] =
    //     {{'C', 'A', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    // vector<vector<char>> va(4, vector<char>(4));
    // for (size_t i = 0; i < 4; i++)
    //     for (size_t j = 0; j < 4; j++)
    //         va[i][j] = a[i][j];

    // Solution s;
    // cout << s.exist(va, "ABCE");


    char a[3][3] =
        {{'C', 'A', 'A'}, {'A', 'A', 'A'}, {'B', 'C', 'D'}};
    vector<vector<char>> va(3, vector<char>(3));
    for (size_t i = 0; i < 3; i++)
        for (size_t j = 0; j < 3; j++)
            va[i][j] = a[i][j];

    Solution s;
    cout << s.exist(va, "AAB");

    return 0;
}
