#include <bits/stdc++.h>
#define MAX 101

using namespace std;

typedef long double ld;
typedef long long ll;
typedef struct
{
    ll x;
    ll y;
}Coord;

int n, s, p;
vector<tuple<ld, int, int>> edges;
int parent[MAX];
vector<Coord> Coords;

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

ld get_dist(Coord c1, Coord c2)
{
    ll dx = abs(c1.x - c2.x);
    ll dy = abs(c1.y - c2.y);

    return sqrt(pow(dx, 2) + pow(dy, 2));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--)
    {   
        // input
        cin >> s >> p;
        for(int i = 1; i <= n; i++) parent[i] = i;  // Union-Find를 위한 사전작업

        // 좌표입력
        for(int i = 0; i < p; i++)
        {
            ll x, y;
            cin >> x >> y;
            Coords.push_back({x, y});
        }

        for(int i = 1; i < p; i++)
        {
            for(int j = i + 1; j <= p; j++)
            {
                Coord c1 = Coords[i - 1];
                Coord c2 = Coords[j - 1];

                ld dist = get_dist(c1, c2);
                edges.push_back({dist, i, j});
            }
        }
        sort(edges.begin(), edges.end());

        ld ans = 0.0l;
        int cnt = 0;
        for(auto nxt : edges)
        {
            ld dist;
            int u, v;
            tie(dist, u, v) = nxt;

            if(find_root(u) == find_root(v)) continue;

            merge(u, v);
            cnt++;
            ans += dist;

            if(cnt == s - 1) break;
        }
        cout.precision(2);
        cout << fixed << ans << '\n';
        edges.clear();
        Coords.clear();
    }

    return 0;
}