#include <iostream>
#include <vector>

using namespace std;

int w, b;

void check(const vector<vector<int>> &map, int len, int y, int x) {
	int sum = 0;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			sum += map[y + i][x + j];
		}
	}
	if (sum == 0)w++;
	else if (sum == len * len)b++;
	else {
		if (len / 2 == 1) {
			b += sum;
			w += (4 - sum);
		}
		else {
			for (int i = y; i < y + len; i += len / 2) {
				for (int j = x; j < x + len; j += len / 2) {
					check(map, len / 2, i, j);
				}
			}
		}
	}
}

int main() {

	int n;
	cin >> n;
	vector<vector<int>> map(n, vector<int>(n));
	int first = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (first == 0 && i > 0 && j > 0 && map[0][0] != map[i][j])first = 1;
		}
	}
	if (first == 1) {
		check(map, n / 2, 0, 0);
		check(map, n / 2, n / 2, 0);
		check(map, n / 2, 0, n / 2);
		check(map, n / 2, n / 2, n / 2);
		cout << w << "\n" << b;
	}
	else if (first == 0) {
		if (map[0][0] == 0)cout << "1\n" << "0";
		else cout << "0\n" << "1";
	}

	return 0;
}