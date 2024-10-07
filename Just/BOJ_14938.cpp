#include <bits/stdc++.h>
#define endl "\n"
#define MAX 101
#define INF 987654321

using namespace std;

int n, m, r;
vector<int> adj[MAX];
int dist[MAX][MAX];
int item[MAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    cin >> n >> m >> r;
    for(int i = 1; i <= n; i++) cin >> item[i];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            dist[i][j] = (i == j) ? 0 : INF;

    for(int i = 0; i < r; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;

        adj[u].push_back(v);
        adj[v].push_back(u);
        dist[u][v] = d;
        dist[v][u] = d;
    }
    
    // Floyd-Warshall
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    int ans = 0;       
    for(int i = 1; i <= n; i++)
    {
        int sum = 0;
        for(int j = 1; j <= n; j++)
            sum += (dist[i][j] <= m) ? item[j] : 0;

        ans = max(ans, sum);
    }
    cout << ans;

    return 0;
}