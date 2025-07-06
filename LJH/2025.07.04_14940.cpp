#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct col {
    int y, x;
};

int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };

void bfs(vector<vector<int>>& map, int y, int x, int n, int m) {
    queue<col>q;
    q.push({ y,x });
    
    while (!q.empty()) {
        col now = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            if (ny >= 0 && ny < n && nx >= 0 && nx < m && map[ny][nx] == 1) {
                map[ny][nx] = map[now.y][now.x] + 1;
                q.push({ ny,nx });
            }
        }
    }
}

int main() {

    int n, m;
    cin >> n >> m;
    vector<vector<int>>map(n, vector<int>(m));
    int y, x;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                y = i, x = j;
            }
        }
    }
    map[y][x] = 2;
    bfs(map, y, x, n, m);
    map[y][x] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == y && j == x)cout << "0 ";
            else if (map[i][j] == 0)cout << "0 ";
            else if (map[i][j] == 1)cout << "-1 ";
            else cout << map[i][j] - 2 << " ";
        }
        cout << "\n";
    }

    return 0;
}