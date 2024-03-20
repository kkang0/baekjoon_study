#include <iostream>
#define endl '\n'
using namespace std;

int T, M, N, K;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int matrix[51][51];
bool visited[51][51];

void reset() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            matrix[i][j] = 0;
            visited[i][j] = false;
        }
    }
}


void dfs(int x, int y) {
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        if(matrix[nx][ny] == 1 && !visited[nx][ny]) {
            visited[nx][ny] = true;
            dfs(nx, ny);
        }
    }
}

int main(void) {
    cin >> T;

    for(int k = 0; k < T; k++) {
        cin >> M >> N >> K;

        int result = 0;
        for(int j = 0; j < K; j++) {
            int x, y;
            cin >> x >> y;
            
            matrix[y][x] = 1;
        }

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(matrix[i][j] == 1 && !visited[i][j]) {
                    visited[i][j] = true;
                    result++;
                    dfs(i, j);
                }
            }
        }

        cout << result << endl;
        reset();
    }

    return 0;
}