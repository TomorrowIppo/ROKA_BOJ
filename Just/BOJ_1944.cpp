#include <bits/stdc++.h>
#define MAX 251
#define endl "\n"
#define X first
#define Y second

using namespace std;

typedef struct 
{
    int x;
    int y;
}Coord;

typedef struct
{
    int v;
    int w;
}Edge;

int n, m;
int parent[MAX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
vector<tuple<int, int, int>> edges;
vector<Edge> adj[MAX];
vector<Coord> coords; 
char board[51][51];
int vis[MAX][51][51];
int id[51][51];

int find_root(int x)
{
    if(x == parent[x]) return x;
    return parent[x] = find_root(parent[x]);
}

void merge(int x, int y)
{
    x = find_root(x);
    y = find_root(y);

    if(x > y) parent[x] = y;
    else parent[y] = x;
}

void bfs(int x, int y, int k)
{
    queue<Coord> q;
    q.push({x, y});
    vis[k][x][y] = 0;

    while(!q.empty())
    {
        auto cur = q.front(); q.pop();

        if(board[cur.x][cur.y] == 'S' || board[cur.x][cur.y] == 'K')
        {
            if(k != id[cur.x][cur.y]) edges.push_back({vis[k][cur.x][cur.y], k, id[cur.x][cur.y]});
        }
        
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(vis[k][nx][ny] >= 0 || board[nx][ny] == '1') continue;

            q.push({nx, ny});
            vis[k][nx][ny] = vis[k][cur.x][cur.y] + 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; i++) parent[i] = i;

    // reset
    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < 51; j++)
            for(int k = 0; k < 51; k++)
                vis[i][j][k] = -1;

    int vertex_num = 1;
    for(int i = 0; i < n; i++)
    {
        string inp;
        cin >> inp;
        for(int j = 0; j < n; j++)
        {
            board[i][j] = inp[j];

            if(board[i][j] == 'S' || board[i][j] == 'K') 
            {
                coords.push_back({i, j});
                id[i][j] = vertex_num++;
            }
        }
    }

    // bfs로 edge 구하기
    for(int i = 1; i <= vertex_num; i++)
        bfs(coords[i - 1].x, coords[i - 1].y, i);

    // test
    long long ans = 0LL;
    int cnt = 0;
    sort(edges.begin(), edges.end());
    for(auto nxt : edges)
    {
        int u, v, d;
        tie(d, u, v) = nxt;
        // cout << "(" << u << ", " << v << ") : " << d << endl;

        if(find_root(u) == find_root(v)) continue;

        merge(u, v);
        ans += d;
        cnt++;

        if(cnt == m) break;
    }
    if(cnt != m) cout << -1;
    else cout << ans;

    return 0;
}