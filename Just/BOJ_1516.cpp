#include <bits/stdc++.h>
#define MAX 501

using namespace std;

void solve();

int n;
int indegree[MAX];
vector<int> graph[MAX];
int dp[MAX];
int time_taken[MAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int v;
        cin >> time_taken[i];
        
        while(true)
        {
            int v;
            cin >> v;
            
            if(v == -1) break;
            else { graph[v].push_back(i); indegree[i]++; }
        }
    }

    // solve
    solve();

    return 0;
}

void solve()
{
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
            dp[nxt] = max(dp[nxt], dp[cur] + time_taken[nxt]);

            indegree[nxt]--;
            if(indegree[nxt] == 0) q.push(nxt);
        }
    }

    for(int i = 1; i <= n; i++) cout << dp[i] << '\n';
}