#include <bits/stdc++.h>
#define MAX 1001

using namespace std;

typedef struct 
{
    int node;
    int r;
}Info;

void solve(int x);
void topologicalSort();
void dfs(int v);

int n, m;
int indegree[MAX];
int dp[MAX];
vector<Info> graph[MAX];
vector<Info> reverse_graph[MAX];
vector<int> ans;
bool vis[MAX];
int end_node = 1;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int p, q, r;
        cin >> p >> q >> r;
        graph[p].push_back({q, r});
        reverse_graph[q].push_back({p, r});

        if(q == 1) continue;

        indegree[q]++;
    }
    solve(1);

    return 0;
}

void solve(int x)
{
    topologicalSort();
    dfs(end_node);

    ans.push_back(1);
    reverse(ans.begin(), ans.end());
    for(auto item : ans) cout << item << ' ';
}

void topologicalSort()
{
    queue<int> q;
    for(int i = 1; i <= n; i++)
        if(indegree[i] == 0) q.push(i);
    
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();

        for(auto nxt : graph[cur])
        {
            int node = nxt.node;

            dp[node] = max(dp[node], dp[cur] + nxt.r);

            if(node == 1) continue;

            indegree[node]--;
            if(indegree[node] == 0) q.push(node);
        }
    }

    for(int i = 2; i <= n; i++)
        if(dp[end_node] < dp[i]) end_node = i;
    
    cout << dp[1] << '\n';
}

void dfs(int v)
{
    vis[v] = true;
    ans.push_back(v);
    for(auto nxt : reverse_graph[v])
    {
        if(vis[nxt.node]) continue;

        if(dp[v] - nxt.r == dp[nxt.node])
            dfs(nxt.node);
    }
}