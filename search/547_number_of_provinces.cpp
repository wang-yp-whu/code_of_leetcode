#include "m.h"

class Solution 
{
private:
    int n;
    int vis[200] = {0};
public:
    void dfs(vector<vector<int>>& isConnected, int seq)
    {
        vis[seq] = 1;
        for(int i = 0;i < n;i++)
        {
            if(isConnected[i][seq] && !vis[i])
            {
                vis[i] = 1;
                dfs(isConnected, i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        n = isConnected.size();
        int cnt = 0;
        for(int i = 0;i < n;i++)
        {
            if(!vis[i])
            {
                cnt++;
                dfs(isConnected, i);
            }
        }
        return cnt;
    }
};