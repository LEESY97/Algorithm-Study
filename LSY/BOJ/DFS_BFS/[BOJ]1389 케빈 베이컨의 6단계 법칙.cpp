#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int N, M;
vector<int>friends[101];
vector<pair<int, int>>result;


int sol(int now) {
	int ret = 0;
	vector<int>visited(101, 1000);
	queue<int>q;

	visited[now] = 0;
	q.push(now);

	while (!q.empty()) {
		int cur = q.front();q.pop();
		for (int i = 0;i < friends[cur].size();i++) {
			if (visited[friends[cur][i]] <= visited[cur] + 1) continue;
			q.push(friends[cur][i]);
			visited[friends[cur][i]] = visited[cur] + 1;
		}
	}

	for (int i = 1;i < N + 1;i++) {
		if (i == now) continue;
		ret += visited[i];
	}

	return ret;
}


int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	int a, b;
	for (int i = 0;i < M;i++) {
		cin >> a >> b;
		friends[a].push_back(b);
		friends[b].push_back(a);
	}

	for (int i = 1;i <= N;i++) {
		int ret = sol(i);
		result.push_back({ ret,i });
	}

	sort(result.begin(),result.end());

	cout << result.front().second;

	return 0;
}
