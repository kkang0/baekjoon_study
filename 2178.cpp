// DFS와 BFS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> edges[105];
int maze[105][105];
int N, M, u, v;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool vis[105][105] = { 0, };

void bfs(int x, int y) {
    queue<pair<int, int> > q;

    vis[x][y] = 1;
    q.push({x, y});

    while (!q.empty()) {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();

        for (int i =0 ; i < 4; i++) {
            int nx = curx + dx[i];
            int ny = cury + dy[i];

            if (nx < 0 || nx > N || ny < 0 || ny > M) {
                continue;
            }

            if(!vis[nx][ny] && maze[nx][ny] == 1) {
                vis[nx][ny] = true;
                q.push({nx, ny});
                maze[nx][ny] = maze[curx][cury] + 1;
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;

    string input;
    for (int i = 0; i < N; i++) {
        cin >> input;
        for (int j = 0; j < M; j++) {
            maze[i][j] = input[j] - '0';
        }
    }

    bfs(0, 0);

    cout << maze[N -1][M -1];
    
    return 0;
}