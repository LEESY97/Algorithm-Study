#include <iostream>
#include <vector>

using namespace std;

int p[1001];

int find(int a) {
	if (a == p[a])return p[a];
	else return find(p[a]);
}

void Union(int a, int b) {
	int roota = find(a);
	int rootb = find(b);
	if (roota != rootb)p[b] = p[a];
}

int main() {

	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) p[i] = i;

	vector<vector<int>>map(n + 1);

	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		map[from].push_back(to);
		map[to].push_back(from);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < map[i].size(); j++) {
			Union(i, map[i][j]);
		}
	}
	int dat[1001] = { 0 };
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		dat[p[i]] = 1;
	}
	for (int i = 0; i <= n; i++) {
		if (dat[i] == 1)cnt++;
	}
	cout << cnt;

	return 0;
}