#include "m.h"

class Solution 
{
public:
    int numDecodings(string s) 
    {
        int n = s.size();
        vector<int> dp(n, 0);
        if(s[0] != '0')
        {
            dp[0] = 1;
        }
        else
        {
            return 0;
        }
        for(int i = 1;i < n;i++)
        {
            if(s[i] == '0')
            {
                if(s[i - 1] == '0' || s[i - 1] > '2')
                {
                    return 0;
                }
                else
                {
                    if((s[i - 1] - '0') < 3)
                    {
                        if(i > 2)
                        {
                            dp[i] = dp[i - 2];
                        }
                        else
                        {
                            dp[i] = 1;
                        }
                    }
                }
                continue;
            }
            if(s[i - 1] != '0' && ((s[i - 1] - '0') * 10 + s[i] - '0' <= 26))
            {
                dp[i] = dp[i - 1] + 1;
            }
            else
            {
                dp[i] = dp[i - 1];
            }
        }
        return dp[n - 1];
    }
};//思路杂乱无章法，想到什么就是什么，特别容易遗漏条件

class Solution
{
public:
    int numDecodings(string s) 
    {
        int n = s.length();
        int prev = s[0] - '0';
        if (prev == 0) 
        {
            return 0;
        }
        if (n == 1) 
        {
            return 1;
        }
        vector<int> dp(n + 1, 1);
        for (int i = 2; i <= n; ++i) 
        {
            int cur = s[i - 1] - '0'; 
            if ((prev == 0 || prev > 2) && cur == 0) 
            {
                // 00, 30, 40, ..., 90, 非法。
                return 0;
            }        
            if ((prev < 2 && prev > 0) || (prev == 2 && cur <= 6)) 
            {
                // 10, 11, ..., 25, 26.
                if (cur == 0) 
                {
                    // 10, 20，只能连续解码两位。
                    dp[i] = dp[i - 2];
                } 
                else 
                {
                    // 可以解码当前位，也可以连续解码两位。
                    dp[i] = dp[i - 2] + dp[i - 1];
                }
            } 
            else 
            {
                // 合法，但只能解码当前位。
                dp[i] = dp[i - 1];
            }
            prev = cur;
        }
        return dp[n];
    }
};//和我的初版思路相同，但是我的并没有考虑全面

class Solution 
{
public:
    int numDecodings(string s)
    {
        int n = s.size();
        vector<int> f(n + 1);
        f[0] = 1;
        for (int i = 1; i <= n; ++i) 
        {
            if (s[i - 1] != '0') 
            {
                f[i] += f[i - 1];//末尾那个单独成一个就行
            }
            if (i > 1 && s[i - 2] != '0' && ((s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26)) 
            {
                f[i] += f[i - 2];//末尾那个可以和他前面的组成一个
            }
        }
        return f[n];
    }
};//思路就是看末尾到底是自己一个还是可以和前面的那个一起组队

int main()
{
    string s = "10";
    Solution t;
    int r = t.numDecodings(s);
    return 0;
}