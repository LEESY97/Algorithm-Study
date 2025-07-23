#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>

using namespace std;

int N;
int num[10];
int types;
queue<int> tangtanghuruhuru;
int result;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    int input;
    while (N--) {
        cin >> input;

        tangtanghuruhuru.push(input);
        if (num[input]++ == 0) types++;

        while (types > 2) {
            int st = tangtanghuruhuru.front(); tangtanghuruhuru.pop();

            if (--num[st] == 0) types--;
        }


        result = max(result, (int)tangtanghuruhuru.size());
    }

    cout << result;

    return 0;
}
