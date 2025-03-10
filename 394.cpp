#include "m.h"

string decodeString(const string &s) 
{
    stack<pair<string, int>> stk;
    string curStr;
    int curNum = 0;
    for (char ch : s) 
    {
        if (isdigit(ch)) 
        {
            // 处理多位数字
            curNum = curNum * 10 + (ch - '0');
        } 
        else if (ch == '[') 
        {
            // 遇到 '['，将当前状态压栈，并重置
            stk.push({curStr, curNum});
            curStr = "";
            curNum = 0;
        } 
        else if (ch == ']') 
        {
            // 遇到 ']'，从栈中取出上一次的状态，并重复当前字符串
            auto p = stk.top();
            stk.pop();
            string temp = p.first;
            for (int i = 0; i < p.second; ++i) 
            {
                temp += curStr;
            }
            curStr = temp;
        } 
        else 
        {
            // 字母直接添加到当前字符串
            curStr.push_back(ch);
        }
    }
    return curStr;
}