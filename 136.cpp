#include "m.h"

class Solution 
{
public:
    int singleNumber(vector<int>& nums) 
    {
        int hash[60001];
        memset(hash, 0, sizeof(hash));
        //int len = nums.size();
        for(int i = 0;i < nums.size();i++)
        {
            hash[nums[i] + 30000] += 1;
        }
        for(int i = 0;i < 60001;i++)
        {
            if(hash[i] == 1)
            {
                return (i - 30000);
            }
        }
        //return 0;
    }
};

int main()
{
    vector<int> nums;
    int n = 0;
    cout << "please input the numbers:" << endl;
    cin >> n;
    while(abs(n) <= 30000)
    {
        nums.push_back(n);
        cin >> n;
    }
    Solution s;
    int r = s.singleNumber(nums);
    cout << r << endl;
    system("pause");
    return 0;
}