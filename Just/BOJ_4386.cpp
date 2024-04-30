#include <bits/stdc++.h>
#define MAX 101

using namespace std;

typedef struct
{
    float x;
    float y;
}Coord;

int n;
vector<tuple<float, int, int>> edges;
vector<Coord> Coords;
int parent[MAX];

float getDist(Coord c1, Coord c2)
{
    return sqrtf(powf(c1.x - c2.x, 2) + powf(c1.y - c2.y, 2));
}

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
    
    // input
    cin >> n;
    for(int i = 1; i <= n; i++) parent[i] = i;
    
    for(int i = 1; i <= n; i++)
    {
        float x, y;
        cin >> x >> y;
        Coords.push_back({x, y});
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            float dist = getDist(Coords[i - 1], Coords[j - 1]);
            edges.push_back({dist, i, j});
        }
    }
    sort(edges.begin(), edges.end());
    
    // solve
    float ans = 0.f;
    int cnt = 0;
    for(auto nxt : edges)
    {
        float dist; int u, v;
        tie(dist, u, v) = nxt;
        
        if(is_Union(u, v)) continue;
        
        cnt++; ans += dist;
        if(cnt == n - 1) break;
    }
    cout << ans;
    
    return 0;
}