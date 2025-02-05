#include "m.h"

class Solution 
{
private:
    int len;
    int num;
    int vis[20] = {0};
    vector<int> t;
    vector<vector<int>> res;
public:
    void dfs(int d)
    {
        if(d == num)
        {
            res.push_back(t);
            return;
        }
        for (int i = 0; i < len; i++)
        {
            if(!vis[i])
            {
                vis[i] = 1;
                t[d] = i + 1;
                dfs(d + 1);
                vis[i] = 0;
            }
        }
    }
    vector<vector<int>> combine(int n, int k) 
    {
        len = n, num = k;
        t.resize(n, 0);
        dfs(0);
        return res;
    }
};