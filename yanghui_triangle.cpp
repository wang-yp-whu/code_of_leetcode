#include "m.h"

class Solution 
{
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> res;
        for(int i = 0;i < numRows;i++)
        {
            vector<int> tmp(i + 1, 0);
            if(i == 0)
            {
                tmp[0] = 1;
            }
            else
            {
                tmp[0] = tmp[i] = 1;
                for(int j = 1;j <= i - 1;j++)
                {
                    tmp[j] = res[i - 1][j - 1] + res[i - 1][j];
                }
            }
            res.push_back(tmp);  
        }
        return res;
    }
};

class Solution 
{
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> res;
        for(int i = 0;i < numRows;i++)
        {
            vector<int> tmp(i + 1, 0);
            tmp[0] = tmp[i] = 1;
            for(int j = 1;j <= i - 1;j++)
            {
                tmp[j] = res[i - 1][j - 1] + res[i - 1][j];
            }
            res.push_back(tmp);  
        }
        return res;
    }
};//这样的话一次分支判断都不需要，最简单

int main()
{
    int rows = 5;
    Solution s;
    vector<vector<int>> r = s.generate(rows);
    return 0;
}