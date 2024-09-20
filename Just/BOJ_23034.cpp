#include <bits/stdc++.h>
#define MAX 1001
#define V first
#define D second
#define endl "\n"

/* 

Kruskal 알고리즘을 통해 구한 MST에서 임의의 2개 노드를 미리 방문표시 한 뒤,
그 2개의 노드를 시작으로 BFS를 하면 됨.
-> 생각해보 이 방식으로 하면 시간초과됨. 그냥 MST 구한 뒤, 미리 N개의 노드에 대해서 i to j 연락할 때 사용하는 최대 간선을 저장한 뒤,
   쿼리별로 MST cost에서 빼주면 됨

*/

using namespace std;

typedef long long ll;

int N, M, K;
vector<tuple<int, int, int>> edges;
vector<pair<int, int>> graph[MAX];
int parent[MAX];
int dist[MAX][MAX];

int find_root(int x)
{
    if(x == parent[x]) return x;
    return parent[x] = find_root(parent[x]);
}

void merge(int x, int y)
{
    x = find_root(x);
    y = find_root(y);

    if(x > y) parent[x] = y;
    else parent[y] = x; 
}

bool is_same_root(int x, int y)
{
    x = find_root(x);
    y = find_root(y);

    return x == y;
}

void bfs(int x)
{
    bool vis[MAX] = {};
    vis[x] = true;
    queue<int> q;
    q.push(x);

    while(!q.empty())
    {
        auto cur = q.front(); q.pop();

        for(auto nxt : graph[cur])
        {
            if(vis[nxt.V]) continue;
            dist[x][nxt.V] = max(max(dist[x][nxt.V], dist[x][cur]), nxt.D);
            vis[nxt.V] = true;
            q.push({nxt.V});
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 1; i <= N; i++) parent[i] = i;

    for(int i = 1; i <= M; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;

        edges.push_back({d, u, v});
    }
    sort(edges.begin(), edges.end());

    // Kruskal
    ll sum = 0LL;
    int cnt = 0;
    for(auto nxt : edges)
    {
        int d, u, v;
        tie(d, u, v) = nxt;

        if(is_same_root(u, v)) continue;

        merge(u, v);
        graph[u].push_back({v, d});
        graph[v].push_back({u, d});
        sum += d;

        if(cnt++ == N - 1) break;
    }
    // cout << sum;

    for(int i = 1; i <= N; i++) bfs(i);
    cin >> K;
    for(int i = 0; i < K; i++)
    {
        int a1, a2;
        cin >> a1 >> a2;
        cout << sum - dist[a1][a2] << endl;
    }

    return 0;
}