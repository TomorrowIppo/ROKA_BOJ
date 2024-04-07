#include <bits/stdc++.h>
#define MAX 51

using namespace std;

void dfs(int cur);

int n, del_node, root;
vector<int> adj[MAX];
int parent[MAX];
int leaf[MAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 입력
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> parent[i];
        if(parent[i] == -1) root = i;
    }
    cin >> del_node;

    if(del_node == root) { cout << 0; return 0; }

    // 트리 설정
    for(int i = 0; i < n; i++)
    {
        if(i == root) continue;
        if(i == del_node || parent[i] == del_node) continue;    // 지울 노드와 연결
        adj[i].push_back(parent[i]);
        adj[parent[i]].push_back(i);
    }

    // 리프노드 수 세기
    dfs(root);
    cout << leaf[root];   

    return 0;
}

void dfs(int cur)
{
    if(cur != root && adj[cur].size() == 1) { leaf[cur] = 1; return ; }
    if(cur == root && adj[cur].size() == 0) { leaf[cur] = 1; return ; }
    for(auto nxt : adj[cur])
    {
        if(nxt == parent[cur]) continue;    // 부모 노드 방문 방지
        dfs(nxt);
        leaf[cur] += leaf[nxt];
    }
}