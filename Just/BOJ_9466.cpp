#include <bits/stdc++.h>
#define MAX 100001

using namespace std;

int linked = 0;
int graph[MAX];
bool vis[MAX];
bool done[MAX];

void getLinked(int node);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        for(int u = 1; u <= n; u++) cin >> graph[u];

        for(int node = 1; node <= n; node++)
        {
            if(vis[node]) continue;
            getLinked(node);    
        }
        cout << n - linked << '\n';
        memset(vis, false, sizeof(vis));
		memset(done, false, sizeof(done));
        linked = 0;
    }

    return 0;
}

void getLinked(int node)
{
    vis[node] = true;
    int nxt = graph[node];

    if(!vis[nxt]) getLinked(nxt);
    else if(!done[nxt])
    {
        for(int i = nxt; i != node; i = graph[i])
        {
            linked++;
        }
        linked++;
    }
    done[node] = true;
  

    return ;
}