#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int N;
bool gr[101][101];

void sol(int now) {
	queue<int> q;
	bool visited[101] = { 0 };

	q.push(now);

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int i = 1; i <= N; i++) {
			if (gr[cur][i] == 0 || visited[i] == 1) continue;
			visited[i] = 1;
			q.push(i);
			gr[now][i] = 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> gr[y][x];
		}
	}

	for (int i = 1; i <= N; i++) {
		sol(i);
	}

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cout << gr[y][x] << ' ';
		}
		cout << "\n";
	}

	return 0;
}
