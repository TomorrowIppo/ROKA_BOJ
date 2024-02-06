#include <bits/stdc++.h>
#define MAX 51
#define X first
#define Y second

/*

브루탈하게 모든 육지에서 BFS 실행

*/

using namespace std;

int h, w;
int max_len = 0;
char board[MAX][MAX];
int dist[MAX][MAX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void bfs(int x, int y);
void resetArr() 
{
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            dist[i][j] = -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Input
    cin >> h >> w;
    for(int i = 0; i < h; i++)
    {
        string tmp;
        cin >> tmp;
        for(int j = 0; j < w; j++)
        {
            board[i][j] = tmp[j];
        }
    }

    // Solve
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            if(board[i][j] == 'W') continue;
            resetArr();
            bfs(i, j);
        }
    }
    cout << max_len;

    return 0;
}

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    dist[x][y] = 0;

    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;    // 범위 벗어나면 스킵
            if(dist[nx][ny] >= 0 || board[nx][ny] == 'W') continue;   // 방문했거나 물이면 스킵

            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            q.push({nx, ny});

            max_len = max(max_len, dist[nx][ny]);
        }
    }
}