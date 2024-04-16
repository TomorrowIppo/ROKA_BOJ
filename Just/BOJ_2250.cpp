#include <bits/stdc++.h>
#define MAX 10001

/* 트리의 루트가 1이 아닐 수도 있어요! */

using namespace std;

int n;
int tree[MAX][2];
int cnt = 1;
int pos[MAX];
int parent[MAX];
int max_depth = 0;
vector<int> lv[MAX];

bool cmp(int a, int b) { return pos[a] < pos[b]; }

void inorder(int cur, int depth)
{
    if(depth > max_depth) max_depth = depth;

    int left = tree[cur][0];
    int right = tree[cur][1];

    if(left != -1) inorder(left, depth + 1);
    pos[cur] = cnt++; lv[depth].push_back(cur);
    if(right != -1) inorder(right, depth + 1);
}

pair<int, int> getMaxLength()
{
    int max_lv = 0;
    int max_len = 0;

    for(int i = 1; i <= max_depth; i++)
    {
        sort(lv[i].begin(), lv[i].end(), cmp);

        int tmp = pos[lv[i][lv[i].size() - 1]] - pos[lv[i][0]] + 1;
        //cout << tmp << endl;
        if(max_len < tmp) { max_lv = i; max_len = tmp; }
    }

    return {max_lv, max_len};
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int root, left, right;
        cin >> root >> left >> right;
        tree[root][0] = left; tree[root][1] = right;
        parent[left] = root; parent[right] = root;
    }

    int root = 0;
    for(int i = 1; i <= n; i++)
        if(parent[i] == 0) { root = i; break; }

    inorder(root, 1);
    pair<int, int> res = getMaxLength();
    cout << res.first << ' ' << res.second;

    return 0;
}