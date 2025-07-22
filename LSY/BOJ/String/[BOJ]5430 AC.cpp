#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>

using namespace std;

int T, dt_l;
string input;
bool dir = 1;
int st, ed;

void ER() {
    cout << "error\n";
}

void RESULT(vector<int> ret) {
    cout << "[";

    // 정방향
    if (dir == 1) {
        for (int i = st; i < ed; i++) {
            cout << ret[i];
            if (i != ed-1) cout << ",";
        }
    }
    else {// 역방향
        for (int i = ed-1; i >= st; i--) {
            cout << ret[i];
            if (i != st) cout << ",";
        }
    }

    cout << "]\n";
}

void R() {
    dir = !dir;
}

void D() {
    // 정방향
    if (dir == 1) {
        st++;
    }
    // 역방향
    else {
        ed--;
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    for (int t = 0; t < T; t++) {
        int flag = 1;
        dir = 1;
        string cmd;
        vector<int> com, ret;

        cin >> cmd >> dt_l;
        cin >> input;

        // init
        input[0] = ','; input[input.size() - 1] = ',';
        for (int i = 0; i < input.size(); i++) {
            if (input[i] == ',') com.push_back(i);
        }
        for (int i = 0; i < com.size() - 1; i++) {
            if (dt_l == 0) continue;
            ret.push_back(stoi(input.substr(com[i] + 1, com[i + 1] - com[i] - 1)));
        }

        st = 0; ed = ret.size();

        for (int i = 0; i < cmd.size(); i++) {
            if (cmd[i] == 'R') R();
            else if (cmd[i] == 'D') D();

            if (st > ed) {
                flag = 0;
                break;
            }
        }

        if (flag == 1) RESULT(ret);
        else ER();
    }

    return 0;
}
