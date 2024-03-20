#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl '\n'
using namespace std;
int N, M;
vector<int> edges[1001];
bool visited[1001];
void init() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        edges[from].push_back(to);
        edges[to].push_back(from);
    }
}
void bfs(int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : edges[cur]) {
            if (visited[next]) continue;
            visited[next] = true;
            q.push(next);
        }
    }
}

int main(void) {
    init();
    int ans = 0;
    for (int cur = 1; cur <= N; cur++) {
        if (visited[cur]) continue;
        bfs(cur);
    }

    cout << ans << endl;
    return 0;
}