#include <bits/stdc++.h>
#define MAX 123456 + 1

using namespace std;

typedef struct
{
    char species;
    int cnt;
}dataSet;

int n, res;
dataSet tree[MAX];
vector<int> adj[MAX];
queue<int> q;
bool vis[MAX];

void dfs(int cur, int cnt)
{
    if(cur == 1) { res += cnt; return ; }

    for(auto nxt : adj[cur])
    {
        if(vis[nxt]) continue;  // 재방문 방지

        int calc = (tree[nxt].species == 'W') ? (cnt - tree[nxt].cnt) : cnt;

        if(tree[nxt].species == 'W')
        {
            if(cnt >= tree[nxt].cnt) tree[nxt].cnt = 0;
            else tree[nxt].cnt -= cnt;

            if(calc <= 0) return ;  // 늑대를 만나고 모두 다 잡아먹혔을 때
        }
        
        vis[nxt] = true;
        dfs(nxt, calc);
        vis[nxt] = false;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    cin >> n;
    for(int u = 2; u <= n; u++)
    {
        char s; int cnt; int v;
        cin >> s >> cnt >> v;

        if(s == 'S') q.push(u);  // 초기 양의 위치 저장
        
        tree[u] = {s, cnt};
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // solve
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();

        vis[cur] = true;
        dfs(cur, tree[cur].cnt);
        vis[cur] = false;
    }
    cout << res;

    return 0;
}