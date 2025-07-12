#include <iostream>
#include <vector>

using namespace std;

struct thing {
	int w, v;
};

int main() {

	int n, k;
	vector<thing> some;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int w, v;
		cin >> w >> v;
		if (w > k)continue;
		some.push_back({ w,v });
	}

	int value[100001] = { 0 };
	for (int i = 0; i < some.size(); i++) {
		for (int j = k; j >= some[i].w; j--) {
			value[j] = max(value[j], value[j - some[i].w] + some[i].v);
		}
	}

	cout << value[k];

	return 0;
}