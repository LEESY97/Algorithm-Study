#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

struct cmp {
	int num;

	bool operator<(const cmp& other) const {
		if (abs(num) == abs(other.num)) return num > other.num;
		return abs(num) > abs(other.num);
	}
};

priority_queue<cmp> pq;
int N;



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	cin >> N;
	
	int a;
	for (int i = 0;i < N;i++) {
		cin >> a;
		if (a != 0)pq.push({ a });
		else {
			if (!pq.empty()) { 
				cout << pq.top().num << "\n"; pq.pop(); 
			}
			else cout << "0\n";
			
		}
	}
	return 0;
}
