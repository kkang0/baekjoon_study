#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;
int M, N;
int tomato[1001][1001];
int days[1001][1001];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<pair<int, int>> q;

void init() {
    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> tomato[i][j];
            days[i][j] = -1;
            
            if(tomato[i][j] == 1) {
                q.push({i, j});
                days[i][j] = 0;
            }
        }
    }
}

void bfs() {
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(tomato[nx][ny] == 0 && days[nx][ny] == -1) {
                days[nx][ny] = days[x][y] + 1;  // 날 증가
                q.push({nx, ny});
            }
        }
    }
}

int main(void) {
    init();
    bfs();
    int result = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            result = max(result, days[i][j]);
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(tomato[i][j] == 0 && days[i][j] == -1) {
                result = -1;
            }
        }
    }

    cout << result << endl;
    return 0;
}