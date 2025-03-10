#include "m.h"

class Solution 
{
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<int> dp(amount + 1, amount);
        unordered_set<int> h(coins.begin(), coins.end());
        for(int i = 1;i <= amount;i++)
        {
            if(h.count(i))
            {
                dp[i] = 1;
                continue;
            }
            for(auto j : h)
            {
                if(j <= i)
                {
                    dp[i] = max(dp[i], dp[i - j] + 1);
                }
            }
        }
        return dp[amount];
    }
};