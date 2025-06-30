#include <iostream>

using namespace std;

int main() {

	int n;
	cin >> n;
	int num[100] = { 0 };
	int cnt = 0;
	int flag = 1;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		if (num[i] == 1)continue;
		int flag = 1;
		for (int j = 2; j < num[i]; j++) {
			if (num[i] % j == 0) {
				flag = 0;
				break;
			}
		}
		if (flag == 1)cnt++;
	}
	cout << cnt;

	return 0;
}