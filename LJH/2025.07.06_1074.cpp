#include <iostream>
#include <cmath>
using namespace std;

int Z(int n, int r, int c) {
    if (n == 0) return 0;

    int half = 1 << (n - 1);
    int area_size = half * half;

    // r,c가 어느 사분면에 속하는지 확인
    if (r < half && c < half) {
        // 1사분면(왼위)
        return Z(n - 1, r, c);
    }
    else if (r < half && c >= half) {
        // 2사분면(오른위)
        return area_size + Z(n - 1, r, c - half);
    }
    else if (r >= half && c < half) {
        // 3사분면(왼아래)
        return area_size * 2 + Z(n - 1, r - half, c);
    }
    else {
        // 4사분면(오른아래)
        return area_size * 3 + Z(n - 1, r - half, c - half);
    }
}

int main() {
    int N, r, c;
    cin >> N >> r >> c;
    cout << Z(N, r, c) << endl;
    return 0;
}