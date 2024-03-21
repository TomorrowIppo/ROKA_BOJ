#include <bits/stdc++.h>
#define MAX 32001

using namespace std;

void solve();

int n, m;
int indegree[MAX];
vector<int> graph[MAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input & make Graph
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        indegree[v]++;
    }
    
    // solve
    solve();

    return 0;
}

void solve()
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 1; i <= n; i++)
        if(indegree[i] == 0) pq.push(i);
    
    while(!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        cout << cur << ' ';

        for(auto nxt : graph[cur])
        {
            indegree[nxt]--;
            if(indegree[nxt] == 0) pq.push(nxt);
        }
    }
}