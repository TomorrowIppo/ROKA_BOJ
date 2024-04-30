#include <bits/stdc++.h>
#define MAX 1001

using namespace std;

typedef long long ll;

int n;
vector<tuple<int, int, int>> edges;
int parent[MAX];

int find_root(int x)
{
    if(x == parent[x]) return x;
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
    
    cin >> n;
    for(int i = 1; i <= n; i++) parent[i] = i;
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            int cost;
            cin >> cost;
            
            if(i >= j) continue;
            
            edges.push_back({cost, i , j});
        }
    }
    sort(edges.begin(), edges.end());
    
    int cnt = 0; ll ans = 0LL;
    for(auto edge : edges)
    {
        int u, v, w;
        tie(w, u, v) = edge;
        
        if(is_Union(u, v)) continue;
        
        cnt++; ans += w;
        if(cnt == n - 1) break;
    }
    cout << ans;
    
    return 0;
}