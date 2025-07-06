#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct h {
	int start, end;

	bool operator< (h right) const {
		if (end < right.end)return true;
		else if (end > right.end)return false;
		return start < right.start;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<h> com;
	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		com.push_back({ start,end });
	}
	sort(com.begin(), com.end());
	int cnt = 0;
	int now = 0;
	for (int i = 0; i < n; i++) {
		if (now > com[i].start)continue;
		cnt++;
		now = com[i].end;
	}
	cout << cnt;
	
	return 0;
}