#include "m.h"

class Solution 
{
private:
    int m;
    int n;
    int len;
    bool flag = false;
    string tmp;
    int vis[6][6] = {0};
    vector<vector<char>> grid;
    vector<vector<int>> dir = {
        {-1, 0}, // 上
        {1, 0},  // 下
        {0, -1}, // 左
        {0, 1}   // 右
    };
public:
    void dfs(int x, int y, int d)
    {
        if(d == len)
        {
            flag = true;
            return ;
        }
        int nx, ny;
        for(int i = 0;i < 4;i++)
        {
            nx = x + dir[i][0];
            ny = y + dir[i][1];
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && !vis[nx][ny] && grid[nx][ny] == tmp[d])
            {
                vis[nx][ny] = 1;
                dfs(nx, ny, d + 1);
                vis[nx][ny] = 0;
            }
        }
    }
    bool exist(vector<vector<char>>& board, string word) 
    {
        m = board.size(), n = board[0].size();
        len = word.size();
        tmp.assign(word.begin(), word.end());
        grid.assign(board.begin(), board.end());
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(board[i][j] == word[0])
                {
                    vis[i][j] = 1;
                    dfs(i, j, 1);
                    if(flag)
                    {
                        return flag;
                    }
                    vis[i][j] = 0;
                }
            }
        }
        return flag;
    }
};

int main()
{
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word = "ABCCED";
    Solution s;
    bool r = s.exist(board, word);
    return 0;
}