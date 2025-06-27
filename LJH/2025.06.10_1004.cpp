#include <iostream>
#include <cmath>

using namespace std;

int main() {

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int n;
		cin >> n;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			int cx, cy, r;
			cin >> cx >> cy >> r;
			if (((x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy)) <= r * r && ((x2 - cx) * (x2 - cx) + (y2 - cy) * (y2 - cy)) > r * r) cnt++;
			if (((x2 - cx) * (x2 - cx) + (y2 - cy) * (y2 - cy)) <= r * r && ((x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy)) > r * r) cnt++;
		}
		cout << cnt << "\n";
	}

	return 0;
}