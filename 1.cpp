#include "m.h"

class Solution 
{
public:
    bool hasSpecialSubstring(string s, int k) 
    {
        int n = s.size();
        if(n < k)
        {
            return false;
        }
        if(n == 1)
        {
            return true;
        }
        int cnt = 0;
        for(int i = 0;i <= n - k;i++)
        {
            cnt = 0;
            string tmp = s.substr(i, k);
            if(i == 0 || (i > 0 && s[i - 1] != s[i]))
            {
                cnt++;
            }
            else
            {
                continue;
            }
            if(i == n - k || (i < n - k && s[i + k - 1] != s[i + k]))
            {
                cnt++;
            }
            else
            {
                continue;
            }
            for(int j = 0;j < tmp.size();j++)
            {
                if(tmp[j] != tmp[0])
                {
                    break;
                }
                if(j == tmp.size() - 1)
                {
                    cnt++;
                }
            }
            if(cnt == 3)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    string str = "jkjhfgg";
    int k = 2;
    Solution s;
    bool r = s.hasSpecialSubstring(str, k);
    return 0;
}