#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

long long st, ed;
long long cnt[58];

long long get1(long long now) {
    int now_l = 57;
    long long result = 0;
    long long num = 0;
    for (now_l; now_l >= 0; now_l--) {
        if ((now & (1LL << now_l)) == 0)continue;
        result += cnt[now_l] + (1LL << now_l) * num;
        num++;
    }
    result += num;

    return result;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> st >> ed;

    cnt[0] = 0;
    for (int i = 1; i < 58; i++) {
        cnt[i] = (2 * cnt[i - 1]) + (1LL << (i - 1));
    }

    cout << get1(ed) - get1(st - 1);

    return 0;
}
