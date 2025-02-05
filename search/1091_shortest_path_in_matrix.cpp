#include "m.h"

class Solution 
{
private:
    int n;
    int res = 0;
    vector<vector<int>> g;
    queue<tuple<int, int, int>> q;
    tuple<int, int, int> tmp;
    int vis[100][100];
    int dir[8][2] = {
        {-1, 0},  // 上
        {1, 0},   // 下
        {0, -1},  // 左
        {0, 1},   // 右
        {-1, -1}, // 左上
        {-1, 1},  // 右上
        {1, -1},  // 左下
        {1, 1}    // 右下
    };
public:
    void bfs()
    {
        int x = 0, y = 0;
        int nx, ny;
        q.push({x, y, res});
        vis[x][y] = 1;
        while(!q.empty())
        {
            tmp = q.front();
            q.pop();
            x = get<0>(tmp);
            y = get<1>(tmp);
            res = get<2>(tmp);
            for(int i = 0;i < 8;i++)
            {
                nx = x + dir[i][0];
                ny = y + dir[i][1];
                if(nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny] && !g[nx][ny])
                {
                    if(nx == n - 1 && ny == n - 1)
                    {
                        res++;
                        return ;
                    }
                    vis[nx][ny] = 1;
                    q.push({nx, ny, res + 1});
                }
            }
        }
        res = -1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        g.assign(grid.begin(), grid.end());
        n = grid.size();
        bfs();
        return res;
    }
};