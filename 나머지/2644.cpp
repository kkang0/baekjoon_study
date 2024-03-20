#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;

int n, x, y, m;
int matrix[101][101];
int visited[101];
queue<int> q;

void init() {
    cin >> n;
    cin >> x >> y;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int nx, ny;
        cin >> nx >> ny;

        matrix[nx][ny] = 1;
        matrix[ny][nx] = 1;
    }

}

int bfs(int cur) {
    q.push(cur);
    visited[cur] = 1;

    while(!q.empty()) {
        int cur_x = q.front();
        q.pop();

        for(int i = 1; i <= n; i++) {
            if(!visited[i] && matrix[cur_x][i]) {
                visited[i] = visited[cur_x] + 1;
                q.push(i);
            }
        }
    }

    return 0;
}

int main(void) {
    init();
    
    int count = 0;
    bfs(x);
    
    if(visited[y] == 0) {
        cout << -1 << endl;
    }
    else {
        cout << visited[y] - 1 << endl;
    }

    return 0;
}