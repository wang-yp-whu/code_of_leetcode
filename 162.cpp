#include "m.h"

class Solution 
{
public:
    int findPeakElement(vector<int>& nums) 
    {
        int left = 0, right = nums.size() - 1;
        int mid = (left + right) / 2;
        int pre = mid;
        if(right == 0)
        {
            return 0;
        }
        if(right == 1)
        {
            if(nums[right] > nums[left])
            {
                return right;
            }
            return 0;
        }
        if(nums[right] > nums[right - 1])
        {
            return right;
        }
        if(nums[left] > nums[left + 1])
        {
            return left;
        }
        while(mid > 0 && mid < right - 1) 
        {
            pre = mid;
            if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            {
                return mid;
            }
            right = mid;
            mid = (left + right) / 2;
            if(mid == pre)
            {
                mid++;
                //break;
            }
        }
        left = 0, right = nums.size() - 1;
        mid = (left + right) / 2;
        while(mid > 0 && mid < right - 1) 
        {
            pre = mid;
            if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            {
                return mid;
            }
            left = mid;
            mid = (left + right) / 2;
            if(mid == pre)
            {
                mid++;
                //break;
            }
        }
        //return 0;
    }
};

class Solution 
{
public:
    int findPeakElement(vector<int>& nums) 
    {
        if (nums.size() == 1) return 0;
        if (nums.size() == 2) return nums[0] > nums[1] ? 0 : 1;
        int lef = 0, rig = nums.size() - 1;
        while (lef < rig) 
        {
            int mid = lef + (rig - lef) / 2;
            if (mid - 1 == -1) 
            {
                if (nums[mid] > nums[mid + 1]) 
                {
                    return mid;
                }
                else 
                {
                    lef = mid + 1;
                }
            }
            else 
            {
                if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]) 
                {
                    return mid;
                }
                else if (nums[mid] < nums[mid + 1]) 
                {
                    lef = mid + 1;
                }
                else 
                {
                    rig = mid - 1;
                }
            }
        }
        return lef;
    }
};

int main()
{
    vector<int> nums;
    int n = 0;
    cin >> n;
    while(abs(n) < 10000)
    {
        nums.push_back(n);
        cin >> n;
    }
    Solution s;
    int r = s.findPeakElement(nums);
    cout << r << endl;
    system("pause");
    return 0;
}