#include "m.h"

class Solution 
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        vector<pair<int, int>> dp(n, {0, 0});//我这里的dp存放的是到达当前下标时最长的递增序列，由此错误，示例如下
        dp[0].first = 1;
        dp[0].second = nums[0];
        int maxx = 0;
        for(int i = 1;i < n;i++)
        {
            if(nums[i] > dp[i - 1].second)
            {
                dp[i].first = dp[i - 1].first + 1;
                dp[i].second = nums[i];
            }
            else
            {
                dp[i].first = 1;
                dp[i].second = nums[i];
                for(int j = i - 1;j >= 0;j--)
                {
                    if(dp[j].first == dp[i].first)
                    {
                        //若相等则此时应该取最大值为两者之间最小的那一个
                        dp[i].second = min(dp[i].second, dp[j].second);
                    }
                    else if(dp[j].first > dp[i].first)
                    {
                        dp[i].first = dp[j].first;
                        dp[i].second = dp[j].second;
                    }
                }
            }
        }
        return dp[n - 1].first;
    }
};

class Solution 
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = (int)nums.size();
        if (n == 0) 
        {
            return 0;
        }
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) 
        {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) 
            {
                if (nums[j] < nums[i]) 
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main()
{
    vector<int> nums({0,1,0,3,2,3});
    Solution s;
    int r = s.lengthOfLIS(nums);
    return 0;
}