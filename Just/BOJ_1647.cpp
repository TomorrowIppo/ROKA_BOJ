#include <bits/stdc++.h>
#define MAX 100001

/*

그냥 MST 구한 다음, MST를 구성하는 간선 중 max를 잘라내서 두 마을로 만들면 됨.
바로 떠오르지 않아서 조금 헤맸던 문제.

*/

using namespace std;

typedef long long ll;

int N, M;
vector<tuple<int, int, int>> edges;
int parent[MAX];

int find_root(int x)
{
    if (x == parent[x]) return x;
    return parent[x] = find_root(parent[x]);
}

bool is_Union(int x, int y)
{
    x = find_root(x);
    y = find_root(y);
    
    if(x == y) return true;
    else
    {
        if(x > y) parent[x] = y;
        else parent[y] = x;
        return false;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    for(int i = 1; i <= N; i++) parent[i] = i;
    for(int i = 0; i < M; i++)
    {
        int u, v, cost;
        cin >> u >> v >> cost;
        edges.push_back({cost, u, v});
    }
    sort(edges.begin(), edges.end());
    
    int cnt = 0; ll ans = 0LL; int cost_max = 0;
    for(int i = 0; i < M; i++)
    {
        int cost, u, v;
        tie(cost, u, v) = edges[i];
        
        if(is_Union(u, v)) continue;
        
        cnt++; ans += cost;
        cost_max = max(cost, cost_max);
        if(cnt == N - 1) break;
    }
    cout << ans - cost_max;
}