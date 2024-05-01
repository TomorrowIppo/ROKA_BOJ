#include <bits/stdc++.h>
#define MAX 1001

using namespace std;

/*

소수점 n번째 자리까지 반올림하여서 출력

cout << fixed;
cout.precision(n);
cout << ans;

형식으로 할 것

*/

typedef struct
{
    int x;
    int y;
}Coord;

int n, m;
double ans;
vector<tuple<double, int, int>> edges;
vector<Coord> Coords;
int parent[MAX];
bool anti_duplication[MAX][MAX];

int find_root(int x)
{
    if(x == parent[x]) return x;
    return parent[x] = find_root(parent[x]);
}

bool is_Union(int x, int  y)
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
        int x, y;
        cin >> x >> y;
        Coords.push_back({x, y});
    }

    int duplication = 0;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        if(anti_duplication[u][v] || anti_duplication[v][u]) duplication++; // 중복 입력 방지 ex) 1 4과 4 1

        anti_duplication[u][v] = true;
        anti_duplication[v][u] = true;

        is_Union(u, v);   
    }

    // 이미 다 연결 되어있는 경우
    if(n == m) { cout << "0.00"; return 0; }

    // setting
    for(int i = 1; i < n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            if(find_root(i) == find_root(j)) continue;
            
            int x1 = Coords[i - 1].x;
            int y1 = Coords[i - 1].y;
            int x2 = Coords[j - 1].x;
            int y2 = Coords[j - 1].y;

            double dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
            edges.push_back({dist, i , j});
        }
    }
    sort(edges.begin(), edges.end());

    // solve
    int cnt = 0;
    for(auto nxt : edges)
    {
        double dist;
        int u, v;
        tie(dist, u, v) = nxt;

        if(is_Union(u, v)) continue;

        cnt++; ans += dist;

        if(cnt == n - m - 1 + duplication) break;
    }
    cout << ans;

    return 0;
}