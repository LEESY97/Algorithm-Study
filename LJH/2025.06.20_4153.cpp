#include <iostream>

using namespace std;

int main() {

	int len[3];
	while (true) {
		int max = 0, idx;
		for (int i = 0; i < 3; i++) {
			cin >> len[i];
			if (len[i] > max) {
				max = len[i];
				idx = i;
			}
		}
		if (len[0] == 0 && len[1] == 0 && len[2] == 0)break;
		int temp = 0;
		for (int i = 0; i < 3; i++) {
			if (i == idx)continue;
			temp += (len[i] * len[i]);
		}
		if (len[idx] * len[idx] == temp)cout << "right\n";
		else cout << "wrong\n";
	}

	return 0;
}