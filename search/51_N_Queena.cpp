#include "m.h"

class Solution 
{
private:
    int col[9] = {0};
    int row[9] = {0};
    int tan_1[18] = {0};
    int tan_2[18] = {0};
    int m;
    vector<vector<string>> r;
    vector<string> t;
public:
    bool is_legal(int x, int y)
    {
        return (!col[y] && !row[x] && !tan_1[x - y + m - 1] && !tan_2[y + x]);
    }
    void dfs(int d)
    {
        if(d == m)
        {
            r.push_back(t);
            return ;
        }
        for(int i = 0;i < m;i++)
        {
            if(is_legal(i, d))
            {
                t[i][d] = 'Q';
                row[i] = 1;
                col[d] = 1;
                tan_1[i - d + m - 1] = 1;
                tan_2[d + i] = 1;

                dfs(d + 1);

                row[i] = 0;
                col[d] = 0;
                tan_1[i - d + m - 1] = 0;
                tan_2[d + i] = 0;
                t[i][d] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        string tmp = string(n, '.');
        t = vector<string> (n, tmp);
        m = n;
        dfs(0);
        return r;
    }
};