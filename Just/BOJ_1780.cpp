#include <bits/stdc++.h>
#define MAX 2187 + 1
#define endl "\n"

using namespace std;

int board[MAX][MAX];
int n;
int cnt_, cnt_0, cnt_1;

void dc(int n, int x, int y)
{
    bool is_all_same = true;
    int init_value = board[x][y];

    for(int i = x; i < x + n; i++)
        for(int j = y; j < y + n; j++)
            if(board[i][j] != init_value) 
            {
                is_all_same = false;
                break;
            }

    // 주어진 영역의 값이 동일하지 않은 경우
    if(!is_all_same)
    {
        dc(n / 3, x, y);
        dc(n / 3, x, y + (n / 3));
        dc(n / 3, x, y + 2 * ((n / 3)));
        dc(n / 3, x + (n / 3), y);
        dc(n / 3, x + (n / 3), y + (n / 3));
        dc(n / 3, x + (n / 3), y + 2 * (n / 3));
        dc(n / 3, x + 2 * (n / 3), y);
        dc(n / 3, x + 2 * (n / 3), y + (n / 3));
        dc(n / 3, x + 2 * (n / 3), y + 2 * (n / 3));
    }
    else
    {
        
        if(init_value == -1) cnt_++;
        else if(init_value == 0) cnt_0++;
        else cnt_1++;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];

    dc(n, 0, 0);
    cout << cnt_ << endl << cnt_0 << endl << cnt_1;

    return 0;
}