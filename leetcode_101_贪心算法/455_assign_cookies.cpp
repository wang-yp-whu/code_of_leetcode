#include "m.h"

//O(m * n)
// class Solution 
// {
// public:
//     int findContentChildren(vector<int>& g, vector<int>& s) 
//     {
//         int m = g.size();
//         int n = s.size();
//         if(!n)
//         {
//             return 0;
//         }
//         sort(g.begin(), g.end());
//         sort(s.begin(), s.end());
//         if(g[0] > s[n - 1])
//         {
//             return 0;
//         }
//         int res = 0;
//         int loc = 0;
//         for(int i = 0;i < m;i++)
//         {
//             for(int j = loc;j < n;j++)
//             {
//                 if(g[i] <= s[j])
//                 {
//                     res++;
//                     loc = j + 1;
//                     break;
//                 }
//             }
//         }
//         return res;
//     }
// };

//O(max(m, n))
class Solution 
{
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        int m = g.size();
        int n = s.size();
        if(!n)
        {
            return 0;
        }
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        if(g[0] > s[n - 1])
        {
            return 0;
        }
        int res = 0;
        int j = 0;
        for(int i = 0;i < m && j < n;)
        {
            if(g[i] <= s[j])
            {
                i++;
                res++;
            }
            j++;
        }
        return res;
    }
};

int main()
{
    vector<int> g;
    vector<int> s;
    return 0;
}