#include "m.h"

class Solution 
{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> st;
        st.push(0);
        for(int i = 1;i < n;i++)
        {
            while(!st.empty() && temperatures[i] > temperatures[st.top()])
            {
                res[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> t = {73,74,75,71,69,72,76,73};
    vector<int> r = s.dailyTemperatures(t);
    return 0;
}