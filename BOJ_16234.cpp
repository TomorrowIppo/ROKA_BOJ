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
void openGate();

int N, L, R;
bool flag = false;
int board[MAX][MAX];
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
    while(flag)
    {
        openGate();

        // reset
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                vis[i][j] = false;
        
        cnt++;
    }
    cout << cnt;
}

void openGate()
{
    queue<Coord> q;
    queue<Coord> update;
    q.push({0, 0});
    vis[0][0] = true;
    value.push_back(board[0][0]);

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
                value.push_back(board[nx][ny]);
                q.push({nx, ny});
                vis[nx][ny] = true;
            }
        }
    }

    int aver = 0;
    for(int i = 0; i < value.size(); i++)
        aver += value[i];
    
    aver = (aver / value.size());
}