#include <bits/stdc++.h>
#define MAX 10001
#define endl "\n"

/* 

구현보다 double to long long에서 맞왜틀을 많이 외쳤던 문제.
https://oculis.tistory.com/59
여기에서 내 맞왜틀을 해결할 수 있었다.

해답은 (long long)(x * 100 + 0.5)였는데,
9.99를 100 곱하면 놀랍게도 99'8'.999로 오차가 발생하는데
여기에 0.5를 더해준 뒤 형변환 해버리면 999만 남게 된다.
이에 대한 정보를 모른 상태로 풀었기 때문에 맞왜틀을 외쳤던 것 같다.

부동소수점 데이터형에서 다른 데이터로 형변환할 때 생길 수 있는 오차에 대해서
알아둘 필요가 있겠다고 느꼈다.

*/

using namespace std;

typedef long long ll;
typedef struct
{
    ll x1;
    ll y1;
    ll x2;
    ll y2;
}Line;

int n;
int parent[MAX];
int group_cnt[MAX];
vector<Line> Lines;

int ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
    ll det = (x2 - x3) * (y1 - y2);
    det -= (x1 - x2) * (y2 - y3);

    if(det > 0) return 1;
    else if(det == 0) return 0;
    else return -1;
}

bool cmp(ll x1, ll y1, ll x2, ll y2)
{
    if(x1 == x2) return y1 <= y2;
    else return x1 <= x2;
}

int find_root(int x)
{
    if(x == parent[x]) return x;
    return parent[x] = find_root(parent[x]);
}

void merge(int x, int y)
{
    x = find_root(x);
    y = find_root(y);

    if(x > y) parent[x] = y;
    else parent[y] = x;
}

bool is_Union(int x, int y)
{
    x = find_root(x);
    y = find_root(y);

    return x == y;
}

void input()
{
    // input & init
    cin >> n;
    Lines.push_back({0, 0, 0, 0});
    for(int i = 1; i <= n; i++)
    {
        parent[i] = i;
        double x1, y1, x2, y2;

        cin >> x1 >> y1 >> x2 >> y2;
        Lines.push_back({(ll)(x1 * 100 + 0.5), (ll)(y1 * 100 + 0.5), (ll)(x2 * 100 + 0.5), (ll)(y2 * 100 + 0.5)});
    }
}

void solve()
{
    ll x1, y1, x2, y2, x3, y3, x4, y4;
    
    for(int i = 1; i < n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            x1 = Lines[i].x1; y1 = Lines[i].y1; x2 = Lines[i].x2; y2 = Lines[i].y2;
            x3 = Lines[j].x1; y3 = Lines[j].y1; x4 = Lines[j].x2; y4 = Lines[j].y2;
            
            int cmp1 = ccw(x3, y3, x1, y1, x2, y2);
            int cmp2 = ccw(x4, y4, x1, y1, x2, y2);
            int cmp3 = ccw(x1, y1, x3, y3, x4, y4); 
            int cmp4 = ccw(x2, y2, x3, y3, x4, y4);
            
            if(cmp1 == 0 && cmp2 == 0 && cmp3 == 0 && cmp4 == 0)
            {
                // 원점에 더 가까운 점을 x1, y1 | x3, y3로 설정
                if(cmp(x2, y2, x1, y1)) 
                {
                    swap(x1, x2);
                    swap(y1, y2);
                }
                if(cmp(x4, y4, x3, y3))
                {
                    swap(x3, x4);
                    swap(y3, y4);
                }

                // 두 직선이 일직선 상에 있으며, 교차하는 경우
                if((cmp(x1, y1, x4, y4) && cmp(x3, y3, x2, y2)) || (cmp(x1, y1, x3, y3) && cmp(x4, y4, x2, y2)) || (cmp(x3, y3, x1, y1) && cmp(x2, y2, x4, y4)))           
                {
                    if(is_Union(i, j)) continue;

                    merge(i, j);
                    //cout << i << ' ' << j << " merge" << endl;
                }
            }
        }
    }
    for(int i = 1; i <= n; i++) group_cnt[find_root(i)]++;
    
    int cnt = 0;
    for(int i = 1; i <= n; i++)
        if(group_cnt[i]) cnt++;

    cout << cnt << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    solve();

    return 0;
}