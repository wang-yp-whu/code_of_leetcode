#include "m.h"

class Solution 
{
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> dp = vector<int> (n + 1, 0);
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 1; i < n;i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);//对于第i号房子，只有抢或不抢两种选择
        }
        return dp[n];
    }
};