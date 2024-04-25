#include <bits/stdc++.h>
#define MAX 300001

using namespace std;

/*

nC2 = n * (n - 1) / 2

임의의 노드 x에 대해서 : (전체 중에서 2개 고르는 경우의 수) + (x 서브트리의 노드 중에서 2개 고르는 경우의 수)

임의의 노드 x와 x의 부모노드 간의 간선을 지나는 경우의 수를 구하는 것.
Root인 1번은 부모가 없으므로 열외.
*/

typedef long long ll;

vector<int> adj[MAX];
int parent[MAX];
int subtree[MAX];
int n;
ll ans;

void makeTree(int cur)
{
    for(auto nxt : adj[cur])
    {
        if(nxt == parent[cur]) continue;
        parent[nxt] = cur;
        makeTree(nxt);
    }
}

ll comb(ll x) { return x * (x - 1LL) / 2LL; }

ll dfs(int cur)
{
    subtree[cur] = 1;
    for(auto nxt : adj[cur])
    {
        if(nxt == parent[cur]) continue;
        subtree[cur] += dfs(nxt);
    }

    return subtree[cur];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    makeTree(1);
    dfs(1);

    for(int i = 2; i <= n; i++)
        ans += (comb(n) - comb(n - subtree[i]));

    cout << ans;

    return 0;
}