#include "m.h"

class Solution 
{
public:
    int findMaxForm(vector<string>& strs, int m, int n) 
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int len = strs.size();
        int zero = 0, one = 0;
        for(int i = 0;i < len;i++)
        {
            string tmp = strs[i];
            zero = 0, one = 0;
            for(int j = 0;j < tmp.size();j++)
            {
                if(tmp[j] == '0')
                {
                    zero++;
                }
                else
                {
                    one++;
                }
            }
            for(int x = m;x >= zero;x--)
            {
                for(int y = n;y >= one;y--)
                {
                    dp[x][y] = max(dp[x][y], dp[x - zero][y - one] + 1);
                }
            }
        }
        return dp[m][n];
    }
};