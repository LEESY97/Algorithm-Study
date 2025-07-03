#include <iostream>
#include <vector>

using namespace std;

int64_t cut(const vector<int>& tree, int h) {
	int64_t sum = 0;
	for (int64_t i : tree) {
		if (i > h) sum += i - h;
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int64_t n, m;
	cin >> n >> m;
	vector<int>tree(n);
	int64_t max = 0;
	for (int i = 0; i < n; i++) {
		cin >> tree[i];
		if (max < tree[i])max = tree[i];
	}
	int64_t left = 0;
	int64_t right = max;
	int64_t sum = 0;

	while (left <= right) {
		int64_t mid = (left + right) / 2;

		int64_t wood = cut(tree, mid);

		if (wood >= m) {
			sum = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << sum;

	return 0;
}