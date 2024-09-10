#include <bits/stdc++.h>
#define MAX 32769
using namespace std;

int num = 0;
vector<vector<int>> _map(MAX, vector<int>(MAX, 0));

void func(int n, int x, int y)
{
    if(n > 1)
    {
        int x_to = x + pow(2, n - 1);
        int y_to = y + pow(2, n - 1);
        
        func(n - 1, x, y);
        func(n - 1, x, y_to);
        func(n - 1, x_to, y);
        func(n - 1, x_to, y_to);
    }
    else if(n == 1)
    {
        _map[x][y] = num++;
        _map[x][y + 1] = num++;
        _map[x + 1][y] = num++;
        _map[x + 1][y + 1] = num++;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, r, c;
    cin >> n >> r >> c;
    
    func(n, 0, 0);
    cout << _map[r][c];
    
    return 0;
}