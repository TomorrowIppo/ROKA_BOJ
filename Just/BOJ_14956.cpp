#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int N, M, locX, locY;

void findLoc(int n, int m)
{
    // 기저사례 처리 N == 2
    if(n == 2)
    {
        switch(m)
        {
            case 0:
                locX = 1;
                locY = 1;
                return;
            case 1:
                locX = 1;
                locY = 2;
                return;
            case 2:
                locX = 2;
                locY = 2;
                return;
            case 3:
                locX = 2;
                locY = 1;
                return;
            default:
                throw;
        }
    }

    // N > 2
    int half = n / 2;
    int quadrant = m / (half * half);
    
    findLoc(half, m % (half * half));

    switch (quadrant) {
        int tmp;
        case 0:
            tmp = locX;
            locX = locY;
            locY = tmp;
            break;
        case 2:
            locX += half;
        case 1:
            locY += half;
            break;
        case 3:
            tmp = locY;
            locY = half + 1 - locX;
            locX = (2 * half) + 1 - tmp;
            break;
        default:
            throw;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    findLoc(N, M - 1);
    cout << locX << ' ' << locY << endl;    

    return 0;
}