#include <iostream>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;
	int less, more;
	int min;
	if (n > m)less = m, more = n;
	else less = n, more = m;
	for (int i = 1; i <= less; i++) {
		if (less % i == 0 && more % i == 0) {
			min = i;
		}
	}
	int a = 1, b = 1;
	int maxa = n, maxb = m;
	while (maxa != maxb) {
		if (maxa > maxb) {
			maxb = m * b;
			b++;
		}
		if (maxa < maxb) {
			maxa = n * a;
			a++;
		}
	}
	cout << min << "\n";
	cout << maxa;

	return 0;
}