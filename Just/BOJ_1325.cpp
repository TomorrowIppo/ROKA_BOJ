#include <bits/stdc++.h>
#define MAX 10001
#define X first
#define Y second

using namespace std;

void input();
void dfs(int v);
void resetArr();

int n, m;
int cnt = 0;
vector<int> graph[MAX];
vector<pair<int, int>> ans;    // vertex별 해킹가능한 컴퓨터 수 (컴퓨터 번호, 해킹가능한 컴퓨터 수)
bool vis[MAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    for(int i = 1; i<= n; i++)
    {
        resetArr();
        vis[i] = true;
        dfs(i);
        ans.push_back({i, cnt});
        cnt = 0;
    }

    int maxHack = -1;
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i].Y > maxHack) {
            maxHack = ans[i].Y;
        }
    }
 
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i].Y == maxHack) {
            cout << ans[i].X << " ";
        }
    }
    return 0;
}

void input()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> v >> u;
        graph[u].push_back(v);
    }
}

void dfs(int v)
{
    vis[v] = true;
    for(int nxt : graph[v])
    {
        if(vis[nxt]) continue;
        vis[nxt] = true;
        dfs(nxt);
        cnt++;
    } 
}

void resetArr()
{
    for(int i = 1; i <= n; i++) vis[i] = false;
}