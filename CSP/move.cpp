#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n = 0;
int k = 0;
int x;
int y;
vector<vector<int>> res;

void get_location(string str)
{
    int len = str.size();
    for(int i = 0;i < len;i++)
    {
        if(str[i] == 'f')
        {
            if(y + 1 <= n)
            {
                y += 1;
            }
        }
        else if(str[i] == 'b')
        {
            if(y - 1 >= 1)
            {
                y -= 1;
            } 
        }
        else if(str[i] == 'l')
        {
            if(x - 1 >= 1)
            {
                x -= 1;
            }
        }
        else if(str[i] == 'r')
        {
            if(x + 1 <= n)
            {
                x += 1;
            }
        }
    }
    res.push_back({x, y});
    x = y = 0;
}

int main()
{
    cin >> n >> k;
    for(int i = 0;i < k;i++)
    {
        string str;
        cin >> x >> y >> str;
        get_location(str);
    }
    for(int i = 0;i < res.size();i++)
    {
        cout << res[i][0] << ' ' << res[i][1] << endl;
    }
    return 0;
}
