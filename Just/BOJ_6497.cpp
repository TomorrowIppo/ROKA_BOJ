#include <bits/stdc++.h>
#define MAX 200001

using namespace std;

typedef long long ll;

int m, n;
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
    
    while(true)
    {
        cin >> m >> n;
        if(m == 0 && n == 0) break;
        
        for(int i = 0; i < m; i++) parent[i] = i;
        
        ll cost = 0LL;
        for(int i = 0; i < n; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            edges.push_back({z, x, y});
            cost += z;
        }
        sort(edges.begin(), edges.end());
        
        int cnt = 0; ll ans = 0LL;
        for(int i = 0; i < n; i++)
        {
            int x, y, z;
            tie(z, x, y) = edges[i];
            
            if(is_Union(x, y)) continue;
            
            cnt++; ans += z;
            if(cnt == m - 1) break;
        }
        cout << cost - ans << '\n';
        edges.clear();
    }
    
    return 0;
}