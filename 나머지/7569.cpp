#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int M, N, H;
int tomato[102][102][102];
int days[102][102][102];
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
queue<pair<pair<int, int>, int>> q;

void init() {
    cin >> M >> N >> H;

    for(int k = 0; k < H; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                cin >> tomato[i][j][k];

                if(tomato[i][j][k] == 1) {
                    q.push({{i, j}, k});
                }
                if(tomato[i][j][k] == 0) {
                    days[i][j][k] = -1;
                }
            }
        }
    }
}

void bfs() {
    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int z = q.front().second;
        q.pop();

        for(int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];


            if(nx < 0 || ny < 0 || nz < 0 || nx >= N || ny >= M || nz >= H) continue;
            if(days[nx][ny][nz] >= 0) continue;
            days[nx][ny][nz] = days[x][y][z] + 1;
            q.push({{nx, ny}, nz});
        }
    }
}

int main(void) {
    init();
    bfs();

    int ans = 0;
    for(int k = 0; k < H; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(days[i][j][k] == -1) {
                    cout << -1 << endl;
                    return 0;
                }
                
                ans = max(ans, days[i][j][k]);
            }
        }
    }

    cout << ans << endl;

    return 0;
}