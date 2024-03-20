#include <iostream>
#include <algorithm> 
#include <queue>
#include <vector>
using namespace std;

int n, m, arr[1001][1001], ans = -1;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

queue<pair<int, int>> q;

void bfs() {
    while (!q.empty()) {
        int xx=  q.front().first;
        int yy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            if (ny >= 0 && nx >= 0 && nx < n && ny < m && arr[nx][ny] == 0) {
                arr[nx][ny] = arr[xx][yy] + 1;
                q.push(make_pair(nx, ny));                  
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(nullptr);

    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                q.push(make_pair(i, j));
            }
        }
    }

    bfs();

	// 이해를 돕기위한 arr배열 출력 코드 
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //        cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                cout << -1;
                return 0;
            }else {
                ans = max(arr[i][j], ans);
            }
        }
    }

    cout << ans-1;
    return 0;
}