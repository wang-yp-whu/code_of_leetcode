#include "m.h"

//新学到的差分思想，细细体会
class Solution
{
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) 
    {
        int n = trips.size();
        int d[1001] = {0};
        int cnt = 0;
        for(auto tmp : trips)
        {
            d[tmp[1]] += tmp[0];
            d[tmp[2]] -= tmp[0];
        }
        for(int i = 0;i < 1001;i++)
        {
            cnt += d[i];
            if(cnt > capacity)
            {
                return false;
            }
        }
        return true;
    }
};