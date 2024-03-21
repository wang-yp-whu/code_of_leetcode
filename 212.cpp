#include "m.h"

class Solution 
{
public:
    vector<string> ans;
    int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
    int m, n;
    bool flag = false;
    void dfs(vector<vector<char>>& board, string &s, int step, int x, int y)
    {
        if(step >= s.size() && !flag)
        {
            ans.push_back(s);
            flag = true;
            return ;
        }
        if(board[x][y] != s[step])
        {
            return ;
        }
        else
        {
            //step++;
            if(step + 1 >= s.size() && !flag)
            {
                ans.push_back(s);
                flag = true;
                return ;
            }
            for(int i = 0;i < 4;i++)
            {
                int nx = x + dir[i][0], ny = y + dir[i][1];
                if(nx >= 0 && nx <= m - 1 && ny >= 0 && ny <= n - 1)
                dfs(board, s, step + 1, nx, ny);
            }
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
    {
        m = board.size();
        n = board[0].size();
        for(int i = 0;i < words.size();i++)
        {
            for(int j = 0;j < m;j++)
            {
                for(int k = 0;k < n;k++)
                {
                    if(!flag && board[j][k] == words[i][0])
                    {
                        dfs(board, words[i], 0, j, k);
                    }
                }
            }
            flag = false;
        }
        return ans;
    }
};

int main()
{
    vector<vector<char>> board;
    vector<char> c = vector<char> (1, 'a');
    vector<string> words;
    board.push_back(c);
    words.push_back("a");
    Solution ans;
    vector<string> r = ans.findWords(board, words);
    for(int i = 0;i < r.size();i++)
    {
        cout << r[i] << endl;
    }
    system("pause");
    return 0;
}