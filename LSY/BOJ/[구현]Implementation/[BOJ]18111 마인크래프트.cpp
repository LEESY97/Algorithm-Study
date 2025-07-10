#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

int N, M, B;
int block[500][500];

int check(int h) {
    int ret=0;
    int blocks = B;

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (block[y][x] > h) {
                ret += (block[y][x] - h) * 2;
                blocks += (block[y][x] - h);
            }
            if (block[y][x] < h) {
                ret += (h - block[y][x]);
                blocks -= (h - block[y][x]);
            }
        }
    }
    if (blocks >= 0) return ret;

    return -1;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> B;

    int result[2] = { 2100000000,0 };

    int max_val = 0;
    int min_val = 2100000000;

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> block[y][x];
            max_val = max(max_val, block[y][x]);
            min_val = min(min_val, block[y][x]);
        }
    }

    for (int h = min_val; h <= max_val; h++) {
        int t = check(h);
        if (t >= 0) {
            if (result[0] >= t) {
                result[0] = t;
                result[1] = h;
            }
        }
    }

    cout << result[0] << " " << result[1];

    return 0;
}
