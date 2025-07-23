#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string S;
int N, M;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> S;

    int st = 0;
    int result = 0;
    int cnt = 0;
    while (st < M-2) {
        if (S[st] == 'I') {
            if (S[st + 1] == 'O' && S[st + 2] == 'I') {
                st += 2;
                cnt++;
                if (cnt >= N) result++;
            }
            else {
                st++;
                cnt = 0;
            }
        }
        else {
            st++;
            cnt = 0;
        }
    }

    cout << result;
    return 0;
}
