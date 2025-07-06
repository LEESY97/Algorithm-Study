#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;
int visited[101];
vector<vector<int>> com;

void dfs(int now) {
	for (int i = 0; i < com[now].size(); i++) {
		if (visited[com[now][i]] == 1)continue;
		visited[com[now][i]] = 1;
		cnt++;
		dfs(com[now][i]);
	}
}

int main() {

	int n;
	int pair;

	cin >> n >> pair;
	com.resize(n + 1, vector<int>());
	for (int i = 0; i < pair; i++) {
		int from, to;
		cin >> from >> to;
		com[from].push_back(to);
		com[to].push_back(from);
	}
	visited[1] = 1;
	dfs(1);

	cout << cnt;

	return 0;
}