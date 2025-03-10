#include "m.h"

class Solution 
{
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        int m = matrix.size(), n = matrix[0].size();
        int max_side = 0;
        // dp数组定义：dp[i][j] 表示以 matrix[i-1][j-1] 为右下角的最大正方形的边长
        // dp 数组的大小比矩阵多一行和一列，dp[0][*] 和 dp[*][0] 都初始化为 0
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) 
        {  // 从 1 开始，因为 dp 数组多了一行和一列
            for (int j = 1; j <= n; ++j) 
            {  // 从 1 开始
                // 如果当前矩阵元素是 '1'，则说明可以参与构建正方形
                if (matrix[i - 1][j - 1] == '1') 
                {
                    // 更新 dp[i][j]：当前元素 (i-1, j-1) 可以作为一个正方形的右下角
                    // dp[i][j] 的值是从上方、左方和左上方三个位置的最小值 + 1
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                }
                max_side = max(max_side, dp[i][j]);
            }
        }
        return max_side * max_side;
    }
};


int main()
{
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    }; 
    Solution s;
    int r = s.maximalSquare(matrix);
    return 0;
}