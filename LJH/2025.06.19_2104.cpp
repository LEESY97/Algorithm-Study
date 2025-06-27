#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<ll> prefix(n + 1, 0);
    for (int i = 0; i < n; i++)
        prefix[i + 1] = prefix[i] + a[i];

    vector<int> left(n), right(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] >= a[i])
            st.pop();
        left[i] = st.empty() ? 0 : st.top() + 1;
        st.push(i);
    }

    while (!st.empty()) st.pop();

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && a[st.top()] >= a[i])
            st.pop();
        right[i] = st.empty() ? n - 1 : st.top() - 1;
        st.push(i);
    }

    ll max_value = 0;
    for (int i = 0; i < n; i++) {
        ll total_sum = prefix[right[i] + 1] - prefix[left[i]];
        max_value = max(max_value, total_sum * a[i]);
    }

    cout << max_value << '\n';
    return 0;
}