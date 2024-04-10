#include <bits/stdc++.h>
#define MAX 10001

using namespace std;

/* (1)루트로 부터 가장 먼곳 + (1)으로부터 가장 먼 곳 */

void dfs(int cur, int len);

typedef struct
{
    int node;
    int weight;
}dataSet;

vector<dataSet> adj[MAX];
bool vis[MAX];
int n, end_point, res;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int p, c, w;
        cin >> p >> c >> w;
        adj[p].push_back({c, w});
        adj[c].push_back({p, w});
    }
    
    // solve
    dfs(1, 0);
    for(int i = 1; i <= n; i++) vis[i] = false; // reset
    dfs(end_point, 0);

    cout << res;

    return 0;
}

void dfs(int cur, int len)
{
    vis[cur] = true;
    for(auto nxt : adj[cur])
    {
        if(vis[nxt.node]) continue;

        if(len + nxt.weight > res) { res = len + nxt.weight; end_point = nxt.node; }
        dfs(nxt.node, len + nxt.weight);
    }
}