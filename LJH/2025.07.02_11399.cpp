#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int n;
	cin >> n;
	vector<int>man(n);
	for (int i = 0; i < n; i++)cin >> man[i];
	sort(man.begin(), man.end());
	vector<int>time(n);
	int result = man[0];
	time[0] = man[0];
	for (int i = 1; i < n; i++) {
		time[i] += (time[i - 1] + man[i]);
		result += time[i];
	}
	cout << result;

	return 0;
}