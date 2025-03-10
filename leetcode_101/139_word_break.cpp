#include "m.h"

class Solution 
{
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        int n = s.size();
        string str;
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        for(int i = 0;i <= n;i++)
        {
            for(int j = 0;j <= i && j <= 20;j++)
            {
                str = s.substr(i - j, j);
                if(wordSet.count(str))
                {
                    dp[i] = dp[i - j];
                    if(dp[i])
                    {
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};

int main()
{
    string t = "leetcode";
    vector<string> word({"leet", "code"});
    Solution s;
    bool r = s.wordBreak(t, word);
    return 0;
}