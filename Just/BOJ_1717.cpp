#include <bits/stdc++.h>
#define MAX 1000001

using namespace std;

int find_root(int x);
void make_union(int x, int y);
bool isUnion(int x, int y);

int parent[MAX];
int n, m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        parent[i] = i;
    
    for(int i = 0; i < m; i++)
    {
        int x, u ,v;
        cin >> x >> u >> v;

        if(x == 0)
            make_union(u, v);
        else
        {
            if(find_root(u) == find_root(v)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    
    return 0;
}

int find_root(int x)
{
    if(x == parent[x]) return x;
    return parent[x] = find_root(parent[x]);    // 경로 압축
}

void make_union(int x, int y)
{
    x = find_root(x);
    y = find_root(y);

    if(x > y) parent[x] = y;
    else parent[y] = x;
}

bool isUnion(int x, int y)
{
    x = find_root(x);
    y = find_root(y);
    return (x == y);
}