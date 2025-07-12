#include <iostream>
#include <string>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int m;
	cin >> m;
	int s[21] = { 0 };
	string order;
	int x;
	for (int i = 0; i < m; i++) {
		cin >> order;
		if (order == "all") {
			for (int i = 1; i <= 20; i++) s[i] = 1;
		}
		else if (order == "empty")for (int i = 1; i <= 20; i++) s[i] = 0;
		else {
			cin >> x;
			if (order == "add") s[x] = 1;
			else if (order == "remove") s[x] = 0;
			else if (order == "check") cout << s[x] << "\n";
			else if (order == "toggle") {
				if (s[x] == 0)s[x] = 1;
				else s[x] = 0;
			}
		}
	}


	return 0;
}