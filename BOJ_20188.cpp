#include <bits/stdc++.h>
#define MAX 300001

using namespace std;

typedef long long ll;

vector<int> adj[MAX];
int parent[MAX];
int n;
ll ans;

void dfs(int cur)
{
    ll child = 0LL;
    for(auto nxt : adj[cur])
    {
        if(nxt == parent[cur]) continue;
        child++;
        dfs(nxt);
    }
    ans += (child * (n - child));

    if(child == 0) ans += 1LL;
    else ans += (child * (child - 1LL)) / 2LL;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        parent[v] = u;
    }
    dfs(1);
    cout << ans;

    return 0;
}