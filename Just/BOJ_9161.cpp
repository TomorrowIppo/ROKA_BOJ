#include <bits/stdc++.h>
#define MIN 100
#define MAX 999

using namespace std;

int _exception = 111;

void is_able(int x, int y)
{
    if((x * (y % 100) == (x / 10) * y) && (x % 10 == y / 100))
    {
        cout << x << " / " << y << " = " << (int)(x / 10) << " / " << y % 100 << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = MIN; i <= MAX; i++)
    {
        for(int j = MIN; j <= MAX; j++)
        {
            if(i % _exception == 0 && j % _exception == 0) continue;
            if(i == j) continue;
            
            is_able(i, j);
        }
    }
    
    return 0;
    
}