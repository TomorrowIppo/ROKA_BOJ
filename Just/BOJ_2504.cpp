#include <bits/stdc++.h>

using namespace std;

// 분배법칙 이용해서 푸는 것이 아이디어였던 문제. 깨닫는데 시간이 좀 걸렸다.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str = "";
    stack<char> s;
    int ans = 0;
    int tmp = 1;

    cin >> str;
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '(')
        {
            s.push('(');
            tmp *= 2;
        }
        else if(str[i] == ')')
        {
            if(s.empty() || s.top() != '(') // 조건에 부합하지 않는 경우, 0 출력 후 종료
            {
                cout << 0;
                return 0;
            }
            else if(str[i - 1] == '(')
            {
                ans += tmp;
                tmp /= 2;
                s.pop();
            }
            else
            {
                tmp /= 2;
                s.pop();
            }
        }

        if(str[i] == '[')
        {
            s.push('[');
            tmp *= 3;
        }
        else if(str[i] == ']')
        {
            if(s.empty() || s.top() != '[') // 조건에 부합하지 않는 경우, 0 출력 후 종료
            {
                cout << 0;
                return 0;
            }
            else if(str[i - 1] == '[')
            {
                ans += tmp;
                tmp /= 3;
                s.pop();
            }
            else
            {
                tmp /= 3;
                s.pop();
            }
        }
    }
    if(!s.empty()) cout << 0;    // 올바르지 못한 배열
    else cout << ans;

    return 0;
}