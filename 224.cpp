#include "m.h"

class Solution 
{
public:
    int calculate(string s) 
    {
        int len = s.size();
        stack<int> stk;
        stack<char> op;
        for(int i = 0;i < len;)
        {
            if(s[i] == ' ')
            {
                i++;
                continue;
            }
            if(s[i] == '(')
            {
                int j, num = 0;
                for(j = i + 1;s[j] >= '0' && s[j] <= '9' && j < len;j++)
                {
                    num *= 10;
                    num += s[j] - '0';
                }
                stk.push(num);
                i = j;
                continue;
            }
            if(s[i] == ')')
            {
                char oper = op.top();
                op.pop();
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                if(oper == '+')
                {
                    stk.push(a + b);
                } 
                else
                {
                    stk.push(a - b);
                }
                i++;
                continue;
            }
            if(s[i] == '+' || s[i] == '-')
            {
                op.push(s[i]);
                i++;
                continue;
            }
            if(s[i] >= '0' && s[i] <= '9')
            {
                int j, num = 0;
                for(j = i;s[j] >= '0' && s[j] <= '9' && j < len;j++)
                {
                    num *= 10;
                    num += s[j] - '0';
                }
                stk.push(num);
                i = j;
            }
        }
        while(op.size())
        {
            char oper = op.top();
            op.pop();
            int a, b;
            if(stk.size())
            {
                b = stk.top();
                stk.pop();
            }
            if(stk.size())
            {
                a = stk.top();
                stk.pop();
            }
            else
            {
                a = 0;
            }
            if(oper == '+')
            {
                stk.push(a + b);
            } 
            else
            {
                stk.push(a - b);
            }
        }
        return stk.top();
    }
    //是此处计算顺序失误，应该是从前往后计算，使用数组模拟的栈会更好
};

int main()
{
    string s;
    char str[20];
    cin.getline(str, 20);
    s = str;
    cout << s << endl;
    Solution a;
    int r = a.calculate(s);
    cout << r << endl;
    system("pause");
    return 0;
}