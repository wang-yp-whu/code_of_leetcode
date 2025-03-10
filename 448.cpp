#include "m.h"

class Solution 
{
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        int n = nums.size();
        int cnt = n + 1;
        for(int i = 0;i < n;i++)
        {
            nums[nums[i] % cnt - 1] += cnt;
        }
        vector<int> res;
        for(int i = 0;i < n;i++)
        {
            if(nums[i] <= n)
            {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {4,3,2,7,8,2,3,1};
    Solution s;
    vector<int> r = s.findDisappearedNumbers(nums);
    return 0;
}