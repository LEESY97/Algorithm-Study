#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool find(const vector<int64_t>& arr, int64_t num) {
	int left = 0;
	int right = arr.size() - 1;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (arr[mid] == num) {
			return true; // 찾았다!
		}
		else if (arr[mid] < num) {
			left = mid + 1; // 오른쪽으로 탐색
		}
		else {
			right = mid - 1; // 왼쪽으로 탐색
		}
	}

	return false; // 못 찾았을 때
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	vector<int64_t>a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int64_t temp;
		cin >> temp;
		a.push_back(temp);
	}
	sort(a.begin(), a.end());
	cin >> m;

	int64_t num;
	for (int i = 0; i < m; i++) {
		cin >> num;
		if (find(a,num)) cout << "1\n";
		else cout << "0\n";
	}

	return 0;
}