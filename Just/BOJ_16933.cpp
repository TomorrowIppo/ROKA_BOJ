#include <bits/stdc++.h>
#define MAX 1001
#define INF 987654321

/*

낮과 밤의 존재가 너무 까다롭다.
어떻게 처리해야할까.

5 5 5
00100
11111
11111
11111
00000

=> ans = 11

이 테스트 케이스만 고치면 정답일 것 같다. 내일 고쳐보자.

*/

using namespace std;

typedef struct
{
    int x;  
    int y;  
    int breakCnt;   // 벽 부순 횟수
    bool isDayTime; // 낮 여부
}dataSet;

int N, M, K;
char board[MAX][MAX];
int dist[MAX][MAX][11];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void bfs(int x, int y, int k, bool daytime);

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
            for(int k = 0; k <= K; k++)
                dist[i][j][k] = -1;

    // 로직
    bfs(0, 0, 0, true);

    return 0;
}

void bfs(int x, int y, int k, bool daytime)
{
    int ret = INF;
    queue<dataSet> q;
    q.push({x, y, k, daytime});
    dist[x][y][k] = 1;

    // 탐색
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        if(cur.x == N - 1 && cur.y == M - 1) break;

        if(!cur.isDayTime)   // 현재 밤일 때
        {
            int cantMoveCnt = 0;
            for(int dir = 0; dir < 4; dir++)
            {
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];

                if(nx < 0 || ny < 0 || nx >= N || ny >= M) { cantMoveCnt++; continue; }    // 범위 넘어가면 스킵
                if(dist[nx][ny][cur.breakCnt] >= 0 || board[nx][ny] == '1') { cantMoveCnt++; continue; }
                
                q.push({nx, ny, cur.breakCnt, !cur.isDayTime});
                dist[nx][ny][cur.breakCnt] = dist[cur.x][cur.y][cur.breakCnt] + 1;
            }

            if(cantMoveCnt == 4) 
            {
                q.push({cur.x, cur.y, cur.breakCnt, !cur.isDayTime});
                dist[cur.x][cur.y][cur.breakCnt] += 1;
            }
        }
        else    // 현재 낮일 때
        {
            for(int dir = 0; dir < 4; dir++)
            {
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];

                if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;    // 범위 넘어가면 스킵

                if(board[nx][ny] == '1')  // 이동하려는 곳이 벽일 때
                {
                    if(cur.breakCnt >= K) continue;   // 벽을 부술 수 있는 횟수를 초과했다면 스킵
                    if(dist[nx][ny][cur.breakCnt + 1] >= 0) continue;   // 이미 지났다면 스킵
                    
                    q.push({nx, ny, cur.breakCnt + 1, !cur.isDayTime});
                    dist[nx][ny][cur.breakCnt + 1] = dist[cur.x][cur.y][cur.breakCnt] + 1;
                }
                else    // 이동하려는 곳이 길일 때
                {
                    if(dist[nx][ny][cur.breakCnt] >= 0) continue;
                    q.push({nx, ny, cur.breakCnt, !cur.isDayTime});
                    dist[nx][ny][cur.breakCnt] = dist[cur.x][cur.y][cur.breakCnt] + 1;
                }
            }
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