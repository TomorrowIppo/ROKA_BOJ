#include <bits/stdc++.h>
#define MAX 21
#define X first
#define Y second
#define MODEFIY(X) X - 65

/*

처음에 문제를 풀 때, dfs 진행할 때마다 알파벳 방문 여부를 저장하는 배열을 깊은 복사를 해가며
이동한 경로에 따른 알파벳 방문 여부를 판단했었다. 하지만, 이로 인해 시간초과가 발생했기에
그리고 dfs 함수를 호출하기 전에, 방문한 지점의 알파벳을 방문한 것으로 체크하고 
dfs 함수를 호출한 뒤에는, 방문한 지점의 알파벳을 방문하지 않은 것으로 체크함으로써 시간초과를 해결했다.

*/

using namespace std;

int r, c;
int ans = 0;
char board[MAX][MAX];
bool vis[26];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void dfs(pair<int, int> node, int dist);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;
    for(int i = 0; i < r; i++)
    {
        string inp;
        cin >> inp;
        
        for(int j = 0; j < c; j++)
        {
            board[i][j] = inp[j];
        }
    }
    vis[MODEFIY(board[0][0])] = true;
    dfs({0, 0}, 1);
    cout << ans;

    return 0;
}

void dfs(pair<int, int> node, int dist)
{
    bool movable = false;

    for(int dir = 0; dir < 4; dir++)
    {
        int nx = node.X + dx[dir];
        int ny = node.Y + dy[dir];

        if(nx < 0 || ny < 0 || nx >=r || ny >= c) continue;
        if(vis[MODEFIY(board[nx][ny])]) continue;

        vis[MODEFIY(board[nx][ny])] = true;
        movable = true;
        dfs({nx, ny}, dist + 1);
        vis[MODEFIY(board[nx][ny])] = false;
    }

    if(!movable) { ans = max(ans, dist); };
}