#include <bits/stdc++.h>
#define MAX 51
#define X first
#define Y second

using namespace std;

/*

Flood-Fill 응용 쉬운 버전 느낌. 평소에는 Flood-Fill을 BFS로 구현하는데 이번엔 DFS로 구현해봄.

*/

int w, h;
int board[MAX][MAX];
bool vis[MAX][MAX];
int dx[8] = {-1, 1, 0, 0, -1, 1, -1 ,1};  // 상 하 좌 우 좌상 좌하 우상 우하
int dy[8] = {0, 0, -1, 1, -1, -1, 1, 1};
int cnt;

void findIsland(pair<int, int> node);
void resetArr();

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true)
    {
        cnt = 0;
        cin >> w >> h;
        if(w == 0 && h == 0) break; // 로직 종료 지점

        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++) 
                cin >> board[i][j];
            
        for(int i = 0; i < h; i++)
        {
            for(int j = 0; j < w; j++)
            {
                if(board[i][j] == 0 || vis[i][j]) continue;
                findIsland({i, j});
                cnt++;
            }
        }
        resetArr();
        cout << cnt << '\n';
    }

    return 0;
}

void findIsland(pair<int, int> node)
{
    vis[node.X][node.Y] = true;

    for(int dir = 0; dir < 8; dir++)
    {
        int nx = node.X + dx[dir];
        int ny = node.Y + dy[dir];

        if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
        if(vis[nx][ny] || board[nx][ny] == 0) continue;

        findIsland({nx, ny});
    }
}

void resetArr()
{
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
        {
            board[i][j] = 0;
            vis[i][j] = false;
        }
}