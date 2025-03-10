#include "m.h"

class Solution 
{
public:
    long long maxWeight(vector<int>& pizzas) 
    {
        int n = pizzas.size();
        int days = n / 4;
        long long ans = 0;
        sort(pizzas.begin(), pizzas.end());
        reverse(pizzas.begin(), pizzas.end());
        int half = days / 2;
        int odd = days - half;
        for(int i = 0;i < odd;i++)
        {
            ans += pizzas[i];//此时取最大的几个
        }
        for (int i = 0; i < half; i++) 
        {
            ans += pizzas[odd + i * 2 + 1];//此时取的是除了要给最后一个之外的最大的几个数，每次跳着选就是为了选择次大的
        }
        return ans;
    }
};