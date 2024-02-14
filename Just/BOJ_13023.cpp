#include <bits/stdc++.h>
#define MAX 2001

using namespace std;

bool isExist();
void dfs(int node, int depth);

int n, m;
bool ret = false;
vector<int> graph[MAX];
bool vis[MAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cout << (isExist() ? 1 : 0);

    return 0;
}

bool isExist()
{
    for(int i = 0; i < n; i++)
    {
        dfs(i, 0);
        if(ret) return true;
    }
    return false;
}

void dfs(int node, int depth)
{
    if(depth == 4)  // 조건에 만족할 때
    {
        ret = true;
        return;
    }

    vis[node] = true;
    for(auto nxt : graph[node])
    {
        if(vis[nxt]) continue;
        dfs(nxt, depth + 1);
    }
    vis[node] = false;
}
