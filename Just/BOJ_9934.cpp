#include <bits/stdc++.h>

using namespace std;

void dfs(int depth, int start, int end);

int input[1024];
int k;
vector<int> level[10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> k;
	
	int num;
	int idx = 0;
	while (cin >> num) {
		input[idx++] = num;
	}
	dfs(0,0, idx);
	for (int i = 0; i < k; i++) {
		for (auto nxt : level[i]) {
			cout << nxt << ' ';
		}
		cout << '\n';
	}
	return 0;
}

void dfs(int depth, int start, int end) {
	
	if (start >= end) {
		return;
	}
	int mid = (start + end) / 2;
	level[depth].push_back(input[mid]);
	dfs(depth + 1, start, mid);
	dfs(depth + 1, mid+1, end);

}