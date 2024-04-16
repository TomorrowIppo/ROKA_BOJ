#include <bits/stdc++.h>
#define MAX 100001

using namespace std;

typedef long long ll;

int n, m;
int parent[MAX];
ll dist[MAX];

int find_root(int x)
{
    if(x == parent[x]) return x;

    int p = find_root(parent[x]);
    dist[x] += dist[parent[x]];

    return parent[x] = p;
}

void merge(int x, int y, int w)
{
    int rootx = find_root(x);
    int rooty = find_root(y);

    if(rootx == rooty) return ;

    dist[rooty] = dist[x] - dist[y] + w;
    parent[rooty] = rootx;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true)
    {
        cin >> n >> m;
        if(n == 0 && m == 0) break;

        for(int i = 1; i <= n; i++) parent[i] = i;

        for(int i = 0; i < m; i++)
        {
            char order;
            cin >> order;

            if(order == '!')
            {
                int x, y, w;
                cin >> x >> y >> w;
                merge(x, y, w);
            }
            else
            {
                int x, y;
                cin >> x >> y;
                
                if(find_root(x) != find_root(y)) cout << "UNKNOWN\n";
                else cout << dist[y] - dist[x] << '\n';
            }
        }

        for(int i = 1; i <= n; i++) { parent[i] = 0; dist[i] = 0LL;}
    }

    return 0;
}
