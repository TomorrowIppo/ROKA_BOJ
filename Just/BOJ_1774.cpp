#include <bits/stdc++.h>
#define MAX 1001

/*

역대급으로 조건이 까다로웠던 문제.
getDist() 함수처럼 구현해서 소수점 손실을 방지하는 것이 관건이었다.
이거에 2시간을 박은게 현타온다

*/

using namespace std;

typedef long long ll;
typedef long double ld;

typedef struct
{
    ll x;
    ll y;
}Coord;

int n, m;
ld ans;
vector<tuple<ld, int, int>> edges;
vector<Coord> Coords;
int parent[MAX];
bool anti_duplication[MAX][MAX];

ld getDist(Coord c1, Coord c2)
{
    ll dx = abs(c1.x - c2.x);
    ll dy = abs(c1.y - c2.y);
    return sqrt(pow(dx, 2) + pow(dy, 2));
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
    cin >> n >> m;
    for(int i = 1; i <= n; i++) parent[i] = i;
    
    for(int i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        Coords.push_back({x, y});
    }

    int cnt = 0;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        if(anti_duplication[u][v] || anti_duplication[v][u]) cnt++; // 중복 입력 방지 ex) 1 4과 4 1

        anti_duplication[u][v] = true;
        anti_duplication[v][u] = true;

        //edges.push_back({0.0, u, v});
        is_Union(u, v);
    }

    for(int i = 1; i < n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            ld dist = getDist(Coords[i - 1], Coords[j - 1]);
            edges.push_back({dist, i, j});
        }
    }
    sort(edges.begin(), edges.end());
    
    // solve
    for(auto nxt : edges)
    {
        ld dist; int u, v;
        tie(dist, u, v) = nxt;
        
        if(is_Union(u, v)) continue;
        
        cnt++; ans += dist;
        if(cnt == n - 1) break;
    }
    cout.precision(2);
    cout << fixed << ans;
    
    return 0;
}