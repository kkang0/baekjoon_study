#include <iostream>
#define endl '\n'
using namespace std;

int N, max_num;
int matrix[101][101];
bool visited[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void reset() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            visited[i][j] = false;
        }
    }
}

void init() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> matrix[i][j];
            
            if(max_num < matrix[i][j]) {
                max_num = matrix[i][j];
            }
        }
    }
}

void dfs(int x, int y, int m) {
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
        if(visited[nx][ny]) continue;
        if(matrix[nx][ny] <= m) continue;
        visited[nx][ny] = true;
        dfs(nx, ny, m);
    }
}

int main(void) {
    init();

    int ans = 1;
    for(int m = 0; m < max_num; m++) {
        int check = 0;
        reset();
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(!visited[i][j] && matrix[i][j] > m) {
                    visited[i][j] = true;
                    dfs(i, j, m);
                    check++;
                }
            }
        }

        ans = max(ans, check);

    }

    cout << ans << endl;

    return 0;
}