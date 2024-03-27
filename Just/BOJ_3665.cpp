#include <bits/stdc++.h>
#define MAX 501

using namespace std;

void updateRate();
void resetParams();

/*

5 -> 4, 3, 2, 1
4 -> 3, 2, 1
3 -> 2, 1
2 -> 1
로 다 연결 한 다음, 갱신하기

+) interator 안쓰고 풀려고 하다가 틀리지 말고 그냥 곱게 interator 쓰자 병진아 원트클 못했다 이거때문에
*/

int t, n, m;
int prev_rank[MAX];
vector<int> graph[MAX];
int indegree[MAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> prev_rank[i];

        // makeGraph
        for(int i = 1; i < n; i++)
            for(int j = i + 1; j <= n; j++) 
            {
                graph[prev_rank[i]].push_back(prev_rank[j]);
                indegree[prev_rank[j]]++;
            }
        
        // updateGraph
        cin >> m;
        for(int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            vector<int>::iterator it = find(graph[v].begin(), graph[v].end(), u);
            if(it != graph[v].end()) {
                graph[v].erase(it);
                indegree[u]--;
                graph[u].push_back(v);
                indegree[v]++;
            } else {
                it = find(graph[u].begin(), graph[u].end(), v);
                graph[u].erase(it);
                indegree[v]--;
                graph[v].push_back(u);
                indegree[u]++;
            }
        }

        updateRate();
        resetParams();
    }

    return 0;
}

void updateRate()
{
    queue<int> q;
    vector<int> ans;
    for(int i = 1; i <= n; i++)
        if(indegree[i] == 0) q.push(i);
    
    // for(int i = 1; i <= n; i++)
    //     cout << i << " : " << indegree[i] << '\n';
    
    while(!q.empty())
    {
        if(q.size() > 1) { cout << "?\n"; return; } // 확실한 순위를 찾을 수 없는 경우

        auto cur = q.front(); q.pop();
        ans.push_back(cur);

        for(auto nxt : graph[cur])
        {
            indegree[nxt]--;
            if(indegree[nxt] == 0) q.push(nxt);
        }
    }

    if(ans.size() != n) cout << "IMPOSSIBLE\n";
    else
    {
        for(auto v : ans) cout << v << ' ';
        cout << '\n'; 
    }
}

void resetParams()
{
    for(int i = 1; i <= n; i++) 
    { prev_rank[i] = 0; indegree[i] = 0; graph[i].clear(); vector<int>().swap(graph[i]); }
}