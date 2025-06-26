#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

int N,M;
int map[1001][1001];
int visited[1001][1001];
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };
pair<int, int>st;

int in_range(int y, int x) {
	return y >= 0 && y < N&&x >= 0 && x < M;
}

void sol() {
	queue<pair<int, int>>q;
	q.push(st);
	visited[st.first][st.second] = 1;

	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cur.first + dy[i];
			int nx = cur.second + dx[i];

			if (!in_range(ny, nx) || visited[ny][nx] != 0 || map[ny][nx] != 1) continue;

			q.push({ ny,nx });
			visited[ny][nx] = visited[cur.first][cur.second] + 1;

		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	cin >> N >> M;

	int a;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> a;
			map[i][j] = a;
			if (a == 2) {
				st.first = i;
				st.second = j;
			}
		}
	}

	sol();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				cout << 0 << " ";
			}
			else {
				if (visited[i][j] == 0) cout << -1 << " ";
				else cout << visited[i][j] - 1 << " ";
			}
		}
		cout << "\n";
	}
	
	return 0;
}
