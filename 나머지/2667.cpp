#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
int N;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int board[26][26];
bool visited[26][26];

void init() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= N; j++) {
            board[i][j] = s[j - 1] - '0';
        }
    }
}

void printboard() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

int bfs(int sx, int sy) {
    int ret = 0;
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        ret++;
        
        for(int k = 0; k < 4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(nx < 1 || ny < 1 || nx > N || ny > N) continue;
            if(visited[nx][ny]) continue;
            if(board[nx][ny] == 0) continue;
            q.push({nx, ny});
            visited[nx][ny] = true;

        }
    }
    return ret; 
}

int main(void) {
    init();
    // printboard();
    vector<int> ans;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(visited[i][j]) continue;
            if(board[i][j] == 0) continue;
            int count = bfs(i, j);
            ans.push_back(count);
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }


    return 0;
}