#include "m.h"

class Solution 
{
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int len = nums.size();
        vector<int> res;
        if(len == 0)
        {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        int l = 0, r = len;
        int mid = (l + r) / 2;
        int prev = -1;
        while(nums[mid] != target)
        {
            mid = (l + r) / 2;
            if(mid == prev)
            {
                break;
            }
            prev = mid;
            if(nums[mid] > target)
            {
                r = mid;
            }
            else if(nums[mid] < target)
            {
                l = mid;
            }
        }
        int l_loc, r_loc;
        if(nums[mid] != target)
        {
            res.push_back(-1);
            res.push_back(-1);
        }
        else
        {
            //这里是错误所在，一定要记得先判断是否越界，才能使用下标访问
            // for(int left = mid;nums[left] == target && left >= 0;left--)
            // {
            //     l_loc = left;
            // }
            // for(int right = mid;nums[right] == target && right < len;right++)
            // {
            //     r_loc = right;
            // }
            res.push_back(l_loc);
            res.push_back(r_loc);
        }
        return res;
    }
};

class Solution_new {
    // lower_bound 返回最小的满足 nums[i] >= target 的下标 i
    // 如果数组为空，或者所有数都 < target，则返回 nums.size()
    // 要求 nums 是非递减的，即 nums[i] <= nums[i + 1]
    int lower_bound(vector<int>& nums, int target) {
        int left = 0, right = (int) nums.size() - 1; // 闭区间 [left, right]
        while (left <= right) { // 区间不为空
            // 循环不变量：
            // nums[left-1] < target
            // nums[right+1] >= target
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid - 1; // 范围缩小到 [left, mid-1]
            } else {
                left = mid + 1; // 范围缩小到 [mid+1, right]
            }
        }
        // 循环结束后 left = right+1
        // 此时 nums[left-1] < target 而 nums[left] = nums[right+1] >= target
        // 所以 left 就是第一个 >= target 的元素下标
        return left;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = lower_bound(nums, target);
        if (start == nums.size() || nums[start] != target) {
            return {-1, -1}; // nums 中没有 target
        }
        // 如果 start 存在，那么 end 必定存在
        int end = lower_bound(nums, target + 1) - 1;
        return {start, end};
    }
};

int main()
{
    vector<int> nums{1};
    int t = 1;
    Solution s;
    vector<int> r = s.searchRange(nums, t);
    return 0;
}