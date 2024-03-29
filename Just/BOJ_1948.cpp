#include <bits/stdc++.h>
#define MAX 10001
#define V first
#define T second

using namespace std;

/*

위상정렬로 최대시간 알아내고, 경로는 백트래킹

*/

void TopologicalSort();
void dfs(int node, int depth);

int n, m, s, e;
vector<pair<int, int>> graph[MAX];  // node, time
int indegree[MAX];
int longest_dist[MAX];
bool vis[MAX][MAX];
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
        indegree[v]++;
    }
    cin >> s >> e;

    TopologicalSort();
    dfs(1, 0);

    cout << cnt;
    
    cout << endl;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cout << vis[i][j] << ' ';
        }
        cout << endl;
    }

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

void dfs(int node, int depth)
{
    if(node == e) { cnt += depth; return ; }

    for(auto nxt : graph[node])
    {
        if(longest_dist[nxt.V] - longest_dist[node] == nxt.T)
        {
            if(vis[node][nxt.V]) dfs(nxt.V, depth);
            else { vis[node][nxt.V] = true; dfs(nxt.V, depth + 1); }
        }
    }
}