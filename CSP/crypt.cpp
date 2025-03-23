#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int level(string password)
{
    bool alpha = false;
    bool digit = false;
    bool spe = false;
    bool twice = false;
    int capital[26] = {0};
    int little[26] = {0};
    int nums[10] = {0};
    int cnt_1 = 0;
    int cnt_2 = 0;
    int len = password.size();
    for(int i = 0;i < len;i++)
    {
        if(password[i] >= '0' && password[i] <= '9')
        {
            digit = true;
            nums[password[i] - '0']++;
            if(nums[password[i] - '0'] > 2)
            {
                twice = true;
            }
        }
        else if(password[i] >= 'A' && password[i] <= 'Z')
        {
            alpha = true;
            capital[password[i] - 'A']++;
            if(capital[password[i] - 'A'] > 2)
            {
                twice = true;
            }
        }
        else if(password[i] >= 'a' && password[i] <= 'z')
        {
            alpha = true;
            little[password[i] - 'a']++;
            if(little[password[i] - 'a'] > 2)
            {
                twice = true;
            }
        }
        else if(password[i] == '*')
        {
            cnt_1++;
            if(cnt_1 > 2)
            {
                twice = true;
            }
            spe = true;
        }
        else if(password[i] == '#')
        {
            cnt_2++;
            if(cnt_2 > 2)
            {
                twice = true;
            }
            spe = true;
        }
    }
    if(digit && alpha && spe)
    {
        if(!twice)
        {
            return 2;
        }
        return 1;
    }
    return 0;
}

int main()
{
    int n;
    cin >> n;;
    vector<string> str;
    for(int i = 0;i < n;i++)
    {
        string tmp;
        cin >> tmp;
        str.push_back(tmp);
    }
    int r = 0;
    for(int i = 0;i < n;i++)
    {
        r = level(str[i]);
        cout << r << endl;
    }
    return 0;
}

//另外有简单的代码如下，真的要善于使用STL
#include <iostream>
#include <unordered_map>
using namespace std;

int  main() {
	int n;
	cin >> n;
	while (n--) {
		string s;
		int level = 0;
		bool hasDigit = 0, hasTeshu = 0, hasAlpha = 0;
		bool isRepeated = 0;
		unordered_map<char,int>myset;
		cin >> s;
		for (const auto& ch : s) {
			myset[ch]++;
			if (myset[ch] > 2)
				isRepeated = 1;
			if (isalpha(ch))
				hasAlpha = 1;
			else if (isdigit(ch)) 
				hasDigit = 1;
			else 
				hasTeshu = 1;
		}

		if (hasAlpha && hasDigit && hasTeshu && !isRepeated)
			cout << 2 << endl;
		else if (hasAlpha && hasDigit && hasTeshu)
			cout << 1 << endl;
		else cout << 0 << endl;
	}
	return 0;
}