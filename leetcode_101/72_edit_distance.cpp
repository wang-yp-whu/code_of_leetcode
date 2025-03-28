#include "m.h"

class Solution 
{
public:
    int minDistance(string word1, string word2) 
    {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        for(int i = 0;i <= m;i++)
        {
            for(int j = 0;j <= n;j++)
            {
                if(i == 0 || j == 0)
                {
                    dp[i][j] = i + j;
                }
                else
                {
                    if(word1[i - 1] == word2[j - 1])//错误在此，之前的是word1[i] == word2[j]
                    {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                    else
                    {
                        dp[i][j] = min(dp[i][j - 1],dp[i - 1][j]) + 1;
                    }
                }
            }
        }
        return dp[m][n];
    }
};