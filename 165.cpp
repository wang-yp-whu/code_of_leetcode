#include "m.h"

class Solution 
{
public:
    int compareVersion(string version1, string version2) 
    {
        int n = version1.length(), m = version2.length();
        int i = 0, j = 0;
        while (i < n || j < m) 
        {
            int x = 0;
            for (; i < n && version1[i] != '.'; ++i) 
            {
                x = x * 10 + version1[i] - '0';
            }
            ++i; // 跳过点号
            int y = 0;
            for (; j < m && version2[j] != '.'; ++j) 
            {
                y = y * 10 + version2[j] - '0';
            }
            ++j; // 跳过点号
            if (x != y) 
            {
                return x > y ? 1 : -1;
            }
        }
        return 0;
    }
};
//我一个一个地加数比较太麻烦了（i++，j++），不如这个题解，总体思路是一样的，但代码实现难度小

int main()
{
    string v1;
    string v2;
    cin >> v1;
    cin >> v2;
    Solution s;
    int r = s.compareVersion(v1, v2);
    cout << r << endl;
    system("pause");
    return 0;
}