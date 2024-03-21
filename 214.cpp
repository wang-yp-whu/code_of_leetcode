#include "m.h"

class Solution 
{
public:
    string shortestPalindrome(string s) 
    {
        int n = s.size();
        if(n == 1)
        {
            return s;
        }
        int loc = 0, ans = 0x7fffffff, sum = 0;
        int mid = (n - 1) / 2, j = 0;
        for(;mid >= 0;mid--)
        {
            sum = (n - 1 - 2 * mid) * 2;
            for(j = 1;j <= mid;j++)
            {
                if(s[mid - j] != s[mid + j])
                {
                    sum += 2 * mid;
                    break;
                }
            }
            if(sum < ans && j > mid)
            {
                ans = sum;
                loc = mid;
            }
        }
        string t = s.substr(loc + 1);
        string r = s[loc] + t;
        reverse(t.begin(), t.end());
        r = t + r;
        return r;
    }
};

int main()
{
    string s;
    cout << "please input the str:" << endl;
    cin >> s;
    Solution q;
    string r = q.shortestPalindrome(s);
    cout << r << endl;
    system("pause");
    return 0;
}