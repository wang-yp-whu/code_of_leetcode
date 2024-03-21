#include "m.h"

class Solution 
{
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int len = nums.size();
        int ans = 0;
        int sum = 0;
        for(int i = 0;i < len;i++)
        {
            sum += nums[i];
        }
        int i = 0, j = 0;
        for(i = 0, j = len - 1;i <= j;)
        {
            if(sum >= target)
            {
                ans = j - i + 1;
                if(nums[i] > nums[j])
                {
                    sum -= nums[j];
                    j--;
                }
                else if(nums[i] == nums[j])
                {
                    if(i < j && nums[i + 1] < nums[j - 1])
                    {
                        sum -= nums[i];
                        i++;
                    }
                    else
                    {
                        sum -= nums[j];
                        j--;
                    }
                }
                else
                {
                    sum -= nums[i];
                    i++;
                }
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums;
    int n = 0;
    cout << "input the nums:" << endl;
    cin >> n;
    while(n > 0)
    {
        nums.push_back(n);
        cin >> n;
    }
    cout << "input the target:" << endl;
    int t;
    cin >> t;
    Solution s;
    int r = s.minSubArrayLen(t, nums);
    cout << r << endl;
    system("pause");
    return 0;
}