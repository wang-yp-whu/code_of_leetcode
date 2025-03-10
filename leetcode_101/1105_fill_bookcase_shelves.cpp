#include "m.h"

class Solution
{
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) 
    {
        int n = books.size();
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) 
        {
            int w = books[i - 1][0], h = books[i - 1][1];
            dp[i] = dp[i - 1] + h;
            for (int j = i - 1; j > 0; --j) 
            {
                //当前的这本书可能和其他的书放在同一行
                int prev_w = books[j - 1][0], prev_h = books[j - 1][1];
                w += prev_w;
                if (w > shelfWidth) 
                {
                    break;
                }
                h = max(h, prev_h);//得出这行目前的最大高度，h是在第二层循环中更新的
                dp[i] = min(dp[i], dp[j - 1] + h);
            }
        }
        return dp[n];
    }//总的来说，这是一个多循环的动态规划问题，我还是不太擅长
};