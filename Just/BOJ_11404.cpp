#include<bits/stdc++.h>
#define INF 987654321
#define MAX 101
#define endl "\n"

using namespace std;

int n, m;
int adj[MAX][MAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            if(i == j) adj[i][j] = 0;
            else adj[i][j] = INF;
        }
    
    for(int i = 0; i < m; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;

        adj[u][v] = min(adj[u][v], d);
    }

    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(adj[i][j] > adj[i][k] + adj[k][j])
                    adj[i][j] = adj[i][k] + adj[k][j];
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(adj[i][j] == INF) cout << 0 << ' ';
            else cout << adj[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}