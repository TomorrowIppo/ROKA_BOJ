#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> ls;
    for(int i = 0; i < n; i++)
    {
        int inp;
        cin >> inp;
        ls.push_back(inp);
    }
    sort(ls.begin(), ls.end());

    int l = 0;
    int r = n - 1;
    int resL = ls[l], resR = ls[r];
    ll res = abs(ls[l] + ls[r]);

    while(l < r)
    {
        ll tmp = ls[l] + ls[r];
        if(abs(tmp) < res)
        {
            resL = ls[l];
            resR = ls[r];
            res = abs(tmp);
        }

        if(tmp < 0) l++;
        else r--;
    }
    cout << resL << ' ' << resR;

    return 0;
}