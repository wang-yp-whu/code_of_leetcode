#include "m.h"

class Solution 
{
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        int m = text1.size(), n = text2.size();
        int res = 0;
        vector<int> t(n + 1, 0);
        vector<vector<int>> dp(m + 1, t);
        for(int i = 1;i <= m;i++)
        {
            for(int j = 1;j <= n;j++)
            {
                if(text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};

int main()
{
    string t1 = "abc";
    string t2 = "def";
    Solution s;
    int r = s.longestCommonSubsequence(t1, t2);
    return 0;
}