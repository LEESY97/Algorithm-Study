#include <iostream>

using namespace std;

int main() {

	int n, max = 0;
	double sum = 0;
	double score[1000] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> score[i];
		if (score[i] > max)max = score[i];
	}
	for (int i = 0; i < n; i++) {
		score[i] = score[i] / max * 100;
		sum += score[i];
	}
	double avg = sum / n;
	cout << avg;

	return 0;
}