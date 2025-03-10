#include "m.h"

class Solution 
{
private:
    vector<vector<char>> alpha = {
        {'a', 'b', 'c'},   // 2号按键
        {'d', 'e', 'f'},   // 3号按键
        {'g', 'h', 'i'},   // 4号按键
        {'j', 'k', 'l'},   // 5号按键
        {'m', 'n', 'o'},   // 6号按键
        {'p', 'q', 'r', 's'}, // 7号按键
        {'t', 'u', 'v'},   // 8号按键
        {'w', 'x', 'y', 'z'}, // 9号按键
    };
    string str;
    string tmp;
    vector<string> res;
    int n;
public:
    void dfs(int d)
    {
        if(d == n)
        {
            res.push_back(tmp);
            return ;
        }
        int num = str[d] - '2';
        for(int i = 0;i < alpha[num].size();i++)
        {
            tmp.push_back(alpha[num][i]);
            dfs(d + 1);
            tmp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) 
    {
        n = digits.size();
        str.assign(digits.begin(), digits.end());
        dfs(0);
        return res;
    }
};

int main()
{
    string digits = "79";
    Solution s;
    vector<string> r = s.letterCombinations(digits);
    for(int i = 0;i < r.size();i++)
    {
        cout << r[i] << endl;
    }
    return 0;
}