#include <bits/stdc++.h>
#define MAX 100001

using namespace std;

void bfs(int root);

int n;
vector<int> tree[MAX];
int parent[MAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n - 1; i++)
    {
        int p, c;
        cin >> p >> c;
        tree[p].push_back(c);
        tree[c].push_back(p);
    }
    bfs(1);

    for(int i = 2; i <= n; i++)
        cout << parent[i] << '\n';

    return 0;
}

void bfs(int root)
{
    queue<int> q;
    q.push(root);

    while(!q.empty())
    {
        auto cur = q.front(); q.pop();

        for(auto nxt : tree[cur])
        {
            if(parent[cur] == nxt) continue;
            parent[nxt] = cur;
            q.push(nxt);
        }
    }
}