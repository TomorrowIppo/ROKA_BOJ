#include <bits/stdc++.h>
#define MAX 27

using namespace std;

void dfs1(char node);
void dfs2(char node);
void dfs3(char node);

char tree[MAX][2];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        char p, l, r;
        cin >> p >> l >> r;

        tree[p - 'A'][0] = l;
        tree[p - 'A'][1] = r;
    }
    dfs1('A'); cout << '\n';
    dfs2('A'); cout << '\n';
    dfs3('A'); cout << '\n';

    return 0;
}

void dfs1(char node)
{
    cout << node;
    if(tree[node - 'A'][0] != '.') dfs1(tree[node - 'A'][0]);
    if(tree[node - 'A'][1] != '.') dfs1(tree[node - 'A'][1]);
}

void dfs2(char node)
{
    if(tree[node - 'A'][0] != '.') dfs2(tree[node - 'A'][0]);
    cout << node;
    if(tree[node - 'A'][1] != '.') dfs2(tree[node - 'A'][1]);
}

void dfs3(char node)
{
    if(tree[node - 'A'][0] != '.') dfs3(tree[node - 'A'][0]);
    if(tree[node - 'A'][1] != '.') dfs3(tree[node - 'A'][1]);
    cout << node;
}