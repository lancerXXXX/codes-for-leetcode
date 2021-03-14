// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem130.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

 // #include "../TreeNode.h"
 // #include "../ListNode.h"

using namespace std;

// @lc code=start
class Solution {
private:
    int turn[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0) return;
        int row = board.size(), col = board[0].size(), turn_index = 0;
        for (int i = 0, j = 0; i >= 0 && j >= 0 && i <= board.size() - 1 && j <= board[0].size() - 1; i += turn[turn_index][0], j += turn[turn_index][1]) {
            if (i == 0 && j == col - 1 || i == row - 1 && j == col - 1 || i == row - 1 && j == 0)
                turn_index++;
            if (board[i][j] == 'O')
                BFS(board, i, j);
        }
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                board[i][j] = board[i][j] == 'I' ? board[i][j] = 'O' : board[i][j] = 'X';

    }
    void BFS(vector<vector<char>>& board, int i, int j) {
        while (i >= 0 && j >= 0 && i <= board.size() - 1 && j <= board[0].size() - 1 && board[i][j] == 'O') {
            board[i][j] = 'I';
            for (auto&& a : turn)
                BFS(board, i + a[0], j + a[1]);
        }
    }
};
// @lc code=end

int main(int argc, char const* argv[]) {
    // vector<vector<char>> a = { {'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'} };
    vector<vector<char>> a = { {'X'} };
    Solution s;
    s.solve(a);
    return 0;
}

