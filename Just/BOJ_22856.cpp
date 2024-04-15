#include <bits/stdc++.h>
#define MAX 100001

using namespace std;

int n;
int tree[MAX][2];   // 0 : left, 1 : right
int parent[MAX];
int end_node, res;
bool flag = true;

void similar_inorder(int cur)
{
    //cout << cur << ' ';
    if(tree[cur][0] != -1)
    {
        res++;
        similar_inorder(tree[cur][0]);
        //if(flag) { res++; cout << cur << ' '; }
        if(flag) res++;
    } 
    if(tree[cur][1] != -1)
    {
        res++;
        similar_inorder(tree[cur][1]);
        //if(flag) { res++; cout << cur << ' '; }
        if(flag) res++;
    }
    if(cur == end_node) { flag = false; return ; }
}

void inorder(int cur)
{
    if(tree[cur][0] != -1) inorder(tree[cur][0]);
    end_node = cur;
    if(tree[cur][1] != -1) inorder(tree[cur][1]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    cin >> n;
    for(int i = 1; i <= n; i++) 
    {
        int root, left, right;
        cin >> root >> left >> right;

        tree[root][0] = left; 
        tree[root][1] = right;

        parent[left] = root;
        parent[right] = root;
    }
    
    // solve
    inorder(1); 
    similar_inorder(1);
    //cout << "\nres : " << res;
    cout << res;

    return 0;
}