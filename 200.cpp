#include "m.h"

class Solution 
{
public:
    int cnt = 0, m = 0, n = 0;
    int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    void dfs(int x,int y, vector<vector<char>>& grid, vector<vector<int>>& visited)
    {
        visited[x][y] = 1;
        for(int i = 0;i < 4;i++)
        {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if(nx >= 0 && nx <= m - 1 && ny >= 0 && ny <= n- 1 && visited[nx][ny] == 0 && grid[nx][ny] == '1')
            {
                dfs(nx, ny, grid, visited);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        m = grid.size(); n = grid[0].size();
        vector<vector<int>> visited = vector<vector<int>> (m, vector<int> (n, 0));
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(grid[i][j] == '1' && visited[i][j] == 0)
                {
                    cnt++;
                    dfs(i, j, grid, visited);
                }
            }
        }
        return cnt;
    }
};

int main()
{
    int m = 0, n = 0;
    vector<vector<char>> grid;
    cin >> m >> n;
    grid.resize(m);
    for(int i = 0;i < m;i++)
    {
        grid[i].resize(n);
    }
    for(int i = 0;i < m;i++)
    {
        for(int j = 0;j < n;j++)
        {
            cin >> grid[i][j];
        }
    }
    Solution s;
    int r = s.numIslands(grid);
    cout << "below here is the answer" << endl;
    cout << r << endl;
    system("pause");
    return 0;
}