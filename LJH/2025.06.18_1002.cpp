#include <iostream>
#include <cmath>

using namespace std;

int main() {

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {

		int result = -1;
		double x1, y1, x2, y2, r1, r2, max, min;

		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		if (r1 > r2)max = r1, min = r2;
		else max = r2, min = r1;
		double dis = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

		if (x1 == x2 && y1 == y2 && r1 == r2)result = -1;
		else if (dis > max && dis == r1 + r2)result = 1;
		else if (dis < max && dis + min == max)result = 1;
		else if (dis < max && dis + min < max)result = 0;
		else if (r1 + r2 < dis)result = 0;
		else result = 2;

		cout << result << "\n";
	}

	return 0;
}