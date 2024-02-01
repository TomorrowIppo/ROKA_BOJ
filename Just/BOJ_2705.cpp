#include <bits/stdc++.h>
#define MAX 1001

using namespace std;

int dp[MAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 1; i < MAX; i++) dp[i] = 1;
    for(int i = 1; i < MAX; i++)
    {
        for(int j = 0; j < i - 1; j++)
        {
            if((i - j) % 2 != 0) continue;
            dp[i] += dp[(i - j) / 2];
        }
    }

    int n, t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << dp[n] << '\n';
    }
}