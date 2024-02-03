#include <bits/stdc++.h>
#define MAX 101
#define X first
#define Y second

using namespace std;

/*

기본적으로 맥주 20병을 지니고 시작.
맥주 1병당 50m 이동 가능 => 처음에는 1000m까지 이동 가능

*/
bool vis[MAX];

int getDist(pair<int, int> p1, pair<int, int> p2)
{
    return (abs(p1.X - p2.X) + abs(p1.Y - p2.Y));
}

void resetVis(int n)
{
    for(int i = 0; i < n; i++) vis[i] = false;
}

bool bfs(pair<int, int>& house, pair<int, int>(&conv)[MAX], pair<int, int>& festival, int n);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, t;
    cin >> t;
    while(t--)
    {
        // 입력
        cin >> n;

        pair<int, int> house;
        pair<int, int> conv[MAX];
        pair<int, int> festival;

        cin >> house.X >> house.Y;
        for(int i = 0; i < n; i++) { cin >> conv[i].X >> conv[i].Y; }
        cin >> festival.X >> festival.Y;

        // 로직
        if(bfs(house, conv, festival, n)) cout << "happy\n";
        else cout << "sad\n";

        resetVis(n);
    }

    return 0;
}

bool bfs(pair<int, int>& house, pair<int, int>(&conv)[MAX], pair<int, int>& festival, int n)
{
    queue<pair<int, int>> q;
    q.push(house);

    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        if(getDist(festival, cur) <= 1000) { return true; } // 현 위치에서 페스티벌과의 거리가 1000 이하면 종료

        for(int i = 0; i < n; i++)
        {
            if(vis[i]) continue;

            if(getDist(conv[i], cur) <= 1000)
            {
                q.push(conv[i]);
                vis[i] = true;
            }
        }
    }

    return false;
}