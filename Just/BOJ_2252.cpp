#include <bits/stdc++.h>
#define MAX 32001

using namespace std;

int n, m;
vector<int> graph[MAX];
int indegree[MAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        indegree[v] += 1;
    }

    queue<int> q;
    for(int i = 1; i <= n; i++)
        if(indegree[i] == 0) q.push(i);
    
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        cout << cur << ' ';

        for(auto nxt : graph[cur])
        {
            indegree[nxt] -= 1;
            if(indegree[nxt] == 0) q.push(nxt);
        }
    }

    return 0;
}