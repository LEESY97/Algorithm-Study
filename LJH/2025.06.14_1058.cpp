#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

	int n;
	cin >> n;
	vector<vector<int>>fs;
	fs.resize(n, vector<int>());
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < n; j++) {
			if (temp[j] == 'Y') {
				fs[i].push_back(j);
			}
		}
	}

	int max = 0;
	for (int i = 0; i < n; i++) {
		int visited[50] = { 0 };
		int cnt = 0;
		cnt = size(fs[i]);
		visited[i] = 1;
		for (int j = 0; j < size(fs[i]); j++) visited[fs[i][j]] = 1;
		for (int j = 0; j < size(fs[i]); j++) {
			for (int k = 0; k < size(fs[fs[i][j]]); k++) {
				if (visited[fs[fs[i][j]][k]] != 1) {
					cnt++;
					visited[fs[fs[i][j]][k]] = 1;
				}
			}
		}
		if (cnt > max)max = cnt;
	}
	cout << max;

	return 0;
}