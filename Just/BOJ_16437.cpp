#include <bits/stdc++.h>
#define MAX 123456 + 1

using namespace std;

typedef long long ll;

int n;
ll res;
vector<int> adj[MAX];
ll island[MAX];

ll dfs(int cur)
{
    if(adj[cur].size() == 0)
    {
        if(island[cur] > 0) return island[cur];
        else return 0;
    }

    ll sum = 0;
    sum += island[cur];

    for(auto nxt : adj[cur])
    {
        sum += dfs(nxt);
    }

    if(sum < 0) return 0;
    return sum;
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
        adj[v].push_back(u);
    }

    res = dfs(1);
    cout << res;

    return 0;
}