#include <bits/stdc++.h>
#define MAX 51

using namespace std;

int n, m, k;
int parent[MAX];
vector<int> truth[MAX];

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

bool isUnion(int x, int y)
{
    x = find_root(x);
    y = find_root(y);

    return x == y;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    cin >> k;

    for(int i = 1; i <= n; i++) parent[i] = i;
    for(int i = 0; i < k; i++)
    {
        int tmp;
        cin >> tmp;
        parent[tmp] = 0;
    }

    for(int i = 1; i <= m; i++)
    {
        int size;
        cin >> size;
        for(int j = 0; j < size; j++)
        {
            int inp;
            cin >> inp;
            truth[i].push_back(inp);
        }
    }

    for(int i = 1; i <= m; i++)
    {
        int prev = truth[i][0];
        for(int j = 1; j < truth[i].size(); j++)
        {
            int cur = truth[i][j];
            if(!isUnion(prev, cur)) merge(prev, cur);
        }
    }

    int ans = 0;
    for(int i = 1; i <= m; i++)
    {
        int sum = 0;
        for(auto nxt : truth[i]) sum += find_root(nxt);

        if(sum == 0) ans++;
    }
    cout << m - ans;

    return 0;
}