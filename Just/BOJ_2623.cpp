#include <bits/stdc++.h>
#define MAX 1001

using namespace std;

void makeGraph();
void topologicalSort();

int n, m;
vector<int> graph[MAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++)
        makeGraph();

    return 0;
}

void makeGraph()
{

}

void topologicalSort()
{

}