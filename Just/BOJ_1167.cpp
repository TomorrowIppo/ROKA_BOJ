#include <bits/stdc++.h>
#define MAX 100001

/* 어떤 노드에서 dfs를 시작해도 가장 먼 곳은 정해져있다. */

using namespace std;

typedef struct
{
    int node;
    int dist;
}dataSet;

int v, res, endP;
vector<dataSet> adj[MAX];
bool vis[MAX];

void dfs(int cur, int dist)
{
    vis[cur] = true;
    for(auto nxt : adj[cur])
    {
        if(vis[nxt.node]) continue;
        
        if(res < dist + nxt.dist) { res = dist + nxt.dist; endP = nxt.node; }
        dfs(nxt.node, dist + nxt.dist);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v;
    for(int i = 1; i <= v; i++)
    {
        int u;
        cin >> u;
        while(true)
        {
            int v, d;
            cin >> v;
            
            if(v == -1) break;
            cin >> d;
            adj[u].push_back({v, d});
        }
    }
    dfs(1, 0);
    res = 0;
    for(int i = 1; i <= v; i++) vis[i] = false;
    dfs(endP, 0);
    cout << res;

    return 0;
}