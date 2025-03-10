#include "m.h"

class Solution 
{
private:
    int m;
    int n;
    vector<vector<char>> g;
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
            nx = x + dir[i][0];
            ny = y + dir[i][1];
            if(nx >= 0 && ny >= 0 && nx < m && ny < n && g[nx][ny] == '1')
            {
                g[nx][ny] = '0';
                dfs(nx, ny);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        m = grid.size(), n = grid[0].size();
        g.assign(grid.begin(), grid.end());
        int cnt = 0;
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(g[i][j] == '1')
                {
                    cnt++;
                    dfs(i, j);
                }
            }
        }
        return cnt;
    }
};

int main()
{
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };
    Solution s;
    int r = s.numIslands(grid);
    cout << r << endl;
    return 0;
}