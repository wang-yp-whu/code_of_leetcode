#include "m.h"

class Solution 
{
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int n = numbers.size();
        int sum = 0;
        vector<int> res;
        for(int i = 0, j = n - 1;i < j;)
        {
            sum = numbers[i] + numbers[j];
            if(sum == target)
            {
                res.push_back(i);
                res.push_back(j);
                return res;
            }
            else if(sum < target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}