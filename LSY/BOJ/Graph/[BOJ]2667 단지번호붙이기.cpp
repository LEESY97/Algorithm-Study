#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>

using namespace std;

int map[26][26];
int visited[26][26];
int N;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int in_range(int ny,int nx) {
	return ny >= 0 && ny < N && nx >= 0 && nx < N;
}

int sol(int y,int x) {
	int cnt=0;

	queue<pair<int,int>> q;
	q.push({ y,x });
	visited[y][x] = 1;
	cnt++;

	while (!q.empty()) {
		pair<int, int> cur = q.front();q.pop();
		for (int i = 0;i < 4;i++) {
			int ny = cur.first + dy[i];
			int nx = cur.second + dx[i];

			if (!in_range(ny,nx)||(map[ny][nx] == 0) || (visited[ny][nx] != 0)) continue;
			q.push({ ny,nx });
			visited[ny][nx] = 1;
			cnt++;
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	cin >> N;
	
	string input;
	for (int i = 0;i < N;i++) {
		cin >> input;
		for (int j = 0;j < N;j++) {
			map[i][j] = input[j] - '0';
		}
	}

	vector<int> result;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (visited[i][j] != 0 || map[i][j] == 0) continue;
			int ret = sol(i,j);
			result.push_back(ret);
		}
	}
	
	sort(result.begin(), result.end());

	int num = result.size();
	cout << num << "\n";
	for (int i = 0;i < num;i++) {
		cout << result[i] << "\n";
	}


	return 0;
}
