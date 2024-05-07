#include <bits/stdc++.h>
#define MAX 100001
#define V first
#define W second
#define INF 987654321

using namespace std;

typedef long long ll;

int n, m, s, e;
ll ans = 0LL;
vector<tuple<int, int, int>> edges;
int parent[MAX];
vector<pair<int, ll>> adj[MAX];
bool vis[MAX];

bool cmp(tuple<int, int, int> a, tuple<int, int ,int> b)
{
    return (get<0>(a) > get<0>(b));
}

int find_root(int x)
{
    if(x == parent[x]) return x;
    return parent[x] = find_root(parent[x]);
}

bool is_Union(int x, int y)
{
    x = find_root(x);
    y = find_root(y);

    return x == y;
}

void merge(int x, int y)
{
    x = find_root(x);
    y = find_root(y);

    if(x > y) parent[x] = y;
    else parent[y] = x;
}

void dfs(int cur, ll dist)
{
    vis[cur] = true;
    if(cur == e) { ans = dist; return ; }

    for(auto nxt : adj[cur])
    {
        if(vis[nxt.V]) continue;
        dfs(nxt.V, min(dist, nxt.W));
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) parent[i] = i;
    cin >> s >> e;

    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }
    sort(edges.begin(), edges.end(), cmp);

    int cnt = 0;
    for(auto nxt : edges)
    {
        int u, v, w;
        tie(w, u, v) = nxt;

        if(is_Union(u, v)) continue;

        merge(u, v);
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});

        cnt++;
        if(cnt == n - 1) break;
    }
    dfs(s, INF);
    cout << ans;

    return 0;
}