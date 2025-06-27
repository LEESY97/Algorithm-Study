#include <iostream>

using namespace std;

int main() {

	int n, size[6], t, p, shirt = 0, pen = 0, one = 0;
	cin >> n;
	for (int i = 0; i < 6; i++) {
		cin >> size[i];
	}
	cin >> t >> p;
	for (int i = 0; i < 6; i++) {
		if (size[i] % t != 0) shirt += ((size[i] / t) + 1);
		else shirt += size[i] / t;
	}
	pen = n / p;
	one = n % p;
	cout << shirt << "\n";
	cout << pen << " " << one;

	return 0;
}