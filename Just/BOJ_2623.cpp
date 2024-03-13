#include <bits/stdc++.h>
#define MAX 1001

using namespace std;

void makeGraph();
void topologicalSort();

int n, m;
vector<int> graph[MAX];
int indegree[MAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++)
        makeGraph();

    topologicalSort();

    return 0;
}

void makeGraph()
{
    int num, u;
    cin >> num >> u;
    for(int i = 0; i < num - 1; i++)
    {
        int v;
        cin >> v;
        graph[u].push_back(v);
        indegree[v] += 1;
        u = v;
    }
}

void topologicalSort()
{
    queue<int> q;
    vector<int> ans;
    
    // indegree cnt = 0인 것들을 q에 push
    for(int i = 1; i <= n; i++)
        if(indegree[i] == 0) q.push(i);

    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        ans.push_back(cur);

        for(auto nxt : graph[cur])
        {
            indegree[nxt] -= 1;
            if(indegree[nxt] == 0) q.push(nxt);
        }
    }

    int sum = 0;
    for(int i = 1; i <= n; i++) sum += indegree[i];

    if(sum == 0)
    {
        for(int i = 0; i < ans.size(); i++)
            cout << ans[i] << ' ';
    }
    else
        cout << 0;
}