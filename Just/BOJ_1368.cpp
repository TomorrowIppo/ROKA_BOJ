#include <bits/stdc++.h>
#define MAX 302

/*

우물을 팔 때의 비용을 가상의 x 노드에서부터의 거리로 두고 접근하면 쉬움.

*/

using namespace std;

typedef long long ll;

int N;
vector<tuple<int, int, int>> edges;
int parent[MAX];

int find_root(int x)
{
    if (x == parent[x]) return x;
    return parent[x] = find_root(parent[x]);
}

bool is_Union(int x, int y)
{
    x = find_root(x);
    y = find_root(y);
    
    if(x == y) return true;
    else
    {
        if(x > y) parent[x] = y;
        else parent[y] = x;
        return false;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for(int i = 1; i <= N; i++) parent[i] = i;
    parent[301] = 301;
    
    for(int i = 1; i <= N; i++)
    {
        int cost; cin >> cost;
        edges.push_back({cost, 301, i});
    }
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            int cost; cin >> cost;
            if(i >= j) continue;    // 중복입력 방지
            
            edges.push_back({cost, i, j});
        }
    }
    sort(edges.begin(), edges.end());
    
    int cnt = 0; ll ans = 0LL;
    for(auto nxt : edges)
    {
        int cost, u, v;
        tie(cost, u, v) = nxt;
        
        if(is_Union(u, v)) continue;
        
        ans += cost; cnt++;
        if(cnt == N) break;    // 가상의 x 노드까지 감안해서
    }
    cout << ans;
}