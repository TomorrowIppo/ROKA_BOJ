#include <bits/stdc++.h>
#define MAX 10001

using namespace std;

void dfs(int cur, int len);

typedef struct
{
    int node;
    int weight;
}dataSet;

vector<dataSet> adj[MAX];
bool vis[MAX];
int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int p, c, w;
        cin >> p >> c >> w;
        adj[p].push_back({c, w});
        adj[c].push_back({p, w});
    }
    dfs(1, 0);

    return 0;
}

void dfs(int cur, int len)
{
    vis[cur] = true;
    for(auto nxt : adj[cur])
    {
        
    }
}