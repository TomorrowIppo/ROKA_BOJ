#include <bits/stdc++.h>
#define MAX 1001

using namespace std;

int n, m;
vector<tuple<int, int, int>> edges;
int parent[MAX];
char sex[MAX];

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

    cin >> n >> m;
    for(int i = 1; i <= n; i++) { cin >> sex[i]; parent[i] = i; }
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }
    sort(edges.begin(), edges.end());

    int cnt = 0; 
    long long ans = 0LL;
    for(auto nxt : edges)
    {
        int u, v, w;
        tie(w, u, v) = nxt;

        if(find_root(u) == find_root(v)) continue;
        if(sex[u] == sex[v]) continue;

        merge(u, v);
        cnt++; ans += w;
        if(cnt == n - 1) break;
    }
    if(cnt == n - 1) cout << ans;
    else cout << -1;

    return 0;
}