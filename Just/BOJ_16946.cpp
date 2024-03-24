#include <bits/stdc++.h>
#define X first
#define Y second
#define MAX 1001

using namespace std;

// 선 Flood-Fill 이후 벽인 지점에서 상하좌우 탐색 후 더하기.
void getRange(int x, int y);

// 전역변수 설정부터 이어서 하기
int n, m;
int board[MAX][MAX];
bool vis[MAX][MAX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        string inp;
        cin >> inp;

        for(int j = 0; j < m; j++) board[i][j] = inp[j] - '0';
    }

    // Flood-Fill
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(vis[i][j] || board[i][j] != 0) continue;
            getRange(i, j);
        }
    }

    // print
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++) cout << board[i][j] % 10;
        cout << '\n';
    }

    return 0;
}

void getRange(int x, int y)
{
    int cnt = 1;

    queue<pair<int, int>> q;
    queue<pair<int, int>> wall;    // Flood-Fill 할 때, 인접 벽들을 저장할 변수
    q.push({x, y});
    vis[x][y] = true;

    while(!q.empty())
    {
        auto cur = q.front(); q.pop();

        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(!vis[nx][ny] && board[nx][ny] == 0)  // 방문한 적이 없는 길
            {
                q.push({nx, ny});
                vis[nx][ny] = true;
                cnt++;
            }
            else if(!vis[nx][ny] && board[nx][ny] != 0) // 방문한 적이 없는 벽
            {
                wall.push({nx, ny});
                vis[nx][ny] = true;
            }
        }
    }

    while(!wall.empty())
    {
        auto cur = wall.front(); wall.pop();
        board[cur.X][cur.Y] += cnt;
        vis[cur.X][cur.Y] = false;
    }
}
