#include <bits/stdc++.h>
#define MAX 20001
#define INF 987654321
#define endl "\n"

using namespace std;

int k;
int n, m;
vector<int> graph[MAX];
int vis[MAX];

void solve();
bool bfs(int start);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}

void solve()
{
    cin >> k;
    while(k--)
    {
        // input
        cin >> n >> m;
        
        // vis 배열, graph reset
        for(int i = 1; i <= n; i++) { vis[i] = -1; graph[i].clear(); }

        for(int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }        
        
        // Flood-Fill
        bool ans = true;
        for(int i = 1; i <= n; i++)
            if(vis[i] == -1)
            {
                ans = ans & bfs(i);
            }
        
        if(ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }    
}

bool bfs(int start)
{
    // 방문 안했으면 -1, 했으면 0 or 1
    bool is_able = true;
    queue<int> q;
    q.push(start);
    vis[start] = 0;

    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        
        for(auto nxt : graph[cur])
        {
            if(vis[nxt] != -1)
            {
                if(vis[cur] == vis[nxt]) is_able = false; 

                continue;
            }
            
            q.push(nxt);
            vis[nxt] = (vis[cur] == 0) ? 1 : 0;
        }
    }

    return is_able;
}