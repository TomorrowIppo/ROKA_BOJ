#include <bits/stdc++.h>
#define MAX 1000001

using namespace std;

int n, cnt;
vector<int> graph[MAX];
bool vis[MAX];
int dp[MAX][2];

void solve(int cur)
{
    vis[cur] = true;
    dp[cur][1] = 1;
    for(auto nxt : graph[cur])
    {
        if(vis[nxt]) continue;

        solve(nxt);
        dp[cur][0] += dp[nxt][1];
        dp[cur][1] += min(dp[nxt][0], dp[nxt][1]);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n - 1; i++)
    {
        int u, v;  
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    solve(1);
    cout << min(dp[1][0], dp[1][1]) << endl;

    return 0;
}