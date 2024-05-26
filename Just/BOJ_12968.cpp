#include <bits/stdc++.h>

using namespace std;

int r, c, k;

int main()
{
    ios::sync_with_stdio(0);   
    cin.tie(0);

    cin >> r >> c >> k;

    if(k == 1) cout << 1;
    else if((r == 2 && c == 1) || (r == 1 && c == 2)) cout << 1;
    else
    {
        if(r >= 2 || c >= 2)
        {
            if(r % 2 == 0 || c % 2 == 0) cout << 1;
            else cout << 0;
        }
        else cout << 0;
    }
    
    return 0;
}