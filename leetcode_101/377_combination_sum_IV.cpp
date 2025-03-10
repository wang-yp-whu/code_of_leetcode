#include "m.h"

/*
输入：nums = [1,2,3], target = 4
输出：7
解释：
所有可能的组合为：
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
*/
//请注意，顺序不同的序列被视作不同的组合
class Solution 
{
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        vector<long long> dp(target + 1, 0);//中间结果有可能是超过int限制的
        dp[0] = 1;
        for(int i = 1;i <= target;i++)
        {
            for(auto x : nums)
            {
                if(x <= i)
                {
                    dp[i] += dp[i - x];
                }
            }
        }
        return dp[target];
    }
};