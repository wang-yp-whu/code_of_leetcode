#include "m.h"

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n < 2) {
            return grid;
        }

        // 右上角三角形对角线非递减排序
        for (int i = 1; i < n; i++) {
            vector<int> tmp;
            int x = 0, y = i;
            while (x < n - i) {
                tmp.push_back(grid[x++][y++]);
            }
            sort(tmp.begin(), tmp.end()); // 非递减排序
            x = 0, y = i;
            for (int k = 0; k < tmp.size(); k++) {
                grid[x++][y++] = tmp[k];
            }
        }

        // 左下角三角形对角线非递增排序
        for (int i = 0; i < n; i++) {
            vector<int> tmp;
            int x = i, y = 0;
            while (x < n) {
                tmp.push_back(grid[x++][y++]);
            }
            sort(tmp.begin(), tmp.end(), greater<int>()); // 非递增排序
            x = i, y = 0;
            for (int k = 0; k < tmp.size(); k++) {
                grid[x++][y++] = tmp[k];
            }
        }

        return grid;
    }
};

class Solution 
{
public:
    vector< vector<int> > sortMatrix(vector< vector<int> >& grid) 
    {
        int n = grid.size();
        if(n < 2)
        {
            return grid;
        }
        vector<int> tmp;
        int x = 0;
        for(int i = 1;i < n;i++)
        {
            tmp.clear();
            x = i;
            for(int j = 0;j < n - i;j++)
            {
                tmp.push_back(grid[x++][j]);
            }
            sort(tmp.begin(), tmp.end());//右上角对角线需要非递减排列
            x = i;
            for(int k = 0;k < n - i;k++)
            {
                grid[x++][k] = tmp[k];
            }
        }
        for(int i = 0;i < n;i++)
        {
            tmp.clear();
            x = i;
            for(int j = 0;j < n - i;j++)
            {
                tmp.push_back(grid[x++][j]);
            }
            sort(tmp.begin(), tmp.end());
            reverse(tmp.begin(), tmp.end());//左下角对角线需要非递增排列，因此逆转
            x = i;
            for(int k = 0;k < n - i;k++)
            {
                grid[x++][k] = tmp[k];
            }
        }
        return grid;
    }
};

int main()
{
    vector< vector<int> > grid;
    grid.push_back({1, 7, 3});
    grid.push_back({9, 8, 2});
    grid.push_back({4, 5, 6});
    Solution s;
    grid = s.sortMatrix(grid);
    return 0;
}