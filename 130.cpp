#include "m.h"

class Solution 
{
private:
    int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
    int flag = 0;
    int m = 0, n = 0;
public:
    void dfs(vector<vector<char>>& board,int i, int j,vector<vector<int>>& visited)
    {
        for(int k = 0; k < 4; k++)
        {
            int nx = i + dir[k][0], ny = j + dir[k][1];
            if(nx >= 0 && nx <= m - 1 && ny >= 0 && ny <= n - 1 && board[nx][ny] == 'O' && visited[nx][ny] == 0)
            {
                visited[nx][ny] = 1;
                if(nx == 0 || nx == m - 1 || ny == 0 || ny == n - 1)
                {
                    flag = 1;
                    return ;
                }
                else
                {
                    dfs(board, nx, ny, visited);
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) 
    {
        m = board.size();
        n = board[0].size();
        vector<vector<int>> visited;
        visited.resize(m);
        for(int i = 0; i < m;i++)
        {
            visited[i].resize(n, 0);
        }
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n;j++)
            {
                if(board[i][j] == 'O' && i != 0 && i != m - 1 && j != 0 && j != n - 1)
                {
                    flag = 0;
                    for(int a = 0; a < m; a++)
                    {
                        board[a].resize(n, 0);
                    }//I HAVE ALREADY RENEWED THE DATA, BUT WHY?
                    visited[i][j] = 1;
                    dfs(board, i, j, visited);
                    if(flag == 0)
                    {
                        board[i][j] = 'X';
                    }
                }
            }
        }
    }
};

int main()
{
    vector<vector<char>> board;
    board.resize(5);
    for(int i = 0; i < 5;i++)
    {
        board[i].resize(5);
    }
    char c;
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5;j++)
        {
            cin >> c;
            board[i][j] = c;
        }
    }
    for(int i = 0; i < 5;i++)
    {
        for(int j = 0; j < 5;j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    Solution s;
    s.solve(board);
    for(int i = 0; i < 5;i++)
    {
        for(int j = 0; j < 5;j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}