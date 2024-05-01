#include <bits/stdc++.h>
#define MAX 1001

using namespace std;

int n, m;
vector<tuple<int, int, int>> edges;
int parent[MAX];

int find_root(int x)
{
    if(x == parent[x]) return x;
    return parent[x] = find_root(parent[x]);
}

bool is_Union(int x, int y)
{
    x = find_root(x); y = find_root(y);
    
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
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++) parent[i] = i;
    
    for(int i = 0; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }
    
    int k_max = 0;
    int cnt = 0;
    sort(edges.begin(), edges.end());
    for(auto nxt : edges)
    {
        int u, v, w;
        tie(w, u, v) = nxt;
        if(is_Union(u, v)) continue;
        if(w == 0) k_max++;
        cnt++;
        //cout << u << v << endl;
        
        if(cnt == n) break;
    }
    //cout << "(k_max)^2 : " << k_max * k_max << '\n';
    
    int k_min = 0;
    cnt = 0;
    for(int i = 1; i <= n; i++) parent[i] = i;
    sort(edges.begin(), edges.end(), greater<>());
    for(auto nxt : edges)
    {
        int u, v, w;
        tie(w, u, v) = nxt;
        if(is_Union(u, v)) continue;
        if(w == 0) k_min++;
        cnt++;
        //cout << u << v << endl;
        
        if(cnt == n) break;
    }
    //cout << "(k_min)^2 : " << k_min * k_min << '\n';
    
    cout << pow(k_max, 2) - pow(k_min, 2);

    return 0;
}