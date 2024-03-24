#include <bits/stdc++.h>
#define MAX 101
#define V first
#define K second

using namespace std;

void solve();

int n, m;
int indegree[MAX];
int outdegree[MAX];
int item_cnt[MAX];
vector<pair<int, int>> graph[MAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int x, y, k;
        cin >> x >> y >> k;

        graph[x].push_back({y, k});
        indegree[y]++;
        outdegree[x]++; // outdegree cnt == 0인 vertex가 기본부품
    }

    solve();

    return 0;
}

void solve()
{
    queue<pair<int, int>> q;
    for(int i = 1; i <= n; i++)
        if(indegree[i] == 0) q.push({i, 1});

    while(!q.empty())
    {
        auto cur = q.front(); q.pop();

        for(auto nxt : graph[cur.V])
        {
            item_cnt[nxt.V] += cur.K * nxt.K;
            indegree[nxt.V]--;
            if(indegree[nxt.V] == 0) q.push({nxt.V, item_cnt[nxt.V]});
        }
    }
    
    for(int i = 1; i <= n; i++)
        if(outdegree[i] == 0) cout << i << ' ' << item_cnt[i] << '\n';
}