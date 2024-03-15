#include <bits/stdc++.h>
#define MAX 1001

using namespace std;

void solve();
void reset();

int n, k, w;
int indegree[MAX];
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
        reset();
    }

    return 0;
}

void solve()
{

}

void reset()
{
    for(int i = 1; i <= n; i++) { time_taken[i] = 0; indegree[i] = 0; }
}