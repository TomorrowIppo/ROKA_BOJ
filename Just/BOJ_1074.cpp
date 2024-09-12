#include <bits/stdc++.h>

using namespace std;

int ans = 0;
int n, r, c;

void func(int x, int y, int size)   // 사분면 중 있는 r, c가 속한 사분면으로 계속 파고드는 구조
{
    if(x == r && y == c) { cout << ans; return ; }
    else if(r < x + size && c < y + size && x <= r && y <= c)   // 분할정복
    {
        func(x, y, size / 2);
        func(x, y + size / 2, size / 2);
        func(x + size / 2, y, size / 2);
        func(x + size / 2, y + size / 2, size / 2);
    }
    else { ans += size * size; }    // 없으면 넓이 더하기

    return ;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> r >> c;
    func(0, 0, pow(2, n));

    return 0;
}