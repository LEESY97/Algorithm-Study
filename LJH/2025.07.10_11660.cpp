#include <iostream>
#include <vector>

using namespace std;

int sum(const vector<vector<int>> &map, int y1, int y2, int x1, int x2) {
	int num = 0;
	for (int i = y1; i <= y2; i++) {
		num += (map[i][x2] - map[i][x1 - 1]);
	}
	return num;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, M;
	cin >> n >> M;
	vector<vector<int>> map(n + 1, vector<int>(n + 1, 0));
	int num = 0;
	for (int i = 1; i <= n; i++) {
		map[i][0] = num;
		for (int j = 1; j <= n; j++) {
			int temp;
			cin >> temp;
			num += temp;
			map[i][j] = num;
		}
	}
	for (int m = 0; m < M; m++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int result = sum(map, x1, x2, y1, y2);
		cout << result << "\n";
	}
	
	return 0;
}