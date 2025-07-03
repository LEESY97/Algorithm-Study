#include <iostream>

using namespace std;

int num[3] = { 1,2,3 };
int cnt;

void func(int now,int target) {
	if (now == target) {
		cnt++;
		return;
	}

	for (int i = 0; i < 3; i++) {
		if (now + num[i] > target)continue;
		func(now + num[i], target);
	}
}

int main() {

	int T;
	int n;

	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> n;
		cnt = 0;
		func(0, n);
		cout << cnt << "\n";
	}

	return 0;
}