#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int T;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    priority_queue<int> L;
    priority_queue<int,vector<int>,greater<int>> R;

    int a;
    for (int i = 0; i < T; i++) {
        cin >> a;
        if (L.size() <= R.size()) L.push(a);
        else R.push(a);

        if (L.size() != 0 && R.size() != 0 && L.top() > R.top()) {
            R.push(L.top()); L.pop();
            L.push(R.top()); R.pop();
        }

        cout << L.top() << "\n";
    }

    return 0;
}
