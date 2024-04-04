#include <bits/stdc++.h>
#define MAX 51

using namespace std;

/* Gate 오픈하고 Flood-Fill 하면 될 듯 */

typedef struct
{
    int x;
    int y;
}Coord;

void solve();
void FloodFill(int x, int y, int num);

int N, L, R;
int board[MAX][MAX];
int UnionArea[MAX][MAX];
bool vis[MAX][MAX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
vector<int> value;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    cin >> N >> L >> R;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> board[i][j];

    solve();

    return 0;
}

void solve()
{
    int cnt = 0;
    while(true)
    {
        value.push_back(0);
        int num = 1;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
            {
                if(vis[i][j]) continue;
                FloodFill(i, j, num);
                num++;
            }

        if(num >= N*N + 1) { cout << cnt; return ; }

        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                board[i][j] = value[UnionArea[i][j]];

        // reset
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
            {
                vis[i][j] = false;
                UnionArea[i][j] = 0;
            }

        cnt++;
        value.clear();
    }
}

void FloodFill(int x, int y, int num)
{
    queue<Coord> q;
    q.push({x, y});
    vis[x][y] = true;
    UnionArea[x][y] = num;

    int sum = board[x][y];
    int cnt = 1;

    while(!q.empty())
    {
        auto cur = q.front(); q.pop();

        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(vis[nx][ny]) continue;

            int dist = abs(board[cur.x][cur.y] - board[nx][ny]);
            if(L <= dist && dist <= R)
            {
                sum += board[nx][ny];
                cnt++;
                q.push({nx, ny});
                vis[nx][ny] = true;
                UnionArea[nx][ny] = num;
            }
        }
    }

    int res = sum / cnt;
    value.push_back(res);
}