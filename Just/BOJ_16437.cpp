#include <bits/stdc++.h>
#define MAX 123456 + 1

using namespace std;

typedef long long ll

int n
ll res;
vector<int> adj[MAX];

ll island[MAX];

ll dfs(int cur, ll cnt)
{
    vis[cur] = true;
    for(auto nxt : adj[cur])
    {
        if(vis[nxt]) continue;  // 재방문 방지
        
        
        ll calc = cnt + island[nxt];

        if(cnt >= island[nxt]) island[nxt] = 0;
        
        dfs(nxt, calc);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    cin >> n;
    for(int u = 2; u <= n; u++)
    {
        char s; ll cnt; int v;
        cin >> s >> cnt >> v;

        if(s == 'W') cnt = -cnt;

        island[u] = cnt;
        adj[u].push_back(v);
    }

    res = dfs(1, 0);
    cout << res;

    return 0;
}