// DFS와 BFS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> edges[1005];

bool vis[1005] = { 0, };

void dfs(int cur) {
    if (vis[cur]) return;
    vis[cur] = 1;   // already visited
    cout << cur << ' ';     // print visited
    for (int& nxt: edges[cur]) {    // vector의 cur에 속하는 모든 정점 방문
        if (vis[nxt])
            continue;
        dfs(nxt);
    }
}

void bfs(int start) {
    for (int i = 0; i <= 1000; ++i) {
        vis[i] = 0;
    }
    queue<int> q;

    vis[start] = 1;
    q.push(start);

    while (!q.empty()) {
        int cur = q.front();
        cout << cur << ' ';
        q.pop();

        for(int& nxt: edges[cur]) {
            if (vis[nxt])
                continue;
            vis[nxt] = true;
            q.push(nxt);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M, V, u, v;
    cin >> N >> M >> V;

    for(int i = 0; i < M; i++) {
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        sort(edges[i].begin(), edges[i].end());
    }

    dfs(V);
    cout << '\n';
    bfs(V);
    
    return 0;
}