#include <bits/stdc++.h>
#define MAX 100001

using namespace std;

typedef struct
{
    int node;
    int depth;
}dataSet;

int n;
vector<int> adj[MAX];
vector<int> lv[MAX];
int cmp[MAX];
bool vis[MAX];

void bfs(int node)
{
    queue<dataSet> q;
    q.push({node, 1});
    vis[node] = true;

    while(!q.empty())
    {
        auto cur = q.front(); q.pop();

        lv[cur.depth].push_back(cur.node);
        for(auto nxt : adj[cur.node])
        {
            if(vis[nxt]) continue;
            vis[nxt] = true;
            q.push({nxt, cur.depth + 1});
        }
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
        cin >> cmp[i];

    // solve
    bfs(1); // 계층방문을 통해, 각 계층별 노드 저장
    for(int i = 1; i <= n; i++) 
    {   
        cout << "Lv." << i << ": ";
        for(auto nxt : lv[i])
            cout << nxt << ' ';
        cout << '\n';
    }

    return 0;
}