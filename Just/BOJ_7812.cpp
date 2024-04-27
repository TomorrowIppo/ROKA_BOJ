#include <bits/stdc++.h>
#define MAX 10001

using namespace std;

typedef struct
{
    int v;
    int w;
}vertex;

typedef long long ll;

int n;
vector<vertex> adj[MAX];
bool vis[MAX];
int parent[MAX];
int subtree[MAX];   // i번을 root로 하는 서브트리의 노드 개수
ll dp[MAX];    // i번으로부터 모든 정점까지의 거리

void makeTree(int root)
{
    vis[root] = true;
    for(auto nxt : adj[root])
    {
        if(vis[nxt.v]) continue;
        parent[nxt.v] = root;
        makeTree(nxt.v);
    }
}

int countSubtree(int cur, int root)
{
   subtree[cur] = 1;
   for(auto nxt : adj[cur])
   {
       if(nxt.v == parent[cur]) continue;
       subtree[cur] += countSubtree(nxt.v, root);
   }
   return subtree[cur];
}

void init(int cur, int root)
{
    for(auto nxt : adj[cur])
    {
        if(nxt.v == parent[cur]) continue;
        dp[root] += nxt.w * subtree[nxt.v];
        init(nxt.v, root);
    }
}

void setDistance(int cur)
{
    for(auto nxt : adj[cur])
    {
        if(nxt.v == parent[cur]) continue;
        dp[nxt.v] = dp[cur] + (n - 2 * subtree[nxt.v]) * nxt.w;
        setDistance(nxt.v);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<ll> ret;
    while(true)
    {
        cin >> n;
        if(n == 0) break;
        
        for(int i = 0; i < n; i++) { adj[i].clear(); vis[i] = false; parent[i] = -1; subtree[i] = 0; dp[i] = 0LL; }
        
        for(int i = 1; i <= n - 1; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        makeTree(0);
        countSubtree(0, 0);
        init(0, 0);
        
        // for(int i = 0; i < n; i++)
        // {
        //     cout << i << " : " << subtree[i] << '\n';
        // }
        // cout << "dist of 0 point : " << dp[0] << '\n';
        
        ll ans = dp[0];
        setDistance(0);
        for(int i = 1; i < n; i++)
            ans = min(ans, dp[i]);
        
        ret.push_back(ans);
    }
    for(auto nxt : ret) cout << nxt << '\n';
    
    return 0;
}