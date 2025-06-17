#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	vector<int> input(N);
	vector<int> vec(N);

	int a;
	for (int i = 0;i < N;i++) {
		cin >> input[i];
		vec[i] = input[i];
	}

	
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	for (int i = 0;i < N;i++) {
		auto result = lower_bound(vec.begin(), vec.end(), input[i]);
		cout << result - vec.begin() << " ";
	}
	return 0;
}
