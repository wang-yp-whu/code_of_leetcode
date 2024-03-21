#include "m.h"

class Solution 
{
public:
    int evalRPN(vector<char>& tokens) 
    {
        int len = tokens.size();
        if(len == 1)
        {
            char t = tokens[0];
            return (t - '0');
        }
        stack<int> s;
        stack<char> stk;
        for(int i = 0; i < len;i++)
        {
            if(tokens[i] >= '0' && tokens[i] <= '9')
            {
                s.push(tokens[i] - '0');
            }
            else
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                if(tokens[i] == '*')
                {
                    s.push(b * a);
                }
                else if(tokens[i] == '/')
                {
                    s.push(b / a);
                }
                else if(tokens[i] == '+')
                {
                    s.push(a + b);
                }
                else
                {
                    s.push(b - a);
                }
            }
        }
        return s.top();
    }
};

int main()
{
    vector<char> t;
    char c;
    cout << "please input the chars:" << endl;
    cin >> c;
    while(c != 'q')
    {
        t.push_back(c);
        cin >> c;
    }
    Solution s;
    int r = s.evalRPN(t);
    cout << r << endl;
    system("pause");
    return 0;
}