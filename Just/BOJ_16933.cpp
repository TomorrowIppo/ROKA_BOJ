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

=> BOJ_14442 방식으로 진행하다가, 밤에 벽을 만난 경우를 처리할 때, 거리 + 1이 중복으로 적용될 수 있음을 발견

무조건 int dist[]을 통해 방문여부 + 이동거리를 동시에 할 필요 없이
그냥 queue에 이동거리를 같이 넣어주는 방식도 좋은 듯 하다. 상황에 따라 유동적으로 할 수 있도록 준비하자.

*/

using namespace std;

typedef struct
{
    int x;  
    int y;
    int dist;
    int breakCnt;   // 벽 부순 횟수
    bool isDayTime; // 낮 여부
}dataSet;

int N, M, K;
char board[MAX][MAX];
bool vis[MAX][MAX][11];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void bfs(int x, int y, int dist, int k, bool daytime);

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

    // 로직
    bfs(0, 0, 1, 0, true);

    return 0;
}

void bfs(int x, int y, int dist, int k, bool daytime)
{
    queue<dataSet> q;
    q.push({x, y, dist, k, daytime});
    vis[x][y][k] = true;

    // 탐색
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        if(cur.x == N - 1 && cur.y == M - 1) 
        {
            cout << cur.dist;
            return;
        }

        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

            if(board[nx][ny] == '1')    // 벽일 경우
            {
                // 어짜피 현재 밤이고, 부술 수 있는 기회를 다 쓴 상태에서 벽을 만났을 때 하루 기다리고 dist + 1 하고 다시 탐색을 해봤자 의미가 없다. 최단거리가 아니게 되기 때문.
                if(cur.breakCnt >= K) continue;
                if(vis[nx][ny][cur.breakCnt + 1]) continue;
                
                if(cur.isDayTime)   // 낮인 경우
                {
                    q.push({nx, ny, cur.dist + 1, cur.breakCnt + 1, !cur.isDayTime});
                    vis[nx][ny][cur.breakCnt + 1] = true;
                }
                else    // 밤인 경우
                {
                    q.push({cur.x, cur.y, cur.dist + 1, cur.breakCnt, !cur.isDayTime});
                }
            }
            else    // 길인 경우
            {
                if(vis[nx][ny][cur.breakCnt]) continue;
                q.push({nx, ny, cur.dist + 1, cur.breakCnt, !cur.isDayTime});
                vis[nx][ny][cur.breakCnt] = true;
            }
        }   
    }
    cout << -1;
}