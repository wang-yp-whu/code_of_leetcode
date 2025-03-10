#include "m.h"

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) 
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, numeric_limits<int>::max() - 1));
        //一开始，dp中的元素数值被设定为了最大值
        // 第一遍扫描：从左上角到右下角
        for (int i = 0; i < m; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            {
                if (matrix[i][j] != 0) 
                {
                    // 如果上方存在元素，更新当前位置的 dp 值
                    if (i > 0) 
                    {
                        dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                    }
                    // 如果左方存在元素，更新当前位置的 dp 值
                    if (j > 0) 
                    {
                        dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                    }
                } 
                else 
                {
                    dp[i][j] = 0;
                }
            }
        }
        // 第二遍扫描：从右下角到左上角
        for (int i = m - 1; i >= 0; --i) 
        {
            for (int j = n - 1; j >= 0; --j) 
            {
                // 如果当前元素不是 0，进行更新
                if (matrix[i][j] != 0) 
                {
                    // 如果下方存在元素，更新当前位置的 dp 值
                    if (i < m - 1) 
                    {
                        dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
                    }
                    // 如果右方存在元素，更新当前位置的 dp 值
                    if (j < n - 1) 
                    {
                        dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
                    }
                }
            }
        }
        return dp;
    }
};

int main()
{
    vector<vector<int>> mat = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}
    };    
    Solution s;
    vector<vector<int>> r = s.updateMatrix(mat);
    return 0;
}