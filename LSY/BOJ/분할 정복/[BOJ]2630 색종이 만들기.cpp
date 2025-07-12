#include<iostream>
#include<string>
#include<vector>

using namespace std;

int N;
int map[128][128];
int result[2];

int dy[] = { 0,0,1,1 };
int dx[] = { 0,1,0,1 };

struct node {
    int y, x;
    int dist;
};

bool in_range(int ny, int nx) {
    return ny >= 0 && ny < N && nx >= 0 && nx < N;
}

bool check(node now, int color);
void sol(node now) {


    for (int local = 0; local < 4; local++) {
        int cur_y = now.y + dy[local] * now.dist;
        int cur_x = now.x + dx[local] * now.dist;
        int color = map[cur_y][cur_x];

        if (!in_range(cur_y, cur_x)) continue;

        if (!check({ cur_y,cur_x,now.dist }, color)) continue;

        result[color]++;
    }

    return;
}

bool check(node now,int color) {
    for (int i = 0; i < now.dist; i++) {
        for (int j = 0; j < now.dist; j++) {
            if (map[now.y + i][now.x + j] == color) continue;
            sol({ now.y,now.x,now.dist / 2 });
            return 0;
        }
    }
    return 1;
}

int main() {

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    sol({ 0,0,N });

    cout << result[0] << "\n" << result[1];

    return 0;
}
