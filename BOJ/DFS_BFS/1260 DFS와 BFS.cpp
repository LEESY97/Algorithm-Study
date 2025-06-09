#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

int N, M, V;
vector<int> gp[1001];
int visited[2][1001];
queue<int> q;

vector<int> bfs;
vector<int> dfs;

void bsol(int now) {
	visited[0][now] = 1;
	dfs.push_back(now);

	for (int i = 0; i < gp[now].size(); i++) {
		if (visited[0][gp[now][i]] == 1) continue;
		bsol(gp[now][i]);
	}
}
void dsol(int now) {
	visited[1][now] = 1;
	q.push(now);
	bfs.push_back(now);

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		for (int i = 0;i < gp[cur].size();i++) {
			if (visited[1][gp[cur][i]] == 1) continue;
			q.push(gp[cur][i]);
			bfs.push_back(gp[cur][i]);
			visited[1][gp[cur][i]] = 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> V;
	
	// 간선 입력
	for (int i = 0;i < M;i++) {
		int a, b;
		cin >> a >> b;
		gp[a].push_back(b);
		gp[b].push_back(a);
	}

	// 간선 오름차순
	for (int i = 1;i <= N;i++) {
		sort(gp[i].begin(), gp[i].end());
	}

	// 풀이
	dsol(V);
	bsol(V);

	// 결과 출력
	for (int i = 0;i < dfs.size();i++) {
		cout << dfs[i] << " ";
	}
	cout << "\n";
	for (int i = 0;i < bfs.size();i++) {
		cout << bfs[i] << " ";
	}

	return 0;
}
