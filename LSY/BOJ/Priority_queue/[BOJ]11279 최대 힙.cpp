#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>

using namespace std;

priority_queue<int> pq;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	int a;
	for (int i = 0;i < N;i++) {
		cin >> a;
		if (a == 0) {
			// pq에 값이 있으면 최대 값 없으면 0
			if (!pq.empty()) {
				cout << pq.top() << "\n"; pq.pop();
			}
			else {
				cout << 0 << "\n";
			}
		}
		else {
			pq.push(a);
		}
	}

	return 0;
}
