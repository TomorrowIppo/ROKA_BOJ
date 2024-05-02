#include <bits/stdc++.h>
#define MAX 100001

using namespace std;

typedef long long ll;
typedef struct 
{
    ll x;
    ll y;
    ll z;
}Coord;

int n;
vector<tuple<ll, int, int>> edges;
vector<Coord> Coords;
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
    for(int i = 1; i <= n; i++)
    {
        parent[i] = i;

        ll x, y, z;
        cin >> x >> y >> z;
        Coords.push_back({x, y, z});
    }

    for(int i = 1; i < n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            Coord c1 = Coords[i - 1];
            Coord c2 = Coords[j - 1];

            ll dx = abs(c1.x - c2.x);
            ll dy = abs(c1.y - c2.y);
            ll dz = abs(c1.z - c2.z);

            ll dist = min(dx, min(dy, dz));
            edges.push_back({dist, i, j});
        }
    }
    sort(edges.begin(), edges.end());

    int cnt = 0;
    ll ans = 0LL;
    for(auto nxt : edges)
    {
        ll dist;
        int u, v;
        tie(dist, u, v) = nxt;

        if(is_Union(u, v)) continue;

        cnt++; ans += dist;
        if(cnt == n - 1) break;
    }
    cout << ans;

    return 0;
}