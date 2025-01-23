#include "m.h"

class Solution_1
{
public:
    int search1(vector<int>& nums, int target) 
    {
        int len = nums.size();
        int left = 0, right = len - 1;
        int mid;
        while(left <= right)
        {
            mid = left + (right - left) / 2;
            if(nums[mid] == target)
            {
                return mid;
            }
            if(nums[mid] >= nums[0])
            {
                if(target >= nums[0] && nums[mid] > target)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                if(target < nums[0] && target > nums[mid])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};

class Solution 
{
public:
    bool search(vector<int>& nums, int target) 
    {
        int len = nums.size();
        if(len == 0)
        {
            return false;
        }
        if(len == 1)
        {
            return nums[0] == target;
        }
        int l = 0, r = len - 1;
        int mid;
        while(l <= r)
        {
            mid = l + (r - l) / 2;
            if(nums[mid] == target)
            {
                return true;
            }
            if(nums[l] == nums[mid] && nums[mid] == nums[r])
            {
                //此处破坏了这道题最难的一点，就是重复元素的出现使得无法判断区间是否有序
                l++, r--;
                continue;
            }
            //之后的做法与上一道题一样
            if(nums[mid] >= nums[l])
            {
                if(target >= nums[l] && nums[mid] > target)
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else if(nums[mid] < nums[l])
            {
                if(target <= nums[r] && nums[mid] < target)
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
        }
        return false;
    }
};

int main()
{
    vector<int> nums{1, 0, 1, 1, 1};
    int target = 0;
    Solution s;
    bool r =  s.search(nums, target);
    cout << r << endl;
    return 0;
}