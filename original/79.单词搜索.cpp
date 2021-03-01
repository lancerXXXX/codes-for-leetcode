
/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int row = board.size();
        int column = board[0].size();
        vector<vector<bool>> vflag(row, vector<bool>(column, false));
        for (size_t i = 0; i < row; i++)
            for (size_t j = 0; j < column; j++)
                if (board[i][j] == word[0])
                    if (DFS(i, j, row, column, word, board, vflag, 0))
                        return true;
        return false;
    }
    bool DFS(int r, int c, int row, int column, string &word, vector<vector<char>> &board, vector<vector<bool>> &vflag, int index)
    {
        if (index == word.length() - 1)
            return true;
        bool flag = false;
        vflag[r][c] = true;
        // vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int directions[][]={{0, 1}, {0, -1}, {1, 0}, {-1, 0}}
        //依次查看,右边,左边,上边,下边
        for (int[] dir : directions)
        {
            int temp_r = r + dir[0];
            int temp_c = c + dir[1];
            if (temp_r < row && temp_r >= 0 && temp_c < column && temp_c >= 0 && !vflag[temp_r][temp_c] && board[temp_r][temp_c] == word[index + 1])
                if (DFS(temp_r, temp_c, row, column, word, board, vflag, index + 1))
                    flag = true;
        }
        if (!flag)
            vflag[r][c] = false;
        return flag;
    }
};
// @lc code=end
