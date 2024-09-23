#include <bits/stdc++.h>
#define X first
#define Y second
#define endl "\n"

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

ll ccw(pii center, pii p1, pii p2)
{
    ll det = (p1.X - center.X) * (p2.Y - center.Y);
    det -= (p1.Y - center.Y) * (p2.X - center.X);

    if(det > 0LL) return 1LL;   // 반시계 방향
    else if(det == 0LL) return 0LL; // 일직선상
    else return -1LL; // 시계 방향
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    pii p1, p2, p3, p4;
    cin >> p1.X >> p1.Y >> p2.X >> p2.Y >> p3.X >> p3.Y >> p4.X >> p4.Y;

    ll cmp1 = ccw(p3, p1, p2);
    ll cmp2 = ccw(p4, p1, p2);
    ll cmp3 = ccw(p1, p3, p4);
    ll cmp4 = ccw(p2, p3, p4);

    if(cmp1 == 0LL || cmp2 == 0LL || cmp3 == 0LL || cmp4 == 0LL) cout << '0' << endl;   // 세 점이 일직선상에 위치한 경우
    else if(cmp1 * cmp2 < 0LL && cmp3 * cmp4 < 0LL) cout << '1' << endl;
    else cout << '0' << endl;

    return 0;
}