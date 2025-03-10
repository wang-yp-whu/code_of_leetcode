#include "m.h"

class Solution 
{
public:
    int findMin(vector<int>& nums) 
    {
        int n = nums.size();
        int left = 0, right = n - 1;
        if(nums[0] <= nums[n - 1])
        {
            return nums[0];
        }
        int pivot = nums[0];
        int mid = 0;
        while(left <= right)
        {
            mid = (left + right) / 2;
            if(nums[mid] >= nums[0])
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
            if(mid == (left + right) / 2)
            {
                break;
            }
        }
        return nums[mid];
    }
};

int main()
{
    vector<int> nums = {
        2, 1
    };
    Solution s;
    int r = s.findMin(nums);
    cout << r << endl;
    return 0;
}