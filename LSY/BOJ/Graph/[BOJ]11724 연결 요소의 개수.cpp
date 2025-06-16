#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>

using namespace std;

int N, M;
vector<int> arr[1001];
int visited[1001];
queue<int> q;

void sol(int st) {
	q.push(st);
	
	while (!q.empty()) {
		int now = q.front(); q.pop();

		for (int i = 0;i < arr[now].size();i++) {
			if (visited[arr[now][i]] == 1) continue;
			visited[arr[now][i]] = 1;
			q.push(arr[now][i]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	
	cin >> N >> M;

	int a, b;
	for (int i = 0;i < M;i++) {
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	int result = 0;
	for (int i = 1;i <= N;i++) {
		if (visited[i] == 1) continue;
		sol(i);
		result++;
	}

	cout << result;

	return 0;
}
