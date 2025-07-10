#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

struct rock {
	int x, cnt;
};

struct loc {
	int y, x;
};
vector<vector<rock>>wall;
int n, t, flag;

void bfs(int y, int x) {
	queue<loc>q;
	q.push({ y, x });

	while (!q.empty()) {
		loc now = q.front(); q.pop();
		for (int i = -2; i <= 2; i++) {
			if (now.y + i < 0 || now.y + i > t)continue;
			for (int j = 0; j < wall[now.y + i].size(); j++) {
				if (abs(wall[now.y + i][j].x - wall[now.y][now.x].x) > 2)continue;

				int ny = now.y + i;
				int nx = j;

				if (wall[ny][j].cnt != -1)continue;

				if (ny == t) {
					flag = 1;
					cout << wall[now.y][now.x].cnt + 1;
					return;
				}
				else wall[ny][j].cnt = wall[now.y][now.x].cnt + 1;

				q.push({ ny,nx });
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> t;
	wall.resize(t + 1);

	wall[0].push_back({ 0,0 });

	for (int i = 0; i < n; i++) {
		int y, x;
		cin >> x >> y;
		wall[y].push_back({ x,-1 });
	}

	bfs(0, 0);

	if (flag == 0)cout << "-1";
	

	return 0;
}