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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    cin >> n >> k;

    // solve
    if(n >= k)   // start가 end보다 크거나 같을 경우 bfs 할 필요 없음
    {
        cout << n - k << '\n';
        cout << n << ' ';
        for(int i = 1; i <= (n - k); i++)
            cout << (n - i) << ' ';
    }
    else
        bfs(n, k);

    return 0;
}

void bfs(int start, int end)
{
    queue<dataSet> q;
    vector<int> root = {start};
    q.push({start, root});
    vis[start] = true;

    while(!q.empty())
    {
        auto info = q.front(); q.pop();

        if(info.cur == end) 
        {
            cout << info.root.size() - 1 << '\n';
            for(int i = 0; i < info.root.size(); i++)
                cout << info.root[i] << ' ';
            break;
        }

        // 좌 우 이동
        for(int dir = 0; dir < 2; dir++)
        {
            int nx = info.cur + dx[dir];
            vector<int> ls = info.root;

            if(nx < 0 || nx >= MAX) continue;
            if(vis[nx]) continue;

            vis[nx] = true;
            ls.push_back(nx);
            q.push({nx, ls});
        }

        // 순간이동 처리
        int nx = info.cur * 2;
        if(nx >= MAX) continue;
        if(vis[nx]) continue;

        vis[nx] = true;
        info.root.push_back(nx);
        q.push({nx, info.root});
    }
}