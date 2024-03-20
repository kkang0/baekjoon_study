#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;

int N, M, V;
int board[1001][1001];
bool visited[1001];
queue<int> q;

void init() {
    cin >> N >> M >> V;

    for(int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;

        board[u][v] = 1;
        board[v][u] = 1;
    }
}

void reset() {
    for (int i = 1; i <= N; i++) {
        visited[i] = 0;
    }
}

void dfs(int start) {
    visited[start] = true;
    cout << start << ' ';

    for (int i = 1; i <= N; i++) {
        if(board[V][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

void bfs(int node) {
    q.push(node);
    visited[node] = true;
    cout << node << ' ';

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int k = 1; k <= N; k++) {
            if (board[cur][k] == 1 && visited[k] == 0) {
                q.push(k);
                visited[k] = true;
                cout << k << ' ';
            }
        }
    }
}

int main(void) {
    init();

    dfs(V);

    cout << endl;
    reset();
    
    bfs(V);

    return 0;
}