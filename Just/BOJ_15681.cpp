#include <bits/stdc++.h>
#define MAX 100001

using namespace std;

int n, r, q;
int dp[MAX];
int parent[MAX];
vector<int> adj[MAX];

void make_tree(int cur, int p)
{
    parent[cur] = p;
    for(auto nxt : adj[cur])
    {
        if(nxt == p) continue;  // 부모노드 재방문 방지
        make_tree(nxt, cur);
    }
}

void dfs(int cur)
{
    for(auto nxt : adj[cur])
    {
        if(nxt == parent[cur]) continue;    // 부모노드 재방문 방지
        dfs(nxt);
        dp[cur] += dp[nxt];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> r >> q;
    for(int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= n; i++) dp[i] = 1;
    make_tree(r, -1);
    dfs(r);

    for(int i = 0; i < q; i++)
    {
        int inp;
        cin >> inp;
        cout << dp[inp] << '\n';
    }

    return 0;
}
