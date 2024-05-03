#include <bits/stdc++.h>
#define MAX 100001

typedef long long ll;

using namespace std;

int n, m;
vector<tuple<int, int, int>> edges;
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

    cin >> n >> m;
    for(int i = 1; i <= n; i++) parent[i] = i;

    ll sum = 0LL;
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        sum += w;
        edges.push_back({w, u, v});
    }
    sort(edges.begin(), edges.end());

    ll ans = 0LL;
    int cnt = 0;
    for(auto nxt : edges)
    {
        int u, v, w;
        tie(w, u, v) = nxt;

        if(is_Union(u, v)) continue;

        cnt++; ans += w;
        if(cnt == n - 1) break;
    }
    if(cnt == n - 1) cout << sum - ans;
    else cout << -1;

    return 0;
}