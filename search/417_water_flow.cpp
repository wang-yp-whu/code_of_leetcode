#include "m.h"

class Solution 
{
private:
    int m;
    int n;
    int vis[200][200] = {0};
    int g1[200][200] = {0};
    vector<vector<int>> heightsCopy;
    vector<vector<int>> dir = {
        {-1, 0}, // 上
        {1, 0},  // 下
        {0, -1}, // 左
        {0, 1}   // 右
    };
public:
    void dfs(int x, int y)
    {
        int nx, ny;
        for(int i = 0;i < 4;i++)
        {
            nx = x + dir[i][0], ny = y + dir[i][1];
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && !vis[nx][ny] && heightsCopy[nx][ny] >= heightsCopy[x][y])
            {
                vis[nx][ny] = 1;
                g1[nx][ny] += 1;
                dfs(nx, ny);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        m = heights.size();
        n = heights[0].size();
        heightsCopy.assign(heights.begin(), heights.end());
        vector<vector<int>> res;
        for(int i = 0;i < n;i++)
        {
            //对能够流向太平洋的坐标进行遍历(上边)
            if(!vis[0][i])
            {
                vis[0][i] = 1;
                g1[0][i] += 1;
                dfs(0, i);
            }
        }
        for(int i = 0;i < m;i++)
        {
            //对能够流向太平洋的坐标进行遍历(左边)
            if(!vis[i][0])
            {
                vis[i][0] = 1;
                g1[i][0] += 1;
                dfs(i, 0);
            }
        }
        memset(vis, 0, sizeof(vis));
        for(int i = 0;i < m;i++)
        {
            //对能够流向大西洋的坐标进行遍历(右边)
            if(!vis[i][n - 1])
            {
                vis[i][n - 1] = 1;
                g1[i][n - 1] += 1;
                dfs(i, n - 1);
            }
        }
        for(int i = 0;i < n;i++)
        {
            //对能够流向大西洋的坐标进行遍历(下边)
            if(!vis[m - 1][i])
            {
                vis[m - 1][i] = 1;
                g1[m - 1][i] += 1;
                dfs(m - 1, i);
            }
        }
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(g1[i][j] == 2)
                {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> heights = {
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4}
    };
    Solution s;
    vector<vector<int>> r = s.pacificAtlantic(heights);
    return 0;
}