#include "m.h"

class Solution 
{
private:
    int n = 0;
public:
    int numberOfArithmeticSlices(vector<int>& nums) 
    {
        n = nums.size();
        vector<int> dp(n, 0);
        for(int i = 2;i < n;i++)
        {
            if(nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])//判断方法是一个重点，之前没想到一个好的
            {
                dp[i] = dp[i - 1] + 1;//dp[i]是以当前元素作为结尾的等差数列的个数
            }
        }    
        int res = accumulate(dp.begin(), dp.end(), 0);
        return res;
    }
};