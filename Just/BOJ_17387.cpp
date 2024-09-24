#include <bits/stdc++.h>
#define X first
#define Y second
#define endl "\n"

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

bool compare(pii p1, pii p2)
{
    if(p1.X == p2.X)
    {
        return p1.Y <= p2.Y;
    }
    else return p1.X <= p2.X;
}

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

    if(cmp1 * cmp2 <= 0LL && cmp3 * cmp4 <= 0LL)
    {
        if(cmp1 * cmp2 == 0LL && cmp3 * cmp4 == 0LL)
        {
            if(compare(p1, p2)) swap(p1, p2);
            if(compare(p3, p4)) swap(p3, p4);

            // 선이 일직선상에 있을 때, l1 가장 큰 점 l2 가장 작은 점, l1 가장 작은 점 l2 가장 큰 점 비교를 용이하게 하기 위해서
            if(compare(p4, p1) && compare(p2, p3)) cout << '1' << endl;
            else cout << '0' << endl;
        }
        else cout << '1' << endl;
    }
    else cout << '0' << endl;

    return 0;
}