#include "m.h"

class Solution 
{
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int n = nums.size();
        int left = 0, right = n - 1;
        int mid = (right + left) / 2;
        while(left <= right)
        {
            if(nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
            mid = (right + left) / 2;
        }
        return left;
    }
};