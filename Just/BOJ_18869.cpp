#include <bits/stdc++.h>
#define MAX_M 101

using namespace std;

/*

좌표 압축이란 ? 모든 구간이 아니라 중요한 구간(숫자)만 들고 있는 기법
" 값보다 값의 순위가 더 중요할 때 " 사용한다.
값을 다루기 편한 임의의 값으로 변경하되 순위는 유지해야 한다.

*/

int n, m;
vector<int> ls[MAX_M];

void compress(vector<int>& vec)
{
    vector<int> tmp(vec.size());
    copy(vec.begin(), vec.end(), tmp.begin());
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    
    for(int i = 0; i < n; i++)
        vec[i] = lower_bound(tmp.begin(), tmp.end(), vec[i]) - tmp.begin();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int inp; cin >> inp;
            ls[i].push_back(inp);
        }
        compress(ls[i]);
    }

    int ans = 0;
    for(int i = 0; i < m - 1; i++)
    {
        for(int j = i + 1; j < m; j++)
        {   
            if(ls[i].size() != ls[j].size()) continue;
            
            bool flag = true;
            for(int k = 0; k < ls[i].size(); k++)
                if(ls[i][k] != ls[j][k]) { flag = false; break; }
            
            if(flag) ans++;
        }
    }
    cout << ans;

    return 0;
}