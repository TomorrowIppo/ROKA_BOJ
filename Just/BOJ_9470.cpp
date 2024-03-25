#include <bits/stdc++.h>
#define MAX 1001

using namespace std;

int getStrahler();
void resetParams();

int t, k, m, p;
int indegree[MAX];
vector<int> graph[MAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> k >> m >> p;
        for(int i = 0; i < p; i++)
        {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            indegree[v]++;
        }

        int ans = getStrahler();
        resetParams();

        cout << k << ' ' << ans << '\n';
    }

    return 0;
}

int getStrahler()
{
    int ret = 0;
    queue<int> q;
    for(int i = 1; i <= m; i++)
        if(indegree[i] == 0) q.push(i);
    
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();

        for(auto nxt : graph[cur])
        {
            indegree[nxt]--;
            if(indegree[nxt] == 0) q.push(nxt);
        }
    }

    return ret;
}

void resetParams()
{
    for(int i = 1; i <= m; i++) { graph[i].clear(); indegree[i] = 0; }
}