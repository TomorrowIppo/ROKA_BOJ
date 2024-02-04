#include <bits/stdc++.h>
#define MAX 101

using namespace std;

/*

촌수 계산할 때, 무방향 그래프로 설정해서 dfs 탐색
p1을 시작 노드로 두고 p2 노드를 찾는 방식으로 진행

*/

int n, m;
int p1, p2;
int ans = -1;
vector<int> graph[MAX];
bool vis[MAX];
bool isFounded = false;

void dfs(int node, int end, int dist);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    cin >> p1 >> p2;
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(p1);
    if(!isFounded) cout << -1;
    else cout << ans;

    return 0;
}

void dfs(int node, int end, int dist)
{
    vis[node] = true;
    if(node == p2) { isFounded = true; return; }

    for(int nxt : graph[node])
    {
        if(vis[nxt]) continue;  // 재방문 방지
        dfs(nxt);
    }
}