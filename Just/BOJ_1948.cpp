#include <bits/stdc++.h>
#define MAX 10001
#define V first
#define T second

using namespace std;

/*

위상정렬로 최대시간 알아내고, 경로는 백트래킹

*/

void TopologicalSort();
int dfs(int u);

int n, m, s, e;
vector<pair<int, int>> graph[MAX];              // node, time
vector<pair<int, int>> reverse_graph[MAX];      // 백트래킹을 위한 그래프
int indegree[MAX];
int longest_dist[MAX];
bool vis[MAX];
int cnt;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v, t;
        cin >> u >> v >> t;
        graph[u].push_back({v, t});
        reverse_graph[v].push_back({u, t});
        indegree[v]++;
    }
    cin >> s >> e;

    TopologicalSort();
    cnt = dfs(e);

    cout << cnt;

    return 0;
}

void TopologicalSort()
{
    queue<int> q;
    for(int i = 1; i <= n; i++)
        if(indegree[i] == 0) q.push(i);
    
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();

        for(auto nxt : graph[cur])
        {
            longest_dist[nxt.V] = max(longest_dist[nxt.V], longest_dist[cur] + nxt.T);

            indegree[nxt.V]--;
            if(indegree[nxt.V] == 0) q.push(nxt.V);
        }
    }

    cout << longest_dist[e] << '\n';
}

int dfs(int u)
{
    vis[u] = true;
    int res = 0;
    for(auto nxt : reverse_graph[u])
    {
        int v = nxt.V; int t = nxt.T;
        if(longest_dist[u] == longest_dist[v] + t)
        {
            res++;
            if(!vis[v]) res += dfs(v);
        }
    }

    return res;
}