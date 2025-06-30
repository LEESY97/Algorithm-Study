#include <iostream>
#include <string>

using namespace std;

int main() {

	string num;
	cin >> num;
	int sum = 0;
	int way[2] = { 1,3 };
	int hidden = 0;
	int result = 0;
	int cnt = 0;
	for (int i = 0; i < 12; i++) {
		if (num[i] == '*') {
			hidden = way[cnt];
			cnt = (cnt + 1) % 2;
			continue;
		}
		sum += (num[i] - '0') * way[cnt];
		cnt = (cnt + 1) % 2;
	}
	if (num[12] == '0') {
		if (hidden == 1) {
			result = 10 * ((sum / 10) + 1) - sum;
		}
		else {
			int temp = 10 * ((sum / 10) + 1) - sum;
			while (temp < 30) {
				if (temp % 3 == 0) {
					result = temp / 3;
					break;
				}
				else temp += 10;
			}
		}
	}
	else {
		if (hidden == 1) {
			result = (10 - (num[12] - '0')) - sum % 10;
			if (result < 0) {
				result += 10;
			}
		}
		else {
			int temp = (10 - (num[12] - '0')) - sum % 10;
			if (temp < 0) {
				temp += 10;
			}
			while (temp < 30) {
				if (temp % 3 == 0) {
					result = temp / 3;
					break;
				}
				else temp += 10;
			}
		}
	}

	cout << result;

	return 0;
}