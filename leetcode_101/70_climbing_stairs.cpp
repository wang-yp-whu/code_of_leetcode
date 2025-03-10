#include "m.h"

class Solution 
{
public:
    int climbStairs(int n) 
    {
        if(n <= 2)
        {
            return n;
        }
        vector<long long> res = vector<long long> (n, 0);
        res[0] = 1;
        res[1] = 2;
        for(int i = 1;i < n;i++)
        {
            res[i] = res[i - 1] + res[i - 2];
        }
        return res[n - 1];
    }
};//可优化处在于使用O（1）的空间变量，因为状态只与后两个有关