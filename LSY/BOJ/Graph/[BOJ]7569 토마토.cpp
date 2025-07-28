#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int M, N, H;
int box[101][101][101];
int dy[] = { 0,0,1,-1,0,0 };
int dx[] = { 1,-1,0,0,0,0 };
int dz[] = { 0,0,0,0,1,-1 };
int rest;
int day;

struct node
{
    int z,y,x;
};
queue<node> q;

int in_range( int nz, int ny, int nx) {
    return ny >= 0 && ny < N && nx >= 0 && nx < M && nz >= 0 && nz < H;
}

void sol() {
    while (!q.empty()) {
        int num = q.size();
        while (num--) {
            node cur = q.front(); q.pop();
            for (int i = 0; i < 6; i++) {
                int ny = cur.y + dy[i];
                int nx = cur.x + dx[i];
                int nz = cur.z + dz[i];
                if (!in_range(nz, ny, nx) || box[nz][ny][nx] != 0) continue;
                q.push({ nz,ny,nx });
                box[nz][ny][nx] = box[cur.z][cur.y][cur.x] + 1;
                rest--;
                day = max(day, box[cur.z][cur.y][cur.x]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N >> H;

    for (int z = 0; z < H; z++) {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                cin >> box[z][y][x];
                if (box[z][y][x] == 1) q.push({ z,y,x });
                if (box[z][y][x] == 0) rest++;
            }
        }
    }

    sol();

    if (rest > 0) cout << -1;
    else cout << day;

    return 0;
}
