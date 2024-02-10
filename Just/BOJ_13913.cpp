#include <bits/stdc++.h>
#define MAX 100001

using namespace std;

typedef struct
{
    int cur;
    vector<int> root;
} dataSet;

void bfs(int start, int end);

int n, k;
int dx[2] = {-1, 1};
bool vis[MAX];
vector<int> root;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    cin >> n >> k;
    root.push_back(n);
    
    // solve
    bfs(n, k);

    return 0;
}

void bfs(int start, int end)
{
    queue<dataSet> q;
    q.push({start, vector<int>()});
}