#include "m.h"

class Solution 
{
public:
    int longestConsecutive(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int ans = 0, flag = 1;
        for(int i = 0; i < len - 1;)
        {
            if(nums[i] == nums[i + 1] - 1)
            {
                flag++;
                i++;
            }
            else if(nums[i] == nums[i + 1])
            {
                i++;
                continue;
            }
            else
            {
                if(flag > ans)
                {
                    ans = flag;
                }
                flag = 1;
                i++;
            }
            if(i == len - 1)
            {
                if(flag > ans)
                {
                    ans = flag;
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = vector<int> (4, 0);
    int n = 0;
    for(int i = 0; i < 10; i++)
    {
        cin >> n;
        nums[i] = n;
    }
    Solution s;
    int r = s.longestConsecutive(nums);
    cout << r << endl;
    system("pause");
    return 0;
}