#include <bits/stdc++.h>

using namespace std;

int get_max_dist(int n, int c, vector<int>& ls);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, c;
    vector<int> ls;

    cin >> n >> c;
    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        ls.push_back(tmp);
    }    
    sort(ls.begin(), ls.end());

    int ret = get_max_dist(n, c, ls);
    cout << ret;

    return 0;
}

int get_max_dist(int n, int c, vector<int>& ls)
{
    int l = 1;
    int r = ls[n - 1] - ls[0];
    int ret = 0;

    while(l <= r)
    {
        int mid = (l + r) / 2;
        int cnt = 1;

        int prev = ls[0];
        for(int i = 1; i < n; i++)
        {
            if(ls[i] - prev >= mid)
            {
                cnt++;
                prev = ls[i];
            }
        }
        
        if(cnt >= c)
        {
            ret = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return ret;
}