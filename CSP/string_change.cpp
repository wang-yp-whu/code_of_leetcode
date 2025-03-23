#include "m.h"

int main()
{
    unordered_map<char, char> h;
    vector<int> nums;
    string s;
    getline(cin, s);
    int len = s.size();
    int n = 0;
    cin >> n;
    for(int i = 0;i <= n;i++)
    {
        string tmp;
        getline(cin, tmp);
        h[tmp[1]] = tmp[2];
    }
    int m;
    cin >> m;
    int num;
    for(int i = 0;i < m;i++)
    {
        cin >> num;
        nums.push_back(num);
    }
    int cnt;
    for(int i = 0;i < m;i++)
    {
        num = nums[i];
        string str = s;
        for(int j = 1;j < len - 1;j++)
        {
            cnt = 0;
            while(cnt < num && h.count(str[j]))
            {
                str[j] = h[str[j]];
                cnt++;
            }
        }
        cout << str << endl;
    }
    return 0;
}