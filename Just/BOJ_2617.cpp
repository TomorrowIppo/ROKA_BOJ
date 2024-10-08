#include <bits/stdc++.h>
#define MAX 100
#define INF 987654321
#define endl "\n"

using namespace std;

int n, m;
int dist[MAX][MAX];
int reverse_dist[MAX][MAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            if(i == j) continue;

            dist[i][j] = INF;
            reverse_dist[i][j] = INF;
        }

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        
        dist[v][u] = 1;
        reverse_dist[u][v] = 1; 
    }


    int remain = (n - 1) / 2;
    int cnt = 0;

    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                reverse_dist[i][j] = min(reverse_dist[i][j], reverse_dist[i][k] + reverse_dist[k][j]);
            }
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(reverse_dist[i][j] == INF) cout << 'x' << ' ';
            else cout << reverse_dist[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}