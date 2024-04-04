#include <bits/stdc++.h>
#define MAX 17

using namespace std;

typedef struct
{
    int x;
    int y;
    int dir;
}Info;

int board[MAX][MAX];
int dp[MAX][MAX];
int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)    
        for(int j = 1; j <= n; j++)
            cin >> board[i][j];

    queue<Info> q;
    q.push({1, 2, 1});

    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        
        if(cur.dir == 1)
        {
            if(cur.y + 1 <= n && board[cur.x][cur.y + 1] == 0)
            {
                q.push({cur.x, cur.y + 1, 1});
                dp[cur.x][cur.y + 1]++;
            }

            if(cur.x + 1 > n || cur.y + 1 > n) continue;
            if(board[cur.x][cur.y + 1] == 0 && board[cur.x + 1][cur.y] == 0 && board[cur.x + 1][cur.y + 1] == 0)
            {
                q.push({cur.x + 1, cur.y + 1, 3});
                dp[cur.x + 1][cur.y + 1]++;
            }
        }
        else if(cur.dir == 2)
        {
            if(cur.x + 1 <= n && board[cur.x + 1][cur.y] == 0)
            {
                q.push({cur.x + 1, cur.y, 2});
                dp[cur.x + 1][cur.y]++;
            }

            if(cur.x + 1 > n || cur.y + 1 > n) continue;
            if(board[cur.x][cur.y + 1] == 0 && board[cur.x + 1][cur.y] == 0 && board[cur.x + 1][cur.y + 1] == 0)
            {
                q.push({cur.x + 1, cur.y + 1, 3});
                dp[cur.x + 1][cur.y + 1]++;
            }
        }
        else
        {
            if(cur.x + 1 <= n && board[cur.x + 1][cur.y] == 0)
            {
                q.push({cur.x + 1, cur.y, 2});
                dp[cur.x + 1][cur.y]++;
            }
            if(cur.y + 1 <= n && board[cur.x][cur.y + 1] == 0)
            {
                q.push({cur.x, cur.y + 1, 1});
                dp[cur.x][cur.y + 1]++;
            }

            if(cur.x + 1 > n || cur.y + 1 > n) continue;
            if(board[cur.x][cur.y + 1] == 0 && board[cur.x + 1][cur.y] == 0 && board[cur.x + 1][cur.y + 1] == 0)
            {
                q.push({cur.x + 1, cur.y + 1, 3});
                dp[cur.x + 1][cur.y + 1]++;
            }
        }
    }
    // 이동할 수 없는 경우
    cout << dp[n][n];

    return 0;
}