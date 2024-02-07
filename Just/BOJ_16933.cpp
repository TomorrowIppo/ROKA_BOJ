#include <bits/stdc++.h>
#define MAX 1001
#define INF 987654321

/*

낮과 밤의 존재가 너무 까다롭다.
어떻게 처리해야할까.

*/

using namespace std;

typedef struct
{
    int x;  
    int y;  
    int breakCnt;   // 벽 부순 횟수
}dataSet;

int N, M, K;
char board[MAX][MAX];
int dist[MAX][MAX][11];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void bfs(int x, int y, int k);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 입력
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
            for(int k = 0; k < K; k++)
                dist[i][j][k] = -1;

    // 로직
    bfs(0, 0, 0);

    return 0;
}

void bfs(int x, int y, int k)
{
    int ret = INF;
    queue<dataSet> q;
    q.push({x, y, k});
    dist[x][y][k] = 1;

    // 탐색
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        }
    }

    // 답 출력
    for(int i = 0; i <= K; i++)
    {
        if(dist[N - 1][M - 1][i] == -1) continue;
        ret = min(ret, dist[N - 1][M - 1][i]);
    }
    if(ret == INF) ret = -1;

    cout << ret;
}