#include <iostream>
#include <vector>

using namespace std;

int main() {

	int n, m, b;
	cin >> n >> m >> b;
	vector<vector<int>>map(n, vector<int>(m));
	int min = 257, max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] > max)max = map[i][j];
			else if (map[i][j] < min)min = map[i][j];
		}
	}
	int h = max;
	int time = 21e7;
	for (int x = max; x >= min; x--) {
		int dig = 0, stack = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (x - map[i][j] < 0)dig += abs(x - map[i][j]);
				else if (x - map[i][j] > 0)stack += x - map[i][j];
			}
		}
		if (stack > b + dig)continue;
		else {
			if (stack + (dig * 2) < time) {
				time = stack + (dig * 2);
				h = x;
			}
		}
	}
	cout << time << " " << h;

	return 0;
}