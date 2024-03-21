#include "m.h"

class Solution 
{
public:
    vector<int> used;
    bool isok(int m)
    {
        for(int i = 0;i < used.size();i++)
        {
            if(used[i] == m)
            {
                return true;
            }
        }
        return false;
    }
    string fractionToDecimal(int numerator, int denominator) 
    {
        string s;
        string t;
        int r = numerator / denominator;
        int m = numerator % denominator;
        s = to_string(r);
        if(m == 0)
        {
            return s;
        }
        else
        {
            s = s + ".";
        }
        while(m)
        {
            if(isok(m))
            {
                r = (m * 10) / denominator;
                for(int i = 1;i < s.size();i++)
                {
                    if(s[i] - '0' == r)
                    {
                    t = s.substr(0, i) + '(' + s.substr(i,s.size() - i + 1) +')';
                    return t;
                    }
                }
            }
            used.push_back(m);
            r = (m * 10) / denominator;
            s = s + to_string(r);
            m = (m * 10) % denominator;
        }
        return s;
    }
};//唯独少了对于负数的处理

int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    Solution s;
    string str = s.fractionToDecimal(n1, n2);
    cout << str << endl;
    system("pause");
    return 0;
}