#include <bits/stdc++.h>

using namespace std;

int dp[10001];

int main()
{   
    dp[0] = 1;
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int val, typ;
    cin >> val >> typ;
    
    vector<pair<int, int>> coin(typ);
    
    for (int i = 0; i < typ; ++i)
    {
        int x, c;
        cin >> x >> c;
        coin[i] = {x, c};
    }
    
    for (int i = 0; i < typ; ++i)
    {
        int coin_val = coin[i].first;
        int coin_cnt = coin[i].second;
        
        for (int j = val; j >= 0; --j)
            for (int k = 1; k <= coin_cnt && j - coin_val * k >= 0; ++k)
                dp[j] += dp[j - coin_val * k];
    }
    
    cout << dp[val];
}