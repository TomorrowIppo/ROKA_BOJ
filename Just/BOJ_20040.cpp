#include <bits/stdc++.h>
#define MAX 500001

using namespace std;

// 두 노드의 root를 확인하는데, 둘이 같으면 cycle 발생한 것

int find_root(int x);
bool check_cycle(int x, int y);

int parent[MAX];
int n, m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) parent[i] = i;

    for(int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        if(check_cycle(u, v)) { cout << i; return 0; }
    }
    cout << 0;

    return 0;
}

int find_root(int x)
{
    // x가 root이면 그대로 반환
    if(x == parent[x]) return x;
    // x가 자식일 경우 부모 노드에 대해 재귀
    return find_root(parent[x]);
}

bool check_cycle(int x, int y)
{
    // 둘이 같은 집합인지 판단
    x = find_root(x);
    y = find_root(y);
    if(x == y) return true;
    else { 
        if(x > y) parent[x] = y;
        else parent[y] = x;
        return false; 
    }
}