#include <bits/stdc++.h>
#define MAX 1001

using namespace std;

int n, m;
int indegree[MAX];
vector<int> adj[MAX];
int dp[MAX];

void TopologicalSort()
{
    queue<int> q;
    for(int i = 1; i <= n; i++) 
        if(indegree[i] == 0) q.push(i);

    while(!q.empty())
    {
        auto cur = q.front(); q.pop();

        for(auto nxt : adj[cur])
        {
            indegree[nxt]--;
            if(indegree[nxt] == 0) q.push(nxt);

            dp[nxt] = max(dp[nxt], dp[cur] + 1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }

    // solve
    TopologicalSort();
    for(int i = 1; i <= n; i++) cout << dp[i] + 1 << ' ';

    return 0;
}