#include "m.h"

/*
输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"
解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'
*/

class Solution 
{
private:
    vector<int> hash = vector<int> (128, 0);
    vector<bool> v = vector<bool> (128, false);
    //使用128是因为大小写都有
    //ASCII码一共128个
public:
    string minWindow(string s, string t) 
    {
        int m = s.size(), n = t.size();
        for(int i = 0;i < n;i++)
        {
            v[t[i]] = true;
            hash[t[i]]++;
        }
        int left = -1, right = -1;
        int ml = -1, min_lenth = -1;
        int count = 0;
        for(left = 0, right = 0;right < m;right++)
        {
            if(!v[s[right]])
            {
                continue;
            }
            if(--hash[s[right]] > 0)
            {
                //之所以这样写，是因为达到负数就不需要count变化了
                //但是hash数组还需要变化，可以表示超过了多少个
                count++;
            }
            while(count == n)
            {
                //此时已经将t中的字符全部包括，接下来要更改滑动窗口的大小
                if(ml == -1 || right - left + 1 < min_lenth)
                {
                    ml = left;
                    min_lenth = right - left + 1;
                }
                if(v[s[left]] && ++hash[s[left]] > 0)
                {
                    count--;
                }
                left++;
            }
        }
        return min_lenth == -1? "" : s.substr(ml, min_lenth);
    }
};