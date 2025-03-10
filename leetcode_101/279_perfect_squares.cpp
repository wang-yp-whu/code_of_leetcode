#include "m.h"

class Solution 
{
public:
    bool is_square(int x)
    {
        int r = sqrt(x);
        if(x == r * r)
        {
            return true;
        }
        return false;
    }
    int numSquares(int n) 
    {
        vector<int> dp(10001, 0);
        dp[0] = 0;
        dp[1] = 1;
        bool f;
        for(int i = 2;i <= n;i++)
        {
            dp[i] = i;
            for(int j = 1;j <= 100;j++)
            {
                if(j * j > i)
                {
                    break;
                }
                else
                {
                    if(dp[i] < dp[i - j * j] + 1)
                    {
                        dp[i] = dp[i - j * j] + 1;
                    }
                }
            }
        }
        return dp[n];
    }
};