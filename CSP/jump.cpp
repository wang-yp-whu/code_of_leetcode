#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

void ooo(int x)
{
    cout<< x << endl;
}

struct p
{
    int id, num;
};

const int xmmm=2e5+10;
int a[xmmm], b[xmmm], k[xmmm];
int dis[xmmm];
bool vis[xmmm];

int main()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=i-a[i];
    }

    for(int i=1;i<=n;i++)
        cin>>k[i];

    int pos=0;
    queue<p>q;
    q.push(p{1, 0});
    int ans=-1;

    while(!q.empty())
    {
        p t=q.front();
        q.pop();

        if(vis[t.id])
            continue;

        vis[t.id]=1;
        if(t.id==n)
        {
            ans=t.num;
            break;
        }

        int x=t.id;
        if(x+k[x]<=pos)
            continue;

        if(x+k[x]>=n)
        {
            q.push(p{n, t.num+1});
            continue;
        }

        for(int i=max(pos+1, x+1);i<=min(n, x+k[x]);i++)
        {
            q.push(p{b[i], t.num+1});//b[i]是提前计算好的，位置i处回退后落到的位置
        }
        pos=max(pos, x+k[x]);
        //pos维护的应该是一个左界限，我们要实现最小步数，至少应该在下一次不会退到比上一次还要靠后的位置
    }
    cout << ans << endl;
    return 0;
}