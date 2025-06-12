#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>

using namespace std;

int N, M;
vector<int> arr;

// 총 갯수 계산기
long long check(long long val) {
	long long total = 0;
	for (int i = 0;i < N;i++) {
		if (arr[i] > val) total += arr[i] - val;
	}

	return total;
}

// 최대 길이 측정
long long sol(long long ed) {
	long long result = 0;
	long long st = 0;
	
	while (st <= ed) {
		long long mid = (st + ed) / 2;
		long long cut = check(mid);
		if (cut >= M) {
			result = mid;
			st = mid + 1;
		}
		else {
			ed = mid - 1;
		}
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	
	cin >> N >> M;

	long long a;
	long long max_val=0;
	for (int i = 0;i < N;i++) {
		cin >> a;
		arr.push_back(a);
		max_val = max(max_val, a);
	}

	cout << sol(max_val);

	return 0;
}
