#include <bits/stdc++.h>
#define MAX 1001

using namespace std;

typedef struct
{
    int strahler;
    int cnt;
}dataSet;

int getStrahler();
void resetParams();
bool comp(dataSet d1, dataSet d2)
{
    return d1.strahler > d2.strahler;   // strahler 내림차순 정렬
}

int t, k, m, p;
int indegree[MAX];
int strahler[MAX];
vector<int> graph[MAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> k >> m >> p;
        for(int i = 0; i < p; i++)
        {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            indegree[v]++;
        }

        int ans = getStrahler();
        resetParams();

        cout << k << ' ' << ans << '\n';
    }

    return 0;
}

int getStrahler()
{
    int ret = 0;
    queue<int> q;
    vector<dataSet> flow[MAX]; // x번 노드에 strahler가 y인 것의 개수
    for(int i = 1; i <= m; i++)
        if(indegree[i] == 0) { q.push(i); strahler[i] = 1; }
    
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        
        for(auto nxt : graph[cur])
        {
            indegree[nxt]--;

            if(flow[nxt].size() == 0) flow[nxt].push_back({strahler[cur], 1});
            else
            {
                bool flag = false;
                int idx = 0;
                for(auto s : flow[nxt]) // nxt 노드에 거쳐갔던 strahler 중 중복된게 있는지 탐색
                {
                    if(s.strahler == strahler[cur]) { flag = true; flow[nxt][idx].cnt++; break; }   // 있으면 횟수 추가
                    idx++;
                }

                // 없으면 push_back
                if(!flag) flow[nxt].push_back({strahler[cur], 1});
            }

            if(indegree[nxt] == 0) 
            {
                q.push(nxt);
                sort(flow[nxt].begin(), flow[nxt].end(), comp);

                // 가장 큰 것의 개수가 1개일 때
                if(flow[nxt][0].cnt == 1) { strahler[nxt] = flow[nxt][0].strahler; }
                // 가장 큰 것의 개수가 2개 이상일 때
                else { strahler[nxt] = flow[nxt][0].strahler + 1; }
            }
        }
    }
    ret = strahler[m];

    return ret;
}

void resetParams()
{
    for(int i = 1; i <= m; i++) { graph[i].clear(); indegree[i] = 0; strahler[i] = 0; }
}