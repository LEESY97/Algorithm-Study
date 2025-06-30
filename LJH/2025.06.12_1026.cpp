#include <iostream>
#include <vector>

using namespace std;

int main() {

	int n;
	cin >> n;
	vector<int>a, b, useda, usedb, newa;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		a.push_back(temp);
	}
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		b.push_back(temp);
	}
	useda.resize(n, -1);
	usedb.resize(n, -1);
	newa.resize(n, -1);
	int cnt = 0;
	int locb, loca;
	while (cnt < n) {
		int max = -1;
		int min = 101;
		for (int i = 0; i < n; i++) {
			if (usedb[i] != -1)continue;
			if (max < b[i]) {
				max = b[i];
				locb = i;
			}
		}
		usedb[locb] = 1;
		for (int i = 0; i < n; i++) {
			if (useda[i] != -1)continue;
			if (min > a[i]) {
				min = a[i];
				loca = i;
			}
		}
		useda[loca] = 1;
		newa[locb] = a[loca];
		cnt++;
	}
	int sum = 0;
	for (int i = 0; i < n; i++) sum += newa[i] * b[i];
	cout << sum;

	return 0;
}