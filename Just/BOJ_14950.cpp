#include <bits/stdc++.h>
#define MAX 10001

using namespace std;

typedef long long ll;

int n, m, t;
int parent[MAX];
vector<tuple<ll, int, int>> edges;

int find_root(int x)
{
    if(x == parent[x]) return x;
    return parent[x] = find_root(parent[x]);
}

void merge(int x, int y)
{
    x = find_root(x);
    y = find_root(y);

    if(x > y) parent[x] = y;
    else parent[y] = x;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> t;
    for(int i = 1; i <= n; i++) parent[i] = i;

    for(int i = 0; i < m; i++)
    {
        int u, v;
        ll d;
        cin >> u >> v >> d;
        edges.push_back({d, u, v});
    }
    sort(edges.begin(), edges.end());

    ll ans = 0LL;
    int cnt = 0;
    for(auto nxt : edges)
    {
        int u, v;
        ll d;
        tie(d, u, v) = nxt;

        if(find_root(u) == find_root(v)) continue;

        merge(u, v);
        ans += (d + t * cnt++);

        if(cnt == n - 1) break;
    }
    cout << ans;

    return 0;
}