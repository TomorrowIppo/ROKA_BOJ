#include <bits/stdc++.h>
#define endl "\n"
#define MAX 3001
#define X first
#define Y second

/*

Union-Find 주의할 점

2,3을 합치고 1,2를 합친 상태에서 
parent 배열의 값이 1,1,2이기 때문,,findParent(3)을 해주어야 1,1,1으로 부모가 갱신됨
계속 갱신되어 있는 상태가 아니라, find 하면서 갱신되기 때문.

즉, 마지막에 parent 배열을 한번 더 갱신해주어야 함

*/

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef struct
{
    int x1;
    int y1;
    int x2;
    int y2;
}Line;

int n;
int parent[MAX];
int parent_cnt[MAX];
Line lines[MAX];

// p1.X == p2.X를 p1.X == p1.Y로 해놓고 맞왜틀 이러고 있었네
bool compare(pii p1, pii p2)
{
    if(p1.X == p2.X) return p1.Y <= p2.Y;
    return p1.X <= p2.X;
}

int ccw(int x1, int y1, int x2, int y2, int x3, int y3)
{
    ll det = (x2 - x1) * (y3 - y1);
    det -= (y2 - y1) * (x3 - x1);

    if(det > 0) return 1;
    else if(det == 0) return 0;
    else return -1;
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

bool is_same_group(int x, int y)
{
    x = find_root(x);
    y = find_root(y);

    return x == y;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        parent[i] = i;

        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        lines[i] = {x1, y1, x2, y2};
    }

    for(int i = 1; i < n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            Line l1 = lines[i];
            Line l2 = lines[j];

            pii p1 = {l1.x1, l1.y1};
            pii p2 = {l1.x2, l1.y2};
            pii p3 = {l2.x1, l2.y1};
            pii p4 = {l2.x2, l2.y2};

            int cmp1 = ccw(p3.X, p3.Y, p1.X, p1.Y, p2.X, p2.Y);
            int cmp2 = ccw(p4.X, p4.Y, p1.X, p1.Y, p2.X, p2.Y);
            int cmp3 = ccw(p1.X, p1.Y, p3.X, p3.Y, p4.X, p4.Y);
            int cmp4 = ccw(p2.X, p2.Y, p3.X, p3.Y, p4.X, p4.Y);

            if(cmp1 * cmp2 <= 0 && cmp3 * cmp4 <= 0)
            {
                if(cmp1 * cmp2 == 0 && cmp3 * cmp4 == 0)    // 두 선이 일직선 상에 있을 때
                {
                    if(compare(p2, p1)) swap(p2, p1);
                    if(compare(p4, p3)) swap(p4, p3);

                    if(compare(p3, p2) && (compare(p1, p4)) || compare(p3, p1) && compare(p2, p4) || compare(p1, p3) && compare(p4, p2))
                    {
                        if(!is_same_group(i, j)) 
                        {
                            // cout << i << "번 (root : " << find_root(i) << ") 과 " << j << "번 (root : " << find_root(j) << ") merge" << endl;
                            merge(i, j);
                        }
                    } 
                }
                else
                {
                    if(!is_same_group(i, j)) 
                    {
                        // cout << i << "번 (root : " << find_root(i) << ") 과 " << j << "번 (root : " << find_root(j) << ") merge" << endl;
                        merge(i, j); 
                    }
                }
            }
        }
    }
    // cout << endl;
    // for(int i = 1; i <= n; i++) cout << i << "번 부모 : " << parent[i] << endl;

    for(int i = 1; i <= n; i++) parent_cnt[find_root(i)]++;
    int group_cnt = 0;
    int _max = 0;
    for(int i = 1; i <= n; i++)
    {
        if(parent_cnt[i]) group_cnt++;
        _max = max(_max, parent_cnt[i]);
    }

    cout << group_cnt << endl;
    cout << _max << endl;

    return 0;
}