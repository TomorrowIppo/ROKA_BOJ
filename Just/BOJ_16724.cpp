#include <bits/stdc++.h>
#define MAX 1001

using namespace std;

int n, m;
int cycle_cnt = 0;
char order[MAX][MAX];       // 위치에 따른 이동을 저장
int board[MAX][MAX];          // 위치의 번호 저장
int graph[MAX * MAX];             // 위치의 번호를 바탕으로 그래프 구현
bool vis[MAX * MAX];              // 방문 여부 저장
bool done[MAX * MAX];             // 사이클 끝났는지 판단하는 변수

void makeGraph();           // 조건에 만족하는 그래프 생성
void findCycle(int node);    // cycle 찾기 

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        string tmp;
        cin >> tmp;
        for(int j = 1; j <= m; j++)
        {
            order[i][j] = tmp[j - 1];
        }
    }
    makeGraph();
    
    for(int i = 1; i <= n * m; i++)
    {
        if(vis[i]) continue;
        findCycle(i);
    }
    cout << cycle_cnt;

    return 0;
}

void makeGraph()
{
    int cnt = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            board[i][j] = cnt++;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(order[i][j] == 'U') { graph[board[i][j]] = board[i - 1][j]; }
            if(order[i][j] == 'D') { graph[board[i][j]] = board[i + 1][j]; }
            if(order[i][j] == 'R') { graph[board[i][j]] = board[i][j + 1]; }
            if(order[i][j] == 'L') { graph[board[i][j]] = board[i][j - 1]; }
        }
    }
}

void findCycle(int node)
{
    vis[node] = true;
    int nxt = graph[node];

    if(!vis[nxt]) findCycle(nxt);   // 방문하지 않았다면 그곳으로 dfs
    else if(!done[nxt]) { cycle_cnt++; } // 방문은 했으나, 아직 cycle 탐색을 끝내지 않았다면 탐색 끝내고 cycle 개수 추가
    
    done[node] = true;  // 현 위치의 cycle 탐색 완료

    return ;
}