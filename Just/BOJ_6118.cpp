#include <bits/stdc++.h>
#define MAX 20001
#define endl "\n"

using namespace std;

int n, m;
vector<int> graph[MAX];
int dist[MAX];

void solve();
tuple<int, int, int> bfs(int x);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}

void solve()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i = 1; i <= n; i++) dist[i] = -1;
    
    int num, max_dist, cnt;
    tie(num, max_dist, cnt) = bfs(1);

    cout << num << ' ' << max_dist << ' ' << cnt << endl;
}

tuple<int, int, int> bfs(int x)
{
    queue<int> q; q.push(x);
    dist[x] = 0;

    int num = 0;
    int max_dist = 0;
    int cnt = 0;

    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        for(auto nxt : graph[cur])
        {
            if(dist[nxt] >= 0) continue;    // 재방문 방지
            
        }
    }
}