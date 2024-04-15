#include <bits/stdc++.h>
#define MAX 100001

using namespace std;

int n, m;
vector<int> adj[MAX];
int dp[MAX];

void dfs(int cur)
{
    for(auto nxt : adj[cur])
    {
        dp[nxt] += dp[cur];
        dfs(nxt);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        int v;
        cin >> v;

        if(v == -1) continue;
        adj[v].push_back(i);
    }

    for(int i = 0; i < m; i++)
    {
        int v, w;
        cin >> v >> w;
        if(dp[v] != 0) dp[v] += w;
        else dp[v] = w;
    }
    
    dfs(1);
    for(int i = 1; i <= n; i++) cout << dp[i] << ' ';

    return 0;
}