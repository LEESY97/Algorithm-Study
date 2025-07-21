#include <iostream>

using namespace std;

int64_t power(int64_t a, int64_t b, int64_t c) {
    if (b == 0) return 1;
    int64_t half = power(a, b / 2, c);
    int64_t result = (half * half) % c;
    if (b % 2 == 1) {
        result = (result * a) % c;
    }
    return result;
}

int main() {
    int64_t A, B, C;
    cin >> A >> B >> C;
    cout << power(A, B, C) << "\n";
    return 0;
}