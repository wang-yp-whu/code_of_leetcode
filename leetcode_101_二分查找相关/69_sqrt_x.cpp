#include "m.h"

//更快的收敛速度可以使用牛顿迭代法
class Solution 
{
public:
    int mySqrt(int x) 
    {
        long long tmp = x;
        long long left = 1, right = x;
        long long mid = (left + right) / 2;
        long long prev = -1;
        while(mid <= right)
        {
            mid = (left + right) / 2;
            if(prev == mid)
            {
                break;
            }
            prev = mid;
            if(mid * mid < tmp)
            {
                left = mid;
            }
            else if(mid * mid > tmp)
            {
                right = mid;
            }
            else
            {
                return mid;
            }
        }
        return mid;
    }
};

int main()
{
    int x = 2147395599;
    Solution s;
    int r = s.mySqrt(x);
    cout << r << endl;
    return 0;
}