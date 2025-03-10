#include "m.h"

class Solution 
{
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) 
    {
        int r = 0;
        int n = nums.size();
        for(int i = 0;i < n;i++)
        {
            if(i >= k || i + k < n)//至少有一边的数字存在
            {
                if(i >= k && nums[i] <= nums[i - k])
                {
                    continue;
                }
                if(i + k < n && nums[i] <= nums[i + k])
                {
                    continue;
                }
                //此时才是严格大于两边距离为k的数（如果存在）
                r += nums[i];
            }
            else
            {
                //证明两边的数字都不存在，符合要求
                r += nums[i];
            }
        }
        return r;
    }
};