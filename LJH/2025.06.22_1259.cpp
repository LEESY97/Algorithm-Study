#include <iostream>
#include <string>

using namespace std;

int main() {

	string num = "";
	while (true) {
		cin >> num;
		if (num[0] == '0')break;
		int flag = 0;
		int cnt = 0;
		int len = num.length();
		while (cnt <= len - 1 - cnt && len - 1 - cnt >= 0) {
			if (num[cnt] == num[num.length() - 1 - cnt]) {
				flag = 1;
			}
			else {
				flag = 0;
				break;
			}
			cnt++;
		}
		if (flag == 0)cout << "no\n";
		else cout << "yes\n";
	}

	return 0;
}