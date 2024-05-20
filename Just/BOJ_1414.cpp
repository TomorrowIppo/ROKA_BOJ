#include <bits/stdc++.h>
#define MAX 51

using namespace std;

typedef long long ll;

int n;
int parent[MAX];
vector<tuple<int, int, int>> edges;

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

    cin >> n;
    for(int i = 1; i <= n; i++) parent[i] = i;

    ll sum = 0LL;
    for(int i = 0; i < n; i++)
    {
        string inp;
        cin >> inp;
        for(int j = 0; j < n; j++)
        {
            int weight = 0;

            if(inp[j] == '0') continue;
            if('A' <= inp[j] && inp[j] <= 'Z') { weight = inp[j] - 'A'; weight += 27; }
            else if('a' <= inp[j] && inp[j] <= 'z') { weight = inp[j] - 'a'; weight += 1; }

            sum += weight;
            edges.push_back({weight, i + 1, j + 1});
        }
    }
    sort(edges.begin(), edges.end());

    int cnt = 0;
    ll ans = 0LL;
    for(auto nxt : edges)
    {
        int w, u, v;
        tie(w, u, v) = nxt;

        if(find_root(u) == find_root(v)) continue;

        merge(u, v);
        cnt++;
        ans += w;

        if(cnt == n - 1) break;
    }
    if(cnt != n - 1) cout << -1;
    else cout << sum - ans;

    return 0;
}