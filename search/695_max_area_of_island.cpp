#include "m.h"

class Solution 
{
private:
    int v[50][50] = {0};
    vector<vector<int>> dir = {
        {-1, 0}, // 上
        {1, 0},  // 下
        {0, -1}, // 左
        {0, 1}   // 右
    };
    int maxx = 0;
    int m, n;
public:
    void dfs(vector<vector<int>>& grid, int x, int y, int s)
    {
        s++;
        int nx, ny;
        for(int i = 0;i < 4;i++)
        {
            nx = x + dir[i][0];
            ny = y + dir[i][1];
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && !v[nx][ny] && grid[nx][ny])
            {
                v[nx][ny] = 1;
                dfs(grid, nx, ny, s);
            }
        }
        if(s > maxx)
        {
            maxx = s;
        }
        return ;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        m = grid.size(), n = grid[0].size();
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(grid[i][j] == 1 && !v[i][j])
                {
                    v[i][j] = 1;
                    dfs(grid, i, j, 0);
                }
            }
        }
        return maxx;
    }
};

int maxAreaOfIsland(vector<vector<int>>& grid) {
    // direction数组用于表示四个方向：上、右、下、左
    vector<int> direction{-1, 0, 1, 0, -1};  // 上，右，下，左
    // 获取网格的行数和列数，以及最大岛屿面积的初始化值
    int m = grid.size(), n = grid[0].size(), max_area = 0;
    // 遍历整个网格
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            // 如果当前点是陆地（值为 1）
            if (grid[i][j] == 1) {
                // 初始化栈，用于存储岛屿的节点
                stack<pair<int, int>> island;               
                // 当前岛屿的面积从1开始（起始点已经算上了）
                int local_area = 1;
                // 将当前的陆地标记为水域，避免重复访问
                grid[i][j] = 0;  
                // 将起始点入栈
                island.push({i, j});           
                // 深度优先搜索（DFS）部分
                while (!island.empty()) {
                    // 获取栈顶元素，当前正在访问的节点
                    auto [r, c] = island.top();
                    island.pop();
                    
                    // 遍历四个方向（上、右、下、左）
                    for (int k = 0; k < 4; ++k) {
                        // 计算相邻节点的位置
                        int x = r + direction[k], y = c + direction[k + 1];                        
                        // 判断相邻节点是否在网格内，并且是否是陆地（值为 1）
                        if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                            // 增加当前岛屿的面积
                            ++local_area;                           
                            // 将当前陆地标记为水域，避免重复访问
                            grid[x][y] = 0;                            
                            // 将相邻的陆地节点入栈
                            island.push({x, y});
                        }
                    }
                }  
                // 更新最大岛屿面积
                max_area = max(max_area, local_area);
            }
        }
    }
    // 返回最大岛屿面积
    return max_area;
}