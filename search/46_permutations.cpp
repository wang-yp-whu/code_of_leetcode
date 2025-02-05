#include "m.h"

class Solution 
{
private:
    vector<vector<int>> res;
    vector<int> t;
    vector<int> tmp;
    int n;
    vector<int> vis = vector<int> (6, 0);
public:
    void dfs(int d)
    {
        if(d == n)
        {
            res.push_back(tmp);
            return ;
        }
        for(int i = 0;i < n;i++)
        {
            if(!vis[i])
            {
                vis[i] = 1;
                dfs(d);//不取这个数，继续向下走
                vis[i] = 0;

                tmp[d] = t[i];
                vis[i] = 1;
                dfs(d + 1);//取这个数
                vis[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        n = nums.size();
        tmp.resize(n, 0);
        t.assign(nums.begin(), nums.end());
        dfs(0);
        return res;
    }
};

//事实上，递归回溯已经有了采用/不采用的这种二义性
//因此，我没必要在代码里使用两个dfs函数来表示是否采用
class Solution 
{
public:
    vector<int> res;
    vector<int> st;

    void dfs(int u, int n, vector<int>& nums, vector<vector<int>>& ans)
    {
        // 当遍历到最后一位 存入一个结果 并返回
        if(u==n) 
        {
            ans.push_back(res);
            return;
        }
        // 遍历 递归
        for(int i=0;i<n;i++)
        {
            if(!st[i])
            {
                // 1.进去要修改：res加上一位；标记已使用
                st[i]=1;
                res.push_back(nums[i]);

                dfs(u+1, n, nums, ans);

                // 2.返回要复原：res去除一位；标记未使用（恢复现场）
                res.pop_back(); 
                st[i]=0;
            }
        }

    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        int n=nums.size();
        st = vector<int>(n, 0);
        vector<vector<int>> ans; 
        // 两个参数：到哪一位了u 以及 一共几位n
        dfs(0,n,nums,ans);
        return ans;
    }
};
