#include "m.h"

class Solution 
{
private:
    int m;
    int n;
    vector<vector<int>> dp;
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        m = grid.size();
        n = grid[0].size();
        dp.assign(grid.begin(), grid.end());
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(j == 0 && i > 0)
                {
                    dp[i][j] += grid[i - 1][j];
                }
                else if(i == 0 && j > 0)
                {
                    dp[i][j] += grid[i][j - 1];
                }
                else
                {
                    if(i && j)
                    {
                        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
                    }
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};