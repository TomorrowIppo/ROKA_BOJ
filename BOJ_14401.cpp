#include <bits/stdc++.h>
#define MAX 501
#define endl "\n"

using namespace std;

typedef long long ll;
typedef struct 
{
    ll x;
    ll y;
    int num;
}Point;

int n, m;
int parent[MAX];
vector<Point> points;
vector<tuple<ll, int, int>> edges;

int ccw(Point center, Point p1, Point p2)
{
    ll det = (p1.x - center.x) * (p2.y - center.y);
    det -= (p1.y - center.y) * (p2.x - center.x);

    if(det > 0LL) return -1;
    else if(det == 0LL) return 0;
    else return 1;
}

int find_root(int x)
{
    if(x == parent[x]) return x;
    return parent[x] = find_root(parent[x]);
}

// merge랑 is_same_group에서 x = find_root(x), y = find_root(y)가 아닌 x = parent[x], y = parent[y]로 해놓고 있었다
// 근데 이상하게 예제는 다 맞아서 이상함을 눈치채지 못했다
void merge(int x, int y)
{
    x = find_root(x);
    y = find_root(y);

    if(x > y) parent[x] = y;
    else parent[y] = x;
}

bool is_same_group(int x, int y)
{
    x = find_root(x);
    y = find_root(y);

    return x == y;
}

bool cmp(Point p1, Point p2)
{
    if(p1.x == p2.x) return p1.y <= p2.y;
    return p1.x <= p2.x;
}

ll get_cost(Point p1, Point p2)
{
    ll ret = pow(p2.x - p1.x, 2);
    ret += pow(p2.y - p1.y, 2);

    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) parent[i] = i;

    int edge_cnt = n - 1;
    for(int i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        points.push_back({x, y, i});
    }

    // Union-Find를 통해 사이클 발생하지 않은 경우에는 MST의 cnt 개수 -1 아니면 그냥 스킵
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        if(!is_same_group(u, v))
        {
            edge_cnt--;
            merge(u, v);
        }
    }
    sort(points.begin(), points.end(), cmp);

    // 임의의 두 점 사이에 있는 점들이 처음 두 점과 일직선 상에 있는지 검사 후 edges에 push_back (여기 다시 구현하기)
    for(int i = 0; i < n; i++)
    {
        for(int j = n - 1; j > i; j--)
        {
            bool is_able_line = true;
            Point p1 = points[i];
            Point p2 = points[j];
            for(int k = i + 1; k < j; k++)
            {
                Point center = points[k];

                int dir = ccw(center, p1, p2);
                //cout << "i : " << i + 1 << ", j : " << j + 1 << ", k : " << k + 1 << ", dir : " << dir << endl;

                if(dir == 0) is_able_line = false;
            }
            
            if(is_able_line) edges.push_back({get_cost(p1, p2), p1.num, p2.num});
        }
    }
    sort(edges.begin(), edges.end(), greater<>());

    int cnt = 0;
    ll sum = 0LL;
    for(auto nxt : edges)
    {
        ll d;
        int u, v;
        tie(d, u, v) = nxt;

        if(is_same_group(u, v)) continue;

        merge(u, v);
        sum += d;
        cnt++;

        if(cnt == edge_cnt) break;
    }
    cout << sum << endl;
}