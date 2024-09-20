#include <bits/stdc++.h>
#define MAX 1001
#define endl "\n"

using namespace std;

/* 

B_min <= k <= B_max면 존재가능

*/

int n, m, k;
int parent[MAX];
vector<tuple<int, int, int>> B_max_edges;
vector<tuple<int, int, int>> R_max_edges;

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

bool is_same_group(int x, int y)
{
    x = find_root(x);
    y = find_root(y);
    
    return x == y;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(true)
    {
        B_max_edges.clear();
        R_max_edges.clear();
        
        cin >> n >> m >> k;
        if(n == 0 && m == 0 && k == 0) break;
        
        for(int i = 0; i < m; i++)
        {
            char c;
            int u, v;
            cin >> c >> u >> v;
            
            if(c == 'B') 
            {
                B_max_edges.push_back({0, u, v});
                R_max_edges.push_back({1, u, v});
            }
            else
            {
                B_max_edges.push_back({1, u, v});
                R_max_edges.push_back({0, u, v});
            }
        }
        sort(B_max_edges.begin(), B_max_edges.end());
        sort(R_max_edges.begin(), R_max_edges.end());

        // blue_max_kruskal
        int cnt = 0;
        int b_cnt = 0;
        for(int i = 1; i <= n; i++) parent[i] = i;
        for(auto nxt : B_max_edges)
        {
            int d, u, v;
            tie(d, u, v) = nxt;
            
            if(is_same_group(u, v)) continue;
            if(d == 0) b_cnt++;
            
            merge(u, v);
            cnt++;
            
            if(cnt == n - 1) break;
        }

        // red_max_kruskal
        cnt = 0;
        int r_cnt = 0;
        for(int i = 1; i <= n; i++) parent[i] = i;
        for(auto nxt : R_max_edges)
        {
            int d, u, v;
            tie(d, u, v) = nxt;
            
            if(is_same_group(u, v)) continue;
            if(d == 0) r_cnt++;
            
            merge(u, v);
            cnt++;
            
            if(cnt == n - 1) break;
        }
        if(n - 1 - r_cnt <= k && k <= b_cnt) cout << 1 << endl;
        else cout << 0 << endl;
    }
    
    return 0;
}