#include <bits/stdc++.h>
#define MAX 501 
#define X first
#define Y second

using namespace std;

int dfs(int x, int y);

int n;
int board[MAX][MAX], dp[MAX][MAX];
int ans;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];

    // solve
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            ans = max(ans, dfs(i, j));
        
    cout << ans;

    return 0;
}

int dfs(int x, int y)
{
    if(dp[x][y]) return dp[x][y];

    dp[x][y] = 1;
    for(int dir = 0; dir < 4; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(board[nx][ny] > board[x][y])
        {
            dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
        }
    }

    return dp[x][y];
}