#include <bits/stdc++.h>
#define MAX 32769
using namespace std;

int num = 0;
int r, c;
int ans = 0;

void func(int n, int x, int y)
{
    int range = pow(2, n);
    int x_to = 0;
    int y_to = 0;
    int area = pow(range / 2, 2);

    if(n == 1)
    {
        if(x == r && y == c) cout << ans;
        if(x == r && y == c + 1) cout << ans + 1;
        if(x == r + 1 && y == c) cout << ans + 2;
        if(x == r + 1 && y == c + 1) cout << ans + 3;

        return ;
    }
    else
    {
        if(0 <= r && r <= (range / 2) - 1 && 0 <= c && c <= (range / 2) - 1)    // 1번 영역
        {
            x_to = x; 
            y_to = y;
        }
        if(0 <= r && r <= (range / 2) - 1 && (range / 2) <= c && c <= range - 1)    // 2번 영역
        {
            x_to = x; 
            y_to = (range / 2) - 1;
            ans = area;
        }
        if((range / 2) <= r && r <= range - 1 && 0 <= c && c <= (range / 2) - 1)    // 3번 영역
        {
            x_to = (range / 2) - 1; 
            y_to = y;
            ans = area * 2;
        }
        if((range / 2) <= r && r <= range - 1 && (range / 2) <= c && c <= range - 1)    // 4번 영역
        {
            x_to = (range / 2) - 1; 
            y_to = (range / 2) - 1;
            ans = area * 3;
        }
        func(n - 1, x_to, y_to);
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n >> r >> c;
    
    func(n, r, c);
    
    return 0;
}