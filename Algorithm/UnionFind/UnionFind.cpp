// https://sangwoo0727.github.io/algorithm/Algorithm-UnionFind/

#include <bits/stdc++.h>

using namespace std;

int parent[100];

int find_root(int x)
{
    // x가 root이면 그대로 반환
    if(x == parent[x]) return x;
    // x가 자식일 경우 부모 노드에 대해 재귀
    return parent[x] = find_root(parent[x]);    // 경로 압축 O(n) -> O(α(n)), 사실상 상수 시간 복잡도
}

void union_root(int x, int y)
{
    // x, y 정점의 최상위 정점을 각각 찾는다. 속한 트리의 루트 노드 찾기
    x = find_root(x);
    y = find_root(y);

    // 서로 다른 트리에 속한다면, 루트 번호가 큰 쪽이 작은 쪽으로 붙도록 설정한다. (반대도 상관없음)
    // 이렇게 설정하지 않으면 시간초과 날 확률 Up
    if(x != y)
    {
        if(x > y) parent[x] = y;
        else parent[y] = x;
    }
}

bool isUnion(int x, int y)
{
    // 둘이 같은 집합인지 판단
    x = find_root(x);
    y = find_root(y);
    if(x == y) return true;
    else return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 1; i <= 10; i++) parent[i] = i;

    union_root(1, 2);
    union_root(2, 3);
    union_root(3, 4);
    union_root(5, 6);
    union_root(6, 7);
    union_root(7, 8);

    // 1과 5는 연결되어있지 않지만, 1과 6을 연결해도 6과 5는 같은 집합이기에, 같이 연결된다.
    cout << "1과 5는 연결 되어 있나 ? : " << (isUnion(1, 5) ? "True" : "False") << '\n';
    union_root(1, 6);
    cout << "1과 5는 연결 되어 있나 ? : " << (isUnion(1, 5) ? "True" : "False") << '\n';

    return 0;
}