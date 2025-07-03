#include <iostream>
#include <vector>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<int>num;
	num.push_back(0);
	for (int i = 1; i <= n; i++) {
		int temp;
		cin >> temp;
		num.push_back(num[i - 1] + temp);
	}
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		cout << num[to] - num[from - 1] << "\n";
	}

	return 0;
}