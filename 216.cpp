#include "m.h"

class Solution 
{
private:
    vector<vector<int>> ans;
    vector<int> t;
    int kk, nn;
public:
    void dfs(int x, int step, int sum, int f)
    {
        if(x >= 5 || sum > nn)
        {
            return ;
        }
        /*if(step > kk)
        {
            return ;
        }*/
        if(step == kk)
        {
            if(sum == nn)
            {
                ans.push_back(t);
            }
            return ;
        }
        if(f)
        {
            sum += x;
            t[step] = x;
        }
        if(f)
        {
            dfs(x + 1, step + 1, sum, 1);
            dfs(x + 1, step + 1, sum, 0);
        }
        else
        {
            dfs(x + 1, step, sum, 1);
            dfs(x + 1, step, sum, 0);
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        if(n > ((19 - k) * k) / 2)
        {
            return ans;
        }
        kk = k, nn = n;
        t.resize(kk);
        //x step sum f
        //dfs(1, 0, 0, 0);
        dfs(1, 0, 0, 1);
        return ans;
    }
};

int main()
{
    int k, n;
    cout << "please input the numbers:" << endl;
    cin >> k >> n;
    Solution s;
    vector<vector<int>> r = s.combinationSum3(k, n);
    for(int i = 0;i < r.size();i++)
    {
        for(int j = 0;j < k;j++)
        {
            cout << r[i][j] << " ";
        }
        printf("\n");
    }
    system("pause");
    return 0;
}