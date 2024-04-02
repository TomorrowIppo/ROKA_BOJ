#include <bits/stdc++.h>
#define MAX 101

using namespace std;

typedef struct 
{
    int id;
    int R;
    int C;
    int speed;
    int direction;  // d) 1 up | 2 down | 3 right | 4 left
    int size;
}Shark_Info;

void input();
void solve();
void gotcha(int c);
void move();
void killing();
bool cmp(int a, int b);
bool check();
void printShark();

int R, C, M;
int gotcha_size;
vector<int> MAP[MAX][MAX];
vector<Shark_Info> Shark;

int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};

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
        Shark.push_back({i, r, c, s, d, z});
        MAP[r][c].push_back(i);
    }
}

void solve()
{
    if(M == 0) { cout << 0; return ; }

    for(int hunter_pos = 1; hunter_pos <= C; hunter_pos++)
    {
        if(check()) break;
        //cout << "hunter_pos : " << hunter_pos << endl;
        //printShark();
        gotcha(hunter_pos);
        move();
        killing();
        //cout << endl;
        //printShark();
    }
    cout << gotcha_size;
}

void gotcha(int c)
{
    for(int i = 1; i <= R; i++)
    {
        if(MAP[i][c].size() == 0) continue;
        gotcha_size += Shark[MAP[i][c][0]].size;
        Shark[MAP[i][c][0]].size = 0;
        MAP[i][c].clear();
        return ;
    }
}

void move()
{
    for(int i = 0; i < Shark.size(); i++)
    {
        if(Shark[i].size == 0) continue;    // 죽은 놈 컷
        MAP[Shark[i].R][Shark[i].C].clear();
    }

    for(int i = 0; i < Shark.size(); i++)
    {
        if(Shark[i].size == 0) continue;    // 죽은 놈 컷
        int r = Shark[i].R;
        int c = Shark[i].C;
        int dir = Shark[i].direction;
        int spd = Shark[i].speed;

        if(dir <= 2)
        {
            int rotate = (R - 1) * 2;
            if (spd >= rotate) spd = spd % rotate;

            for(int j = 0; j < spd; j++)
            {
                int nr = r + dx[dir];
                int nc = c + dy[dir];
                
                if(nr < 1) { dir = 2; nr += 2; }
                if(nr > R) { dir = 1; nr -= 2; }

                r = nr;
                c = nc;
            }
        }
        else
        {
            int rotate = (C - 1) * 2;
            if (spd >= rotate) spd = spd % rotate;

            for(int j = 0; j < spd; j++)
            {
                int nr = r + dx[dir];
                int nc = c + dy[dir];

                if(nc < 1) { dir = 3; nc += 2; }
                if(nc > C) { dir = 4; nc -= 2; }

                r = nr;
                c = nc;
            }
        }
        Shark[i].R = r;
        Shark[i].C = c;
        Shark[i].direction = dir;
        MAP[r][c].push_back(i);
    }
}

void killing()
{
    for(int i = 1; i <= R; i++)
    {
        for(int j = 1; j <= C; j++)
        {
            if(MAP[i][j].size() > 1)
            {
                sort(MAP[i][j].begin(), MAP[i][j].end(), cmp);
                int survive_idx = MAP[i][j][0];

                for(int k = 1; j < MAP[i][j].size(); k++)
                {
                    Shark[MAP[i][j][k]].size = 0;
                    Shark[MAP[i][j][k]].R = 0;
                    Shark[MAP[i][j][k]].C = 0;
                }

                MAP[i][j].clear();
                MAP[i][j].push_back(Shark[survive_idx].id);
            }
        }
    }
}

bool cmp(int a, int b)
{
    if(Shark[a].size > Shark[b].size) return true;
    return false;
}

bool check()
{
    for(int i = 0; i < Shark.size(); i++)
        if(Shark[i].size != 0) return false;
    return true;
}

void printShark()
{
    for(int i = 1; i <= R; i++)
    {
        for(int j = 1; j <= C; j++)
        {
            if(MAP[i][j].size() == 0) cout << "0 ";
            else cout << "S ";
        }
        cout << endl;
    }
}