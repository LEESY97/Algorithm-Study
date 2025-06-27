#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {

	string order;
	string command[6] = { "push","pop","size","empty","front","back" };
	int n;
	deque<int> q;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> order;
		if (order == command[0]) {
			int temp;
			cin >> temp;
			q.push_back(temp);
		}
		else if (order == command[1]) {
			if (q.empty())cout << "-1\n";
			else {
				int temp = q.front(); q.pop_front();
				cout << temp << "\n";
			}
		}
		else if (order == command[2]) {
			cout << q.size() << "\n";
		}
		else if (order == command[3]) {
			if (q.empty())cout << "1\n";
			else cout << "0\n";
		}
		else if (order == command[4]) {
			if (q.empty())cout << "-1\n";
			else cout << q.front() << "\n";
		}
		else if (order == command[5]) {
			if (q.empty())cout << "-1\n";
			else cout << q.back() << "\n";
		}
	}

	return 0;
}