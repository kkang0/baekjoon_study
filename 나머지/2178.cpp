#include <iostream>
#include <queue>
#include <string>
#define endl '\n'
using namespace std;

int N, M;
int maze[101][101];
int dist[101][101];
// bool visited[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void init() {
    cin >> N >> M;
    
    string s;
    for(int i = 1; i <= N; i++) {
        cin >> s;
        for(int j = 1; j <= M; j++) {
            maze[i][j] = s[j - 1] - '0';
        }
    }
}

void printMaze() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cout << maze[i][j] << ' ';
        }
        cout << endl;
    }
}

int bfs() {
    queue<pair<int, int>> q;
    q.push({1, 1});
    // visited[1][1] = true;
    dist[1][1] = 1;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx <= 0 || ny <= 0 || nx > N || ny > M) continue;
            if(maze[nx][ny] == 0) continue;
            if(dist[nx][ny] != 0) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }

    return dist[N][M];
}

int main(void) {
    init();

    cout << bfs() << endl;

    return 0;
}