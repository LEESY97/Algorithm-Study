#include<iostream>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

int N;
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };

char draw[100][100];
int visited[2][100][100];
int result[2];

bool in_range(int ny, int nx) {
    return ny >= 0 && ny < N && nx >= 0 && nx < N;
}

void bfs0(pair<int, int>now) {
    queue<pair<int, int>>q;
    q.push(now);
    visited[0][now.first][now.second] = 1;
    char ch = draw[now.first][now.second];

    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop(); 
        for (int i = 0; i < 4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];
            if (!in_range(ny, nx) || visited[0][ny][nx] != 0) continue;
            if (ch != draw[ny][nx]) continue;
            q.push({ ny,nx });
            visited[0][ny][nx] = 1;
        }
    }
    result[0]++;
}

void bfs1(pair<int, int>now) {
    queue<pair<int, int>>q;
    q.push(now);
    visited[1][now.first][now.second] = 1;
    char ch = draw[now.first][now.second];

    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];
            if (!in_range(ny, nx) || visited[1][ny][nx] != 0) continue;
            if (ch == 'B' && draw[ny][nx] != 'B') continue;
            if (ch != 'B' && draw[ny][nx] == 'B') continue;
            q.push({ ny,nx });
            visited[1][ny][nx] = 1;
        }
    }
    result[1]++;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    string input;
    for (int i = 0; i < N; i++) {
        cin >> input;
        for (int j = 0; j < N; j++) {
            draw[i][j] = input[j];
        }
    }

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (visited[0][y][x] == 0) bfs0({ y,x });
            if (visited[1][y][x] == 0) bfs1({ y,x });
        }
    }

    cout << result[0] << " " << result[1];

    return 0;
}
