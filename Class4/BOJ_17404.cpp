#include <bits/stdc++.h>
#define MAX 1001
#define INF 987654321

using namespace std;

int n;
int ans = INF;
int cost[MAX][3];

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int r, g, b;
        cin >> r >> g >> b;

        cost[i][0] = r;
        cost[i][1] = g;
        cost[i][2] = b;
    }

    for(int start = 0; start < 3; start++)
    {
        int dp[MAX][3]; 
        // 시작할 때 당시 선택되지 않은 색은 INF로 지정하여 선택되지 못 하도록 함.
        for(int i = 0; i < 3; i++)
        {
            if(i == start) dp[1][i] = cost[1][i];
            else dp[1][i] = INF;
        }
        
        for(int i = 2; i <= n; i++)
        {
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2];
        }

        for(int i = 0; i < 3; i++)
        {
            if(start == i) continue;    // 시작과 끝은 같을 수 없다.
            ans = min(ans, dp[n][i]);
        }
    }

    cout << ans << '\n';

    return 0;
}