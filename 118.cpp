#include "m.h"

class Solution 
{
private:
    vector<vector<int>> ans;
public:
    vector<vector<int>> generate(int numRows) 
    {
        //ans.resize(numRows);
        vector<int> a = vector<int> (1, 1);
        vector<int> b = vector<int> (2, 1);
        if(numRows == 1)
        {
            ans.push_back(a);
        }
        else if(numRows == 2)
        {
            ans.push_back(a);
            ans.push_back(b);
        }
        else
        {
            ans.push_back(a);
            ans.push_back(b);
            for(int i = 3;i <= numRows; i++)
            {
                vector<int> c;
                vector<int> t = ans[ans.size() - 1];
                c.resize(i, 0);
                c[0] = c[i - 1] = 1;
                for(int j = 1;j <= i - 2;j++)
                {
                    c[j] = t[j - 1] + t[j];
                }
                ans.push_back(c);
            }
        }
        return ans;
    }
};

int main()
{
    int n = 0;
    cout << "please input the number:" << endl;
    cin >> n;
    vector<vector<int>> r;
    Solution s;
    r = s.generate(n);
    for(int i = 0; i < r.size(); i++)
    {
        for(int j = 0; j < r[i].size(); j++)
        {
            cout << r[i][j] << ' ' ;
        }
        cout << endl;
    }
    system("pause");
    return 0;
}