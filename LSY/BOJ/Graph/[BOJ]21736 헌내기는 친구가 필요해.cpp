#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>

using namespace std;

int N, M;
char map[601][601];
int visited[601][601];
pair<int, int> st;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int in_range(int y, int x) {
	return y >= 0 && y < N && x >= 0 && x < M;
}

int sol() {
	int result = 0;
	queue<pair<int, int>> q;
	q.push(st);
	visited[st.first][st.second] = 1;

	while (!q.empty()) {
		pair<int, int>cur = q.front();q.pop();

		for (int i = 0;i < 4;i++) {
			int ny = cur.first + dy[i];
			int nx = cur.second + dx[i];
			if (!in_range(ny, nx) || visited[ny][nx] == 1 || map[ny][nx] == 'X') continue;
			q.push({ ny,nx });
			visited[ny][nx] = 1;
			if (map[ny][nx] == 'P') result++;
		}
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	string sen;
	for (int i = 0;i < N;i++) {
		cin >> sen;
		for (int j = 0;j < M;j++) {
			map[i][j] = sen[j];
			if (sen[j] == 'I') {
				st.first = i;
				st.second = j;
			}
		}
	}

	int ret = sol();

	if (ret == 0) {
		cout << "TT";
	}
	else {
		cout << ret;
	}

	return 0;
}
