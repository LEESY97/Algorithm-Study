#include <iostream>

using namespace std;

int n, m, maxx;
int card[100], used[100];

void func(int now, int sum) {
	if (now == 3) {
		if (sum > maxx)maxx = sum;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (used[i] == 1)continue;
		if (sum + card[i] > m)continue;
		used[i] = 1;
		func(now + 1, sum + card[i]);
		used[i] = 0;
	}
}

int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}
	int sum = 0;
	func(0, sum);

	cout << maxx;

	return 0;
}