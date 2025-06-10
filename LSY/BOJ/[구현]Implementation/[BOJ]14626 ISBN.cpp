#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>

using namespace std;

string ch;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> ch;

	// * 위치 찾기
	int idx = ch.find("*");

	// * 가중치 계산 1 or 3
	int offset = idx % 2 * 3;
	if (offset == 0) offset = 1;

	// 총합
	int result = 0;
	for (int i = 0;i < 13;i++) {
		if (i == idx) continue;
		if (i % 2 == 0) {
			result += (ch[i]-'0');
		}
		else {
			result += (ch[i] - '0')*3;
		}
	}

	// mod 확인
	result %= 10;


	// 출력
	for (int i = 0;i < 10;i++) {

		if ((result + (i * offset)) % 10 == 0) {
			cout << i;
			break;
		}
	}

	return 0;
}
