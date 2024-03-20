#include <iostream>
#include <queue>
#include <vector>
#define endl '\n'
using namespace std;

int N, M;
vector<int> edges[5000];
bool visited[101];

void init() {
    cin >> N;
    cin >> M;

    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;

        edges[from].push_back(to);
        edges[to].push_back(from);
    }
}

int bfs(int start) {
    int ans = 0;
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        ans++;

        for (int next : edges[cur]) {
            if (visited[next]) continue;
            visited[next] = true;
            q.push(next);
        }
    }

    return ans;
}

int main(void) {
    init();
    int result;
    
    result = bfs(1);

    cout << result - 1 << endl;

    return 0;
}