#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;
vector<int> a;
vector<int> b;
vector<long long> w;
vector<long long> pre_add_a(100001, 0);
vector<long long> pre_add_b(100001, 0);
long long maxx;
int offset = 0;

void minimum_energy(int t)
{
    maxx = 0;
    offset = b[t];
    for(int i = 1;i <= n;i++)
    {
        if(i >= t)
        {
            maxx = max(pre_add_a[i] - pre_add_b[i] + offset, maxx);
        }
        else
        {
            maxx = max(pre_add_a[i] - pre_add_b[i], maxx);
        }
    }
    w.push_back(maxx);
}

int main()
{
    cin >> n;
    int num = 0;
    for(int i = 0;i <= n;i++)
    {
        cin >> num;
        a.push_back(num);
        if(i > 0)
        {
            pre_add_a[i] = pre_add_a[i - 1] +  a[i];
        }
        else
        {
            pre_add_a[0] = a[0];
        }
    }
    b.push_back(0);
    for(int i = 1;i <= n;i++)
    {
        cin >> num;
        b.push_back(num);
        pre_add_b[i] = pre_add_b[i - 1] + b[i];
    }
    for(int i = 1;i <= n;i++)
    {
        minimum_energy(i);
    }
    for(int i = 0;i < n;i++)
    {
        cout << w[i] << ' ';
    }
    cout << endl;
    return 0;
}


#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
 
using namespace std;
 
int main () {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 0; i <= n; i++) {
		cin >> a[i];
	}
	vector<int> b(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	
	vector<int> sum(n + 1);//前缀和数组，相当于草稿纸上用到的wi
	vector<int> pre_max(n + 1);//前缀和的最大值 
	sum[0] = a[0];
	pre_max[0] = sum[0];
	for(int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i] - b[i];
		pre_max[i] = max(sum[i], pre_max[i - 1]);
	}
	vector<int> suf_max(n + 1);//后缀之中的的最大值 
	suf_max[n] = sum[n];
	for(int i = n - 1; i >= 1; i--) {
		suf_max[i] = max(sum[i], suf_max[i + 1]);
	}
	//输出结果 
	for(int i = 1; i <= n; i++) {
		int ans = max(pre_max[i - 1], suf_max[i] + b[i]);
		cout << ans << " ";
	}
	return 0;
}