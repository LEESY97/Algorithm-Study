#include<iostream>
#include<string>
#include<vector>

using namespace std;

string input;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> input;

    string num;

    int flag = 1;

    int result = 0;

    for (int i = 0; i < input.size(); i++) {
        if (input[i] >= '0' || input[i] <= '9') num += input[i];
        if (input[i] == '-') {
            result += (stoi(num) * flag);
            num = "";
            flag = -1;
        }
        else if (input[i] == '+') {
            result += (stoi(num) * flag);
            num = "";
        }
    }
    result += (stoi(num) * flag);

    cout << result;

    return 0;
}
