#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct cor {
	int y, x;
};

int result = 21e8;
vector<cor> house;
vector<cor> chicken;
vector<int> pick;
int visited[13];

void func(int m, int now) {
	if (now == m) {
		int sum = 0;
		for (int i = 0; i < house.size(); i++) {
			int min = 1000000;
			for (int j = 0; j < m; j++) {
				int dis = abs(chicken[pick[j]].y - house[i].y) + abs(chicken[pick[j]].x - house[i].x);
				if (dis < min)min = dis;
			}
			sum += min;
		}
		if (sum < result) {
			result = sum;
		}
		return;
	}

	for (int i = 0; i < chicken.size(); i++) {
		if (visited[i] == 1)continue;
		if (now > 0 && i < pick[now - 1])continue;
		pick[now] = i;
		visited[i] = 1;
		func(m, now + 1);
		visited[i] = 0;
		pick[now] = -1;
	}
}

int main() {

	int n, m;
	cin >> n >> m;
	vector<vector<int>>map(n, vector<int>(n, 0));
	pick.resize(m, -1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) house.push_back({ i,j });
			else if (map[i][j] == 2) chicken.push_back({ i,j });
		}
	}
	
	func(m, 0);

	cout << result;

	return 0;
}