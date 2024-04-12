#include <bits/stdc++.h>
#define MAX 26

using namespace std;

int indegree[MAX];
vector<int> adj[MAX];
int dp[MAX];
int time_taken[MAX];

void TopologicalSort()
{
    int ret = 0;
    queue<int> q;
    for(int i = 0; i < MAX; i++)
        if(time_taken[i] != 0 && indegree[i] == 0) { q.push(i); dp[i] = time_taken[i]; }
    
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        for(auto nxt : adj[cur])
        {
            indegree[nxt]--;
            if(indegree[nxt] == 0) q.push(nxt);
            dp[nxt] = max(dp[nxt], dp[cur] + time_taken[nxt]);
        }
        ret = max(ret, dp[cur]);
    }
    cout << ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    string s;
	while (getline(cin, s)) {
		stringstream ss(s);
		char a; int b,to; string c;
		ss >> a >> b;
		to = a - 'A';
		time_taken[to] = b;
		if (ss >> c) for (int i = 0; i < c[i]; i++) {
			adj[c[i] - 'A'].push_back(to);
			indegree[to]++;
		}
	}

    // solve
    TopologicalSort();

    return 0;
}