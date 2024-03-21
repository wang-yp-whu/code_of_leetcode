#include "m.h"

class Solution 
{
public:
    int numSquares(int n) 
    {
        vector<int> dp = vector<int> (n + 1, 0);
        for(int i = 1; i <= sqrt(n);i++)
        {
            dp[i * i] = 1;
        }
        //int j = 2;
        for(int i = 1;i <= n;i++)
        {
            if(dp[i])
            {
                continue;
            }
            dp[i] = i;
            for(int j = 1;j <= sqrt(i);j++)
            {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        
        return dp[n];
    }
};

int main()
{
    int n = 0;
    cin >> n;
    Solution s;
    int r = s.numSquares(n);
    cout << r << endl;
    system("pause");
    return 0;
}