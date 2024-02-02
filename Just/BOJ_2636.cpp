#include <bits/stdc++.h>
#define MAX 101
#define X first
#define Y second

using namespace std;

void input();
void solve();
void bfs(int x, int y);

int n, m;
int _time = 0;
int cheese_cnt = 0;
int board[MAX][MAX];
bool vis[MAX][MAX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
queue<pair<int, int>> q;
queue<pair<int, int>> cheese;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    solve();

    return 0;
}

void input()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];       
}

void solve()
{
    bfs(0, 0);  // 공기의 가장 최외각에서 시작
}

void bfs(int x, int y)
{
    q.push({x, y});
    vis[x][y] = true;

    while(true)
    {
        if(q.empty()) { _time--; break; }

        while(!q.empty())
        {
            auto cur = q.front(); q.pop();
            for(int dir = 0; dir < 4; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if(vis[nx][ny]) continue;

                if(board[nx][ny] == 1)  // 치즈를 만날 시
                {
                    cheese.push({nx, ny});  // 치즈 위치 저장
                    board[nx][ny] = 0;  // 치즈 녹임
                } 
                else 
                {
                    q.push({nx, ny});
                }
                vis[nx][ny] = true;
            }
        }
        _time++;
        if(!cheese.empty()) { cheese_cnt = cheese.size(); } // cheese가 비어있지 않을 때만 갱신

        while(!cheese.empty()) { q.push(cheese.front()); cheese.pop(); }    // 저장해둔 치즈 위치를 q에 갱신
    }
    cout << _time << '\n' << cheese_cnt << '\n';
}
