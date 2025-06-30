#include <iostream>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;
	int sixmin = 1001, onemin = 1001;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (a < sixmin)sixmin = a;
		if (b < onemin)onemin = b;
	}
	int result;
	if (onemin * 6 < sixmin)result = onemin * n;
	else if (onemin * (n % 6) > sixmin) {
		result = sixmin * ((n / 6) + 1);
	}
	else {
		result = sixmin * (n / 6) + onemin * (n % 6);
	}
	cout << result;

	return 0;
}