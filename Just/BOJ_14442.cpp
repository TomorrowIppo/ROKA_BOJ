#include <bits/stdc++.h>
#define MAX 1001
#define INF 987654321

using namespace std;

typedef struct 
{
    int x;  // x좌표
    int y;  // y좌표
    int k;  // 벽 부순 횟수
} dataSet;

int N, M, K;
char board[MAX][MAX];
int dist[MAX][MAX][11];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int bfs(int x, int y, int k);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Input & Setting
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++)
    {
        string tmp;
        cin >> tmp;
        for(int j = 0; j < M; j++)
        {
            board[i][j] = tmp[j];
        }
    }

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            for(int k = 0; k <= K; k++)
                dist[i][j][k] = -1;

    // Solve
    cout << bfs(0, 0, 0);

    return 0;
}

int bfs(int x, int y, int k)
{
    int ret = INF;
    queue<dataSet> q;
    q.push({x, y, k});
    dist[x][y][k] = 1;

    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;    // 범위를 벗어나면 스킵

            if(board[nx][ny] == '1')  // 이동하려는 곳이 벽일 때
            {
                if(cur.k >= K) continue;   // 벽을 부술 수 있는 횟수를 초과했다면 스킵
                if(dist[nx][ny][cur.k + 1] >= 0) continue;   // 이미 지났다면 스킵
                
                q.push({nx, ny, cur.k + 1});
                dist[nx][ny][cur.k + 1] = dist[cur.x][cur.y][cur.k] + 1;
            }
            else    // 이동하려는 곳이 길일 때
            {
                if(dist[nx][ny][cur.k] >= 0) continue;
                q.push({nx, ny, cur.k});
                dist[nx][ny][cur.k] = dist[cur.x][cur.y][cur.k] + 1;
            }
        }
    }   

    for(int i = 0; i <= K; i++)
    {
        if(dist[N - 1][M - 1][i] == -1) continue;
        ret = min(ret, dist[N - 1][M - 1][i]);
    }

    if(ret == INF) ret = -1;

    return ret;
}