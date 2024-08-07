#include <bits/stdc++.h>
#define MAX 1025

using namespace std;

typedef long long ll;

int n;
vector<tuple<int, int, int>> edges;
vector<int> adj[MAX];
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

    return x == y;
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
    
    // input
    cin >> n;
    for(int i = 1; i <= n; i++) parent[i] = i;

    for(int i = 1; i < n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            int dist;
            cin >> dist;
            edges.push_back({dist, i, j});
        }
    }
    sort(edges.begin(), edges.end());


    // solve
    int cnt = 0; ll ans = 0LL;
    for(auto edge : edges)
    {
        int u, v, w;
        tie(w, u, v) = edge;

        if(is_Union(u, v)) continue;
        merge(u, v);
        
        cnt++; ans += w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        if(cnt == n - 1) break;
    }
    for(int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());
    // cout << ans << "\n";
    
    for(int i = 1; i <= n; i++)
    {
        cout << adj[i].size() << " ";
        for(auto nxt : adj[i])
        {
            cout << nxt << " ";
        }
        if(i != n) cout << "\n";
    }

    return 0;
}