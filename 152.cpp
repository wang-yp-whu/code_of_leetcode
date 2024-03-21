#include "m.h"

class Solution 
{
public:
    int maxProduct(vector<int>& nums) 
    {
        int len = nums.size();
        if(len == 1)
        {
            return nums[0];
        }
        vector<int> dp = vector<int> (len, 0xffffffff);
        dp[0] = nums[0];
        for(int i = 1;i < len;i++)
        {
            if(nums[i] * dp[i - 1] > dp[i - 1])
            {
                dp[i] = nums[i] * dp[i - 1];
            }
            else
            {
                dp[i] = nums[i];
            }
        }
        int ans = 0xffffffff;
        for(int i = 0;i < len;i++)
        {
            if(ans < dp[i])
            {
                ans = dp[i];
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums;
    int n = 0;
    cout << "please input the numbers:" << endl;
    cin >> n;
    while(abs(n) <= 10)
    {
        nums.push_back(n);
        cin >> n;
    }
    Solution s;
    int r = s.maxProduct(nums);
    cout << r << endl;
    system("pause");
    return 0;
}