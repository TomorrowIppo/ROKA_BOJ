#include <bits/stdc++.h>
#define MAX 100
#define INF 987654321
#define endl "\n"

using namespace std;

/*

Floyd-Warshall을 통해 ligth to heavy 그래프와 heavy to light 그래프에서의 dist 배열을 만든다.
각각 dist[Start]와 reverse_dist[Start]를 순회해서 0 or INF가 아닌 값의 개수가 
자기보다 앞 혹은 뒤에있는 구슬의 개수이다. 

이 개수가 (n - 1) / 2 보다 크다면 중앙에 위치할 수 없다는 뜻이다.

*/

int n, m;
int dist[MAX][MAX]; // [Start][End]
bool disable[MAX];
int reverse_dist[MAX][MAX]; // [Start][End]

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
                reverse_dist[j][i] = min(reverse_dist[j][i], reverse_dist[j][k] + reverse_dist[k][i]);
            }
    
    for(int i = 1; i <= n; i++)
    {
        int tmp = 0;
        for(int j = 1; j <= n; j++)
            if(dist[i][j] && dist[i][j] != INF) tmp++;
        
        if(tmp > remain) disable[i] = true;
    }
    for(int i = 1; i <= n; i++)
    {
        int tmp = 0;
        for(int j = 1; j <= n; j++)
            if(reverse_dist[i][j] && reverse_dist[i][j] != INF) tmp++;
        
        if(tmp > remain) disable[i] = true;
    }

    for(int i = 1; i <= n; i++)
    {
        if(disable[i]) cnt++;
    }
    cout << cnt << endl;

    return 0;
}