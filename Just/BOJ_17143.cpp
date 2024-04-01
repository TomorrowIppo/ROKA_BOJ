#include <bits/stdc++.h>
#define MAX 101
#define X first
#define Y second

using namespace std;

typedef pair<int, int> pii;
typedef struct 
{
    int speed;
    int direction;  // d) 1 up | 2 down | 3 right | 4 left
    int size;
}Shark;

void input();
void solve();
void gotcha(int c);
void simulate();
void move(vector<pii> &v, int idx, int spd, int d);

int R, C, M;
int gotcha_size;
Shark board[MAX][MAX];
vector<pii> coord;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    solve();

    return 0;
}

void input()
{
    cin >> R >> C >> M;
    for(int i = 0; i < M; i++)
    {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        board[r][c] = {s, d ,z};
        coord.push_back({r, c});
    }
}

void solve()
{
    if(M == 0) { cout << 0; return ; }

    for(int hunter_pos = 1; hunter_pos <= C; hunter_pos++)
    {
        gotcha(hunter_pos);
        simulate();
    }
    cout << gotcha_size;
}

void gotcha(int c)
{
    for(int i = 1; i <= R; i++)
    {
        if(board[i][c].speed == 0 && board[i][c].direction == 0 && board[i][c].size == 0) continue;
        
        gotcha_size += board[i][c].size;
        board[i][c].speed = 0;
        board[i][c].direction = 0;
        board[i][c].size = 0;

        return ;
    }
}

void simulate()
{
    vector<pii>::iterator iter;
    iter = coord.begin();
    int r = iter->X;
    int c = iter->Y;
    for(iter = coord.begin(); iter != coord.end(); )
    {
        int spd = board[r][c].speed;
        int d = board[r][c].direction;
        int sz = board[r][c].size;

        // 기록된 좌표의 상어 값이 {0, 0, 0}이란 것은 죽었단 것을 의미 by 낚시꾼
        if(spd == 0 && d == 0 && sz == 0)
        {
            iter = coord.erase(iter);
            continue;
        }
        int idx = distance(coord.begin(), iter);
        move(coord, idx, spd, d);

        iter++;
    }
}

// move를 O(N) 미만의 시간으로 구현할 방법이 없을까
// (+) 방향으로 남은 칸의 개수 : R or C - cur
// (-) 방향으로 남은 칸의 개수 : cur - 1
void move(vector<pii> &v, int idx, int spd, int d)
{
    int move_cnt = spd;
    int cur_r = v[idx].X;
    int cur_c = v[idx].Y;
    int r = v[idx].X;
    int c = v[idx].Y;
    bool dir = (d % 3 == 1);  // 1(-) 2(+) 3(+) 4(-) 3의 차이를 갖는다. true : (-), false : (+)

    while(move_cnt == 0)
    {
        int space = 0;  // d 방향으로 이동할 수 있는 칸의 개수
        if(d <= 2)  // UP & DOWN
        {
            if(dir)
            {
                space = cur_r - 1;
                if(move_cnt <= space) break;
                cur_r = 0;
            }
            else
            {
                space = R - cur_r;
                if(move_cnt <= space) break;
                cur_r = R;
            }
        }
        else    // RIGHT & LEFT
        {
            if(dir)
            {
                space = cur_c - 1;
                if(move_cnt <= space) break;
                cur_c = 0;
            }
            else
            {
                space = C - cur_c;
                if(move_cnt <= space) break;
                cur_c = C;
            }
        }
        move_cnt -= space;
        dir = !dir;
    }

    if(d <= 2)  // UP & DOWN
    {
        int n_r = cur_r + ((dir) ? -1 : 1) * move_cnt;
        if(board[n_r][c].speed != 0 || board[n_r][c].direction != 0 || board[n_r][c].size != 0) // 가려고 하는 칸에 다른 상어가 이미 존재했을 때
        {
            if(board[r][c].size > board[n_r][c].size)   // 가려고 하는 칸에 있었던 상어보다 내가 더 클 때
            {
                board[n_r][c].speed = board[r][c].speed;
                board[n_r][c].direction = (dir) ? 1 : 2; 
                board[n_r][c].size = board[r][c].size;

                v[idx].X = n_r;
            }
            else    // 내가 먹힐 때
            {
                coord.erase(coord.begin() + idx);
            }
        }
        else
        {
            board[n_r][c].speed = board[r][c].speed;
            board[n_r][c].direction = (dir) ? 1 : 2; 
            board[n_r][c].size = board[r][c].size;
        }
    }
    else    // RIGHT & LEFT
    {
        int n_c = cur_c + ((dir) ? -1 : 1) * move_cnt;
        if(board[r][n_c].speed != 0 || board[r][n_c].direction != 0 || board[r][n_c].size != 0) // 가려고 하는 칸에 다른 상어가 이미 존재했을 때
        {
            if(board[r][c].size > board[r][n_c].size)   // 가려고 하는 칸에 있었던 상어보다 내가 더 클 때
            {
                board[r][n_c].speed = board[r][c].speed;
                board[r][n_c].direction = (dir) ? 4 : 3; 
                board[r][n_c].size = board[r][c].size;

                v[idx].Y = n_c;
            }
            else    // 내가 먹힐 때
            {
                coord.erase(coord.begin() + idx);
            }
        }
        else
        {
            board[r][n_c].speed = board[r][c].speed;
            board[r][n_c].direction = (dir) ? 4 : 3; 
            board[r][n_c].size = board[r][c].size;    
        }
    }

    // 기존 위치 제거
    board[r][c].speed = 0;
    board[r][c].direction = 0; 
    board[r][c].size = 0;
}