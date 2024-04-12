#include <bits/stdc++.h>
#define MAX 100001

using namespace std;

int n;
int idx = 1;
vector<int> adj[MAX];
int dfs_path[MAX];
int order[MAX];
bool vis[MAX];

bool cmp(int a, int b) { return dfs_path[a] < dfs_path[b]; }

void dfs(int node)
{
    vis[node] = true;
    dfs_path[idx++] = node;
    for(auto nxt : adj[node]) 
    {
        if(vis[nxt]) continue;
        dfs(nxt);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    cin >> n;
    for(int i = 1; i <= n - 1; i++)
    {
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> order[i];
        dfs_path[order[i]] = i;
    }
    if(order[1] != 1) { cout << 0; return 0; }

    for(int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end(), cmp);

    // solve
    dfs(1); // 계층방문을 통해, 각 계층별 노드 저장
    for(int i = 1; i <= n; i++)
        if(order[i] != dfs_path[i]) { cout << 0; return 0; }
    cout << 1;

    return 0;
}