#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct node {
	int st, ed;
};

vector<node> times;

bool cmp(node left, node right) {
	if (left.ed < right.ed) return 1;
	if (left.ed > right.ed) return 0;

	return left.st < right.st;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	int a,b;
	for (int i = 0;i < N;i++) {
		cin >> a >> b;
		times.push_back({ a,b });
	}

	sort(times.begin(), times.end(), cmp);

	int cnt = 0;
	int start = -1;
	for (int i = 0; i < times.size(); i++) {
		if (times[i].st < start) continue;
		cnt++;
		start = times[i].ed;
	}

	cout << cnt;

	return 0;
}
