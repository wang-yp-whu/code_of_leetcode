#include "m.h"

class Solution 
{
private:
    int n;
    int r;
    queue<pair<int, int>> points;
    vector<vector<int>> g;
    vector<vector<int>> dir = {
        {-1, 0}, // 上
        {1, 0},  // 下
        {0, -1}, // 左
        {0, 1}   // 右
    };
public:
    void dfs(int x, int y)
    {
        if(!g[x][y])
        {
            points.push({x, y});//作为BFS的最外层
            return ;
        }
        g[x][y] = 2;
        int nx, ny;
        for(int i = 0;i < 4;i++)
        {
            nx = x + dir[i][0];
            ny = y + dir[i][1];
            if(nx >= 0 && nx < n && ny >= 0 && ny < n && g[nx][ny] != 2)
            {
                dfs(nx, ny);
            }
        }
        return ;
    }
    int bfs()
    {
        int d = 0;
        int len = 0;
        int nx, ny;
        pair<int, int> tmp;
        while(!points.empty())
        {
            d++;
            len = points.size();
            while(len--)
            {
                tmp = points.front();
                points.pop();
                for(int i = 0;i < 4;i++)
                {
                    nx = tmp.first + dir[i][0];
                    ny = tmp.second + dir[i][1];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < n)
                    {
                        if(g[nx][ny] == 2)
                        {
                            continue;
                        }
                        else if(g[nx][ny] == 1)
                        {
                            return d;
                        }
                        else
                        {
                            g[nx][ny] = 2;
                            points.push({nx, ny});
                        }
                    }
                }
            }
        }
        return d;
    }
    int shortestBridge(vector<vector<int>>& grid) 
    {
        n = grid.size();
        g.assign(grid.begin(), grid.end());
        bool f = true;
        for(int i = 0;i < n && f;i++)
        {
            for(int j = 0;j < n && f;j++)
            {
                if(grid[i][j])
                {
                    dfs(i, j);
                    f = false;
                    break;
                }
            }
        }
        r = bfs();
        return r;
    }
};

int main()
{
    vector<vector<int>> grid = {{0, 1, 0}, {0, 0, 0}, {0, 0, 1}};
    Solution s;
    int r = s.shortestBridge(grid);
    return 0;
}