#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef struct
{
    int x;
    int y;
}Point;

int ccw(Point p1, Point p2, Point p3)
{
    ll det = (p2.x-p1.x) * (p3.y-p1.y) - (p2.y-p1.y) * (p3.x-p1.x);
    
    if(det > 0) return 1;       // 반시계방향
    else if(det < 0) return -1; // 시계방향
    else return 0;              // 세 점이 일직선상에 놓여있음
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Point P1, P2, P3, P4;
    int x1, x2, x3, x4;
    int y1, y2, y3, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    // 1. 서로 교차할 때
    // 2. 서로 교차하지 않을 때
    // 3-1. 서로 일직선상에 있지만, 포개어지지 않을 때
    // 3-2. 서로 일직선상에 있찌만, 포개어질 때

    return 0;
}