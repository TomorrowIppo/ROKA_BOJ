#include <bits/stdc++.h>
#define MAX 64 + 1
#define endl "\n"

using namespace std;

char board[MAX][MAX];
string ans = "";
int tmp;

void dc(int n, int x, int y)
{
    bool is_all_same = true;
    char init_value = board[x][y];

    for(int i = x; i < x + n; i++)
        for(int j = y; j < y + n; j++)
        {
            if(init_value != board[i][j])
            {
                is_all_same = false;
                break;
            }
        }
    
    if(!is_all_same)
    {
        ans += "(";
        dc(n / 2, x, y);
        dc(n / 2, x, y + (n / 2));
        dc(n / 2, x + (n / 2), y);
        dc(n / 2, x + (n / 2), y + (n / 2));
        ans += ")";
    }
    else
    {
        if(init_value == '0') ans += "0";
        else ans += "1";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string inp;
        cin >> inp;

        for(int j = 0; j < n; j++)
        {
            board[i][j] = inp[j];
        }
    }
        
    dc(n, 0, 0);
    cout << ans;

    return 0;
}