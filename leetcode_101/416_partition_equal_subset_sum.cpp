#include "m.h"

/*
其中dp[i][j]表示从数组的[0,i]下标范围内选取若干个正整数（可以是0个）
是否存在一种选取方案使得被选取的正整数的和等于j
*/
class Solution 
{
public:
    bool canPartition(vector<int> &nums) 
    {
        int nums_sum = accumulate(nums.begin(), nums.end(), 0);  // 计算数组所有元素的和
        if (nums_sum % 2 != 0) 
        { 
            return false;
        }
        int target = nums_sum / 2, n = nums.size();  // 目标值是总和的一半，n 是数组的大小
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));  // dp 数组，用来存储子问题的答案
        dp[0][0] = true;  // 初始化：没有物品，和为 0 是可能的
        //事实上，dp[i][0] = true 总是成立，因为不选取任何正整数就可以使得和为 0
        for (int i = 1; i <= n; ++i) 
        {  // 遍历每一个物品
            for (int j = 0; j <= target; ++j) 
            {  // 遍历每一个可能的目标值
                if (j < nums[i - 1]) 
                {  // 当前物品的重量大于目标值 j
                    dp[i][j] = dp[i - 1][j];  // 不能选择当前物品，继承上一行的结果
                } 
                else 
                {  // 当前物品的重量小于等于目标值 j
                    // 两种情况：1. 不选当前物品，2. 选当前物品
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[n][target];  // 如果 dp[n][target] 为 true，则可以将数组分成两个和相等的子集
    }
};