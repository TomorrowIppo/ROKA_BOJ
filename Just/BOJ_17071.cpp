#include <bits/stdc++.h>
#define MAX 500001
#define cur first
#define time second

using namespace std;

void bfs(int start, int end);

int s, e;
bool vis[MAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    cin >> s >> e;

    //solve
    bfs(s, e);

    return 0;
}

void bfs(int start, int end)
{
    queue<pair<int, int>> q;
    q.push({start, 0});
    vis[start] = true;

    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        
    }
}
