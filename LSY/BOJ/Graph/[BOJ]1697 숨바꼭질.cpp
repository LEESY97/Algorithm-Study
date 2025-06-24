#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

vector<int> map(100001, 9999999);
int N, K;
int ds[] = { 1,1,2 };
int dp[] = { 1,-1,0 };

int in_range(int now) {
	return now >= 0 && now <= 100000;
}

void sol() {
	queue<int> q;
	q.push(N);

	while (!q.empty()) {
		int cur = q.front();q.pop();
		for (int i = 0;i < 3;i++) {
			int now = cur * ds[i] + dp[i];
			if (!in_range(now)||(map[now] < (map[cur]+1))) continue;
			map[now] = map[cur] + 1;
			q.push(now);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	cin >> N >> K;
	map[N] = 0;

	sol();

	cout << map[K];

	return 0;
}
