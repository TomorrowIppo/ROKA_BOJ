#include <bits/stdc++.h>
#define MAX 100001

#define dist first
#define num second

using namespace std;

typedef long long ll;

int n;
vector<tuple<ll, int, int>> edges;
vector<pair<int, int>> xvec;
vector<pair<int, int>> yvec;
vector<pair<int, int>> zvec;
int parent[MAX];

int find_root(int x)
{
    if(x == parent[x]) return x;
    return parent[x] = find_root(parent[x]);
}

bool is_Union(int x, int y)
{
    x = find_root(x);
    y = find_root(y);

    if(x == y) return true;
    else
    {
        if(x > y) parent[x] = y;
        else parent[y] = x;

        return false;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        parent[i] = i;

        ll x, y, z;
        cin >> x >> y >> z;
        xvec.push_back({x, i});
        yvec.push_back({y, i});
        zvec.push_back({z, i});
    }
    sort(xvec.begin(), xvec.end());
    sort(yvec.begin(), yvec.end());
    sort(zvec.begin(), zvec.end());

    for(int i = 0; i < n - 1; i++)
    {
        edges.push_back({xvec[i + 1].dist - xvec[i].dist, xvec[i].num, xvec[i + 1].num});
        edges.push_back({yvec[i + 1].dist - yvec[i].dist, yvec[i].num, yvec[i + 1].num});
        edges.push_back({zvec[i + 1].dist - zvec[i].dist, zvec[i].num, zvec[i + 1].num});
    }
    sort(edges.begin(), edges.end());

    int cnt = 0;
    ll ans = 0LL;
    for(auto nxt : edges)
    {
        ll dist;
        int u, v;
        tie(dist, u, v) = nxt;

        if(is_Union(u, v)) continue;

        cnt++; ans += dist;
        if(cnt == n - 1) break;
    }
    cout << ans;

    return 0;
}