#include <bits/stdc++.h>
#define MAX 100001

using namespace std;

int n, m;
int oper_cnt;
int parent[MAX];

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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) parent[i] = i;

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        int root_u = find_root(u);
        int root_v = find_root(v);

        if(root_u != root_v) merge(u, v);
        else oper_cnt++;
    }

    for(int i = 1; i <= n; i++)
        if(i == find_root(i)) oper_cnt++;
    
    cout << oper_cnt - 1;
    return 0;
}