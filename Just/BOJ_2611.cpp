#include <bits/stdc++.h>
#define MAX 1001

using namespace std;

typedef struct 
{
    int node;
    int r;
}Info;

void solve(int x);

int n, m;
int indegree[MAX];
int dp[MAX];
vector<Info> graph[MAX];
int end_node;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int p, q, r;
        cin >> p >> q >> r;
        graph[p].push_back({q, r});
        indegree[q]++;
    }
    solve(1);

    return 0;
}

void solve(int x)
{
    
}