#include <bits/stdc++.h>
#define MAX 200001
#define endl "\n"

using namespace std;

void input();
void topological_sort();

int n, m, k;
int indegree[MAX];
bool vis[MAX];
vector<int> adj[MAX];
vector<int> res;
int recipe[MAX];
vector<int> default_stuff;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    topological_sort();

    return 0;
}

void input()
{
     // input
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int len, to;

        cin >> len;
        for(int j = 0; j < len; j++)
        {
            int x;
            cin >> x;
            adj[x].push_back(i);
            indegree[i]++;
        }

        cin >> to;
        recipe[i] = to;
    }

    cin >> k;
    for(int i = 0; i < k; i++)
    {
        int inp;
        cin >> inp;
        default_stuff.push_back(inp);
    }
}

void topological_sort()
{
    queue<int> q;
    for(auto nxt : default_stuff) 
    {
        if(!vis[nxt]) { res.push_back(nxt); q.push(nxt); vis[nxt] = true; }
    }

    while(!q.empty())
    {
        auto cur = q.front(); q.pop();

        for(auto nxt : adj[cur])
        {
            indegree[nxt]--;

            if(indegree[nxt] == 0)
            {
                if(!vis[recipe[nxt]])
                {
                    res.push_back(recipe[nxt]);
                    q.push(recipe[nxt]);
                    vis[recipe[nxt]] = true;
                }
            }
        }
    }   

    sort(res.begin(), res.end());
    cout << res.size() << endl;
    for(auto nxt : res) cout << nxt << " ";
}