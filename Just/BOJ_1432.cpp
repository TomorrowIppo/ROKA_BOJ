#include <bits/stdc++.h>
#define MAX 51

using namespace std;

int n;
int indegree[MAX];
vector<int> adj[MAX];
vector<int> result;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        string inp;
        cin >> inp;
        for(int j = 1; j <= n; j++)
        {
            if(i >= j) continue;
            if(inp[j - 1] == '1')
            {
                
            }

        }
    }

    return 0;
}