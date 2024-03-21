#include <bits/stdc++.h>
#define MAX 10001

using namespace std;

int n;
int indegree[MAX];
vector<int> graph[MAX];
int dp[MAX];
int time_taken[MAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input & makeGraph
    cin >> n;
    for(int u = 1; u <= n; u++)
    {
        int t, m;
        cin >> t >> m;
        time_taken[u] = t;

        for(int j = 0; j < m; j++)
        {
            int v;
            cin >> v;
            graph[v].push_back(u);
            indegree[u]++;
        }
    }

    // solve
    queue<int> q;
    for(int i = 1; i <= n; i++)
    {
        if(indegree[i] == 0) q.push(i);
        dp[i] = time_taken[i];
    }
    
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        for(auto nxt : graph[cur])
        {
            indegree[nxt]--;
            if(indegree[nxt] == 0) q.push(nxt);
            
            dp[nxt] = max(dp[nxt], dp[cur] + time_taken[nxt]);
        }
    }
    
    int res = -1;
    for(int i = 1; i <= n; i++)
        res = max(res, dp[i]);
    
    cout << res;

    return 0;
}