#include "m.h"

class Solution 
{
public:
    int majorityElement(vector<int>& nums) 
    {
        int n = nums.size();
        int candidate = nums[0];
        int cnt = 1;
        for(int i = 1;i < n;i++)
        {
            if(nums[i] == candidate)
            {
                cnt++;
            }
            else
            {
                cnt--;
                if(cnt <= 0)
                {
                    candidate = nums[i];
                    cnt = -1 * cnt;
                }
            }
        }
        return candidate;
    }
};

int main()
{
    vector<int> nums = {1,3,1,1,4,1,1,5,1,1,6,2,2};
    Solution s;
    int r = s.majorityElement(nums);
    cout << r << endl;
    return 0;
}