#include "m.h"

class Solution 
{
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) 
    {
        int m = groups.size();
        int n = elements.size();
        vector<int> res(m, -1);
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(groups[i] % elements[j] == 0)
                {
                    res[i] = j;
                    break;
                }
            }
        }
        return res;
    }
};//最后会超出时间限制

//更好的方法，类似于求解素数时的筛法
class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        int mx = ranges::max(groups);
        vector<int> target(mx + 1, -1);
        for (int i = 0; i < elements.size(); i++) {
            int x = elements[i];
            if (x > mx || target[x] >= 0) { // x 及其倍数一定已被标记，跳过
                continue;
            }
            for (int y = x; y <= mx; y += x) { // 枚举 x 的倍数 y
                if (target[y] < 0) { // 没有标记过
                    target[y] = i; // 标记 y 可以被 x 整除（记录 x 的下标）
                }
            }
        }
        // 回答询问
        for (int& x : groups) {
            x = target[x]; // 原地修改
        }
        return groups;
    }
};