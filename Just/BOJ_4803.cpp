#include <bits/stdc++.h>
#define MAX 501

using namespace std;

int n, m;
int parent[MAX];
bool isCycle[MAX];

int find_root(int u)
{
    if(u == parent[u]) return u;
    return parent[u] = find_root(parent[u]);  // 경로압축
}

int count_tree()
{
    int res = 0;
    vector<int> root;
    sort(parent, parent + n);

    int pin = parent[1];
    root.push_back(pin);
    for(int i = 2; i <= n; i++)
        if(pin != parent[i]) { pin = parent[i]; root.push_back(pin); }

    for(auto nxt : root)
        if(!isCycle[nxt]) res++;
            
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    while(true)
    {
        cin >> n >> m;
        if(n == 0 && m == 0) break;

        int tree_cnt = 0;
        for(int i = 1; i <= n; i++) { parent[i] = i; isCycle[i] = false; }
        
        for(int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            
            int root_u = find_root(u);
            int root_v = find_root(v);

            if(root_u == root_v) isCycle[root_u] = true;    // 사이클 발생 시
            else
            {
                if(isCycle[root_u] || isCycle[root_v]) { isCycle[root_u] = true; isCycle[root_v] = true; }  // 사이클과 연결하려고 할 시
 
                if(root_u > root_v) parent[root_u] = root_v;
                else parent[root_v] = root_u;
                
            }
        }
        tree_cnt = count_tree();

        if(tree_cnt == 0) cout << "Case " << T << ": No trees.\n";
        else if(tree_cnt == 1) cout << "Case " << T << ": There is one tree.\n";
        else cout << "Case " << T << ": A forest of " << tree_cnt << " trees.\n";

        T++;
    }
    
    return 0;
}
