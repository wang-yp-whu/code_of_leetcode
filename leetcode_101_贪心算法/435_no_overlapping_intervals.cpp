#include "m.h"

bool compare(vector<int> &a, vector<int> &b)
{
    return a[0] < b[0];
}

class Solution 
{
private:
    vector< vector<int> > tmp;
public:
    int eraseOverlapIntervals(vector< vector<int> >& intervals) 
    {
        int n = intervals.size();
        if(n < 2)
        {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), compare);
        int res = 0;
        int left_bound = intervals[0][0];
        int right_bound = intervals[0][1];
        for(int i = 1;i < n;i++)
        {
            if(intervals[i][0] == left_bound)
            {
                if(intervals[i][1] <= right_bound)
                {
                    right_bound = intervals[i][1];
                }
                res++;
            }
            else
            {
                tmp.push_back({left_bound, right_bound});
                left_bound = intervals[i][0], right_bound = intervals[i][1];
            }
            if(intervals[i][0] != left_bound || i == n - 1)
            {
                tmp.push_back({left_bound, right_bound});
            }
        }
        int len = tmp.size();
        right_bound = tmp[0][1];
        for(int i = 1;i < len;i++)
        {
            if(tmp[i][0] < right_bound)
            {
                res++;
                right_bound = min(right_bound, tmp[i][1]);
            }
            else
            {
                right_bound = tmp[i][1];
            }
        }
        return res;
    }
};

class Solution2 
{
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        if (intervals.empty()) 
        {
            return 0;
        }
        
        sort(intervals.begin(), intervals.end(), [](const auto& u, const auto& v) 
        {
            return u[1] < v[1];
        });

        int n = intervals.size();
        int right = intervals[0][1];
        int ans = 1;
        for (int i = 1; i < n; ++i) 
        {
            if (intervals[i][0] >= right) 
            {
                ++ans;
                right = intervals[i][1];
            }
        }
        return n - ans;
    }
};

int main()
{
    vector< vector<int> > a = {
    {-52, 31}, 
    {-73, -26}, 
    {82, 97}, 
    {-65, -11}, 
    {-62, -49}, 
    {95, 99}, 
    {58, 95}, 
    {-31, 49}, 
    {66, 98}, 
    {-63, 2}, 
    {30, 47}, 
    {-40, -26}};
    Solution s;
    int r = s.eraseOverlapIntervals(a);
    cout << r << endl;
    return 0;
}