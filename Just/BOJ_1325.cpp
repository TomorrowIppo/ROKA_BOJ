#include <bits/stdc++.h>
#define MAX 10001

using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2) {}
void input();
void dfs(int v, int dist);
void resetArr();

int n, m;
int cnt = 0;
vector<int> graph[MAX];
vector<pair<int, int>> ans;    // vertex별 해킹가능한 컴퓨터 수 (컴퓨터 번호, 해킹가능한 컴퓨터 수)
bool vis[MAX];

int main()
{
    ios::sync_with_stido(0);
    cin.tie(0);

    input();
    for(int i = 1; i<= n; i++)
    {
        resetArr();
        vis[i] = true;
        dfs(i, 1);
        ans.push_back({i, cnt});
        cnt = 0;
    }
    // ans의 원소들을 비교해서 답 출력하는 부분 구현하기

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

void dfs(int v, int dist)
{
    for(int nxt : graph[v])
    {
        if(vis[nxt]) continue;
        vis[nxt] = true;
        dfs(nxt, dist + 1);
        vis[nxt] = false;
    } 
    cnt = max(cnt, dist);
}

void resetArr()
{
    for(int i = 1; i <= n; i++) vis[i] = false;
}