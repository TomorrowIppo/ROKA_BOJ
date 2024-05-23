#include <bits/stdc++.h>
#define MAX 1000001

using namespace std;

int n;
int origin_arr[MAX];
int shuffle_arr[MAX];
int start_idx;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> origin_arr[i];
    for(int i = 0; i < n; i++)
    {
        cin >> shuffle_arr[i];
        if(shuffle_arr[i] == origin_arr[0]) start_idx = i;
    }

    for(int i = 1; i < n; i++)
    {
        int r_idx = (start_idx == n - 1) ? 0 : start_idx + 1;
        int l_idx = (start_idx == 0) ? n - 1 : start_idx - 1;

        if(shuffle_arr[r_idx] != origin_arr[i] && shuffle_arr[l_idx] != origin_arr[i])
        {
            cout << "bad puzzle";
            return 0;
        }
        else
        {
            if(shuffle_arr[r_idx] == origin_arr[i]) start_idx = r_idx;
            else if(shuffle_arr[l_idx] == origin_arr[i]) start_idx = l_idx;
        }
    }
    cout << "good puzzle";

    return 0;
}