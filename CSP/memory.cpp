#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
#define LL long long
#define pr std::pair
#define mp std::make_pair

const int kN = 1e5 + 10;
int n, N, q, nowtime;
std::map<int, int> tim, modified;
std::set<int> have[kN];
std::set<pr <int, int> > lru[kN];

void pop(int id_) 
{
    if (have[id_].size() < n) return ;
    auto it = lru[id_].begin();
    if (modified[it->second]) 
    {
        std::cout << 1 << " " << it->second << "\n";
        modified[it->second] = 0;
    }
    have[id_].erase(it->second);
    lru[id_].erase(it);
}

void insert(int id_, int pos_) 
{
    have[id_].insert(pos_);
    tim[pos_] = nowtime;
    lru[id_].insert(mp(nowtime, pos_));
    std::cout << 0 << " " << pos_ << "\n";
}

void solve(int pos_) 
{
    ++ nowtime;
    int id = (pos_ / n) % N;
    if (have[id].count(pos_)) 
    {
        lru[id].erase(lru[id].find(mp(tim[pos_], pos_)));
        tim[pos_] = nowtime;
        lru[id].insert(mp(nowtime, pos_));
        return ;
    }
    if (have[id].size() == n) pop(id);
    insert(id, pos_);
}

int main() 
{
    std::ios::sync_with_stdio(0); std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> N >> q;
    while (q --) 
    {
        int o, a; 
        std::cin >> o >> a;
        solve(a);
        if (o == 1) 
            modified[a] = 1;
    }
    return 0;
}