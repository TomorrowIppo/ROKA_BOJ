#include <bits/stdc++.h>
#define MAX 200001
#define endl "\n"

using namespace std;

void input();
void topological_sort();

int n, m, k;
int indegree[MAX];
vector<int> adj[MAX];
vector<int> res;
vector<int> default_stuff;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    topological_sort();

    return 0;
}

void input()
{
     // input
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int len, to;
        vector<int> tmp;
        
        cin >> len;
        for(int j = 0; j < len; j++)
        {
            int inp;
            cin >> inp;
            tmp.push_back(inp);
        }
        cin >> to;

        for(auto nxt : tmp)
        {
            adj[nxt].push_back(to);
            indegree[to]++;
        }
    }
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        int inp;
        cin >> inp;
        default_stuff.push_back(inp);
    }
}

void topological_sort()
{
    // 하나의 물약을 만드는 방법이 2개 이상일 수 있다는 반례 때문에
    // 밑의 코드는 사용 불가능. 입력받은 레시피를 하나의 그래프로 합치는 것이 아닌,
    // 레시피별로 각각의 그래프로 분류해서 위상정렬해야할 듯
}

// void topological_sort()
// {
//     queue<int> q;
//     for(auto nxt : default_stuff) 
//     {
//         q.push(nxt);
//         if(indegree[nxt] == 0) res.push_back(nxt);
//     }

//     while(!q.empty())
//     {
//         auto cur = q.front(); q.pop();

//         for(auto nxt : adj[cur])
//         {
//             indegree[nxt]--;

//             if(indegree[nxt] == 0) { q.push(nxt); res.push_back(nxt); }
//         }
//     }

//     for(auto nxt : default_stuff)
//         if(indegree[nxt] != 0) res.push_back(nxt);   

//     sort(res.begin(), res.end());
//     cout << res.size() << endl;
//     for(auto nxt : res) cout << nxt << " ";
// }