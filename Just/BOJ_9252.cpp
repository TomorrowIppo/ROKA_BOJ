#include <bits/stdc++.h>
#define MAX 1001

using namespace std;

int dp[MAX][MAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    for(int i = 0; i < s1.size(); i++)
        for(int j = 0; j < s2.size(); j++)
        {
            if(s1[i] == s2[i]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }

    return 0;
}