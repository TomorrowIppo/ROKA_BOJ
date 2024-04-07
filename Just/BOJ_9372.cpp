#include <bits/stdc++.h>

using namespace std;

int t, n, m;
vector<int> adj;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
        }
        cout << n - 1 << '\n';
    }

    return 0;
}