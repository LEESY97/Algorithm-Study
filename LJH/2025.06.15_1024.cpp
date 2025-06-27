#include <iostream>

using namespace std;

int main() {

	int n, l;
	cin >> n >> l;
	int result = -1;

	for (l; l <= 100; l++) {
		if ((n - (l * (l - 1) / 2)) % l == 0) {
			result = (n - (l * (l - 1) / 2)) / l;
			break;
		}
	}

	if (result < 0) cout << "-1";
	else {
		for (int i = 0; i < l; i++) {
			cout << result << " ";
			result++;
		}
	}
	

	return 0;
}