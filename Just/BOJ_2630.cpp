#include <bits/stdc++.h>
#define MAX 129
#define endl "\n"

using namespace std;

// white = 0, blue = 1
// n은 한 변의 길이이지만, 탐색범위이기도 하다.

int board[MAX][MAX];
int N;
int white_cnt, blue_cnt;

void divide_color(int n, int x, int y)
{
    int first_color = board[x][y];  // 초기 위치의 색을 통해 모두 같은 색인지 판단을 위한 변수
    bool is_all_same = true;

    for(int i = x; i < x + n; i++)
    {
        for(int j = y; j < y + n; j++)
        {
            if(board[i][j] != first_color) 
            {
                is_all_same = false;
                break;
            }
        }
    }

    if(!is_all_same)
    {
        divide_color(n / 2, x, y);
        divide_color(n / 2, x + (n / 2), y);
        divide_color(n / 2, x, y + (n / 2));
        divide_color(n / 2, x + (n / 2), y + (n / 2));
    }
    else (first_color == 0) ? ++white_cnt : ++blue_cnt;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> board[i][j];

    divide_color(N, 0, 0);
    cout << white_cnt << endl << blue_cnt;

    return 0;
}