#include <iostream>

using namespace std;

int cnt = 9999999999;

void func(int n, int time) {
	if (n == 1) {
		if (time < cnt)cnt = time;
		return;
	}

	for (int i = 0; i < 3; i++) {
		if (time >= cnt)return;
		if (i == 0 && n % 3 == 0)func(n / 3, time + 1);
		else if (i == 1 && n % 2 == 0)func(n / 2, time + 1);
		else if (i == 2)func(n - 1, time + 1);
	}
}

int main() {

	int n;
	cin >> n;
	func(n, 0);

	cout << cnt;

	return 0;
}