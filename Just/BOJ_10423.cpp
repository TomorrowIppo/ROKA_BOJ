#include <bits/stdc++.h>
#define MAX 2001

using namespace std;

typedef long long ll;

int n, m, k;
vector<tuple<int, int, int>> edges;
int parent[MAX];
bool is_planted[MAX];

int find_root(int x)
{
    if(x == parent[x]) return x;
    return parent[x] = find_root(parent[x]);
}

void merge(int x, int y)
{
    x = find_root(x);
    y = find_root(y);
    
    if(x < y) parent[x] = y;
    else parent[y] = x;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) parent[i] = i;
    
    // 발전소 위치 입력
    for(int i = 0; i < k; i++)
    {
        int inp; 
        cin >> inp;
        is_planted[inp] = true;
    }
    
    // 간선 정보
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        
        u = (is_planted[u]) ? u + 1000 : u;
        v = (is_planted[v]) ? v + 1000 : v;
        
        edges.push_back({w, u, v});
    }
    sort(edges.begin(), edges.end());
    
    // Kruskal
    ll ans = 0LL; int cnt = 0;
    for(auto nxt : edges)
    {
        int u, v, w;
        tie(w, u, v) = nxt;
        
        int root_u = find_root(u);
        int root_v = find_root(v);
        if(root_u == root_v) continue;  // 같은 집합 연결 방지
        if(root_u > 1000 && root_v > 1000) continue;    // 발전소가 설치된 집합과 연결 방지
        
        merge(u, v);
        cnt++; ans += w;
        if(cnt == n - k) break;
    }
    cout << ans;
    
    return 0;
}