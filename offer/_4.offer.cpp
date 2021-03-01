#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        int row = matrix.size() - 1, column = matrix[0].size() - 1;
        for (int i = 0, j = 0; i <= row && j <= column;)
        {
            if (target == matrix[i][j])
            {
                return true;
            }
            else if (target > matrix[i][j])
            {
                if (i == row && j == column)
                    return false;
                i = i < row ? i + 1 : row;
                j = j < column ? j + 1 : column;
            }
            else
            {
                for (int index2 = j; index2 <= column; index2++)
                    for (int index = i; index >= 0; index--)
                        if (matrix[index][index2] == target)
                            return true;
                for (int index2 = i; index2 <= row; index2++)
                    for (int index = j; index >= 0; index--)
                        if (matrix[index2][index] == target)
                            return true;
                return false;
            }
        }
        return false;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    // int a[5][5] = {
    //     {1, 4, 7, 11, 15},
    //     {2, 5, 8, 12, 19},
    //     {3, 6, 9, 16, 22},
    //     {10, 13, 14, 17, 24},
    //     {18, 21, 23, 26, 30}};
    int a[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {17, 18, 19, 20, 21},
        {22, 23, 24, 25, 26}};
    // int a[1][2]{
    //     {1, 1}};
    vector<vector<int>> va(5, vector<int>(5));
    // vector<vector<int>> va(1, vector<int>(2));
    for (size_t i = 0; i < 5; i++)
        for (size_t j = 0; j < 5; j++)
            va[i][j] = a[i][j];
    cout << s.findNumberIn2DArray(va, 15);
    return 0;
}
