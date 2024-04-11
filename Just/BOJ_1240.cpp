#include <bits/stdc++.h>
#define MAX 1001

using namespace std;

typedef struct
{
    int node;
    int dist;
}dataSet;

int n, m;
bool vis[MAX];
vector<dataSet> adj[MAX];

int bfs(int from, int to)
{
    queue<dataSet> q;
    q.push({from, 0});
    vis[from] = true;
    
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        if(cur.node == to) { return cur.dist; } // to에 방문시 종료

        for(auto nxt : adj[cur.node])
        {
            if(vis[nxt.node]) continue; // 재방문 방지
            q.push({nxt.node, cur.dist + nxt.dist});
            vis[nxt.node] = true;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n - 1; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }

    for(int i = 0; i < m; i++)
    {
        int from, to;
        cin >> from >> to;
        cout << bfs(from, to) << '\n';

        for(int i = 1; i <= n; i++) vis[i] = false;
    }

    return 0;
}