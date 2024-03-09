#include <bits/stdc++.h>
#define X first
#define Y second
#define MAX 1001

using namespace std;

void bfs(int x, int y);

int n, m, p;
char board[MAX][MAX];
int p_range[10];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    cin >> n >> m >> p;
    for(int i = 1; i <= p; i++)
        cin >> p_range[i];

    for(int i = 1; i <= n; i++)
    {
        string tmp;
        cin >> tmp;
        for(int j = 1; j <= m; j++)
            board[i][j] = tmp[j];
    }

    // solve

    return 0;
}

void bfs(int x, int y)
{
    
}