#include <iostream>
#include <vector>

using namespace std;

struct bae {
	int type = 0;
	int parent;
};

int n, m, k;
int dy[] = {1,-1,0,0};
int dx[] = { 0,0,1,-1 };
bae map[50][50];

int find(int y, int x) {
	if (map[y][x].parent == (y * m + x))return (y * m + x);
	return map[y][x].parent = find((map[y][x].parent / m), (map[y][x].parent % m));
}

void Union(int x1, int y1, int x2, int y2) {
	int roota = find(x1, y1);
	int rootb = find(x2, y2);

	if (roota == rootb)return;
	if (roota < rootb) {
		map[rootb / m][rootb % m].parent = roota;
	}
	else {
		map[roota / m][roota % m].parent = rootb;
	}
}

int main() {

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n >> m >> k;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				map[i][j].parent = i * m + j;
				map[i][j].type = 0;
			}
		}
		int f = 0;
		for (int i = 0; i < k; i++) {
			int y, x;
			cin >> y >> x;
			map[y][x].type = 1;
			for (int j = 0; j < 4; j++) {
				if (x + dx[j] >= 0 && x + dx[j] < m && y + dy[j] >= 0 && y + dy[j] < n && map[y + dy[j]][x + dx[j]].type == 1 && find(y, x) != find(y + dy[j], x + dx[j]))Union(y, x, y + dy[j], x + dx[j]);
			}
		}
		int cnt = 0;
		int dat[2500] = { 0 };
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j].type == 1) dat[find(i, j)] = 1;
			}
		}
		for (int i = 0; i < n * m; i++)if (dat[i] == 1)cnt++;
		
		cout << cnt << "\n";
	}

	return 0;
}