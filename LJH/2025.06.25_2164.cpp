#include <iostream>
#include <deque>

using namespace std;

int main() {

	int n;
	deque<int>a;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		a.push_back(i);
	}
	int temp;
	while (a.size() > 1) {
		a.pop_front();
		temp = a.front(); a.pop_front();
		a.push_back(temp);
	}
	cout << a[0];

	return 0;
}