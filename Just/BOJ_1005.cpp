#include <bits/stdc++.h>
#define MAX 1001

using namespace std;

void solve();
void resetParams();

int n, k, w;
int indegree[MAX];
int dp[MAX];
vector<int> graph[MAX];
int time_taken[MAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        resetParams();

        cin >> n >> k;
        // 건물당 건설 소요 시간
        for(int i = 1; i <= n; i++)
            cin >> time_taken[i];
        // 건설 순서 make graph
        for(int i = 1; i <= k; i++)
        {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            indegree[v]++;
        }
        // 승리하기 위해 건설해야 할 건물 번호
        cin >> w;
        
        solve();
    }

    return 0;
}

void solve()
{
    // indegree cnt = 0인 것을 큐에 push
    queue<int> q;
    for(int i = 1; i <= n; i++)
        if(indegree[i] == 0) q.push(i);
    
    // dp와 time_taken 매치시켜서 basis 설정
    for(int i = 1; i <= n; i++)
        dp[i] = time_taken[i];

    // 탐색
    while(!q.empty())  
    {
        auto cur = q.front(); q.pop();
        if(cur == w) { cout << dp[cur] << '\n'; break; }

        for(auto nxt : graph[cur])
        {
            dp[nxt] = max(dp[nxt], dp[cur] + time_taken[nxt]);  // vertex에 올 때마다, 최댓값으로 갱신

            indegree[nxt]--;
            if(indegree[nxt] == 0) q.push(nxt);
        }
    }
}

void resetParams()
{
    for(int i = 1; i <= n; i++) { time_taken[i] = 0; indegree[i] = 0; dp[i] = 0; graph[i].clear(); }
}