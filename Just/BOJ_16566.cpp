#include <bits/stdc++.h>
#define MAX 4000001

using namespace std;

int N, M, K;
int parent[MAX];
vector<int> my_deck;

int find_root(int x)
{
    if(x == parent[x]) return x;
    return parent[x] = find_root(parent[x]);
}

void merge(int x, int y)
{
    x = find_root(x);
    y = find_root(y);

    // 큰 값을 부모로
    if(x < y) parent[x] =  y;
    else parent[y] = x;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    my_deck.push_back(0);

    parent[0] = 0;
    for(int i = 1; i <= M; i++)
    {
        int inp;
        cin >> inp;
        my_deck.push_back(inp);
        parent[i] = i;
    }
    sort(my_deck.begin(), my_deck.end());
    
    for(int i = 1; i <= K; i++)
    {
        int inp;
        cin >> inp;
        
        int idx = lower_bound(my_deck.begin(), my_deck.end(), inp + 1) - my_deck.begin();
        idx = find_root(idx);
        cout << my_deck[parent[idx]] << '\n';
        merge(idx, idx + 1);
    }

    return 0;
}