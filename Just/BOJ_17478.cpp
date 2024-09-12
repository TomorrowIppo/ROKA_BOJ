#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

string txt1 = "\"재귀함수가 뭔가요?\"";
string txt2_1 = "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.";
string txt2_2 = "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.";
string txt2_3 = "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"";
string txt3 = "\"재귀함수는 자기 자신을 호출하는 함수라네\"";
string txt4 = "라고 답변하였지.";

void print_(int m)
{
    for(int i = 0; i < m; i++) cout << "____";
}

void func(int n, int m)
{
    print_(m);
    cout << txt1 << endl;

    if(n == 0)
    {
        print_(m);
        cout << txt3 << endl;
    }
    else
    {
        print_(m);
        cout << txt2_1 << endl;
        print_(m);
        cout << txt2_2 << endl;
        print_(m);
        cout << txt2_3 << endl;
        func(n - 1, m + 1);
    }
    print_(m);
    cout << txt4 << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << endl;
    func(n, 0);

    return 0;
}