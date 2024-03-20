#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

int N;
vector<int> matrix[101];
bool visited[101];

void init() {
    cin >> N;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            int u;
            cin >> u;

            if(u == 1) {
                matrix[i].push_back(j);
            }
        }
    }
}

void reset() {
    for(int i = 1; i <= N; i++) {
        visited[i] = false;
    }
}

void dfs(int cur) {
    for(int next : matrix[cur]) {
        if(visited[next]) continue;
        visited[next] = true;
        dfs(next);
    }
}


int main(void) {
    init();

    for(int i = 1; i <= N; i++) {
        dfs(i);

        for(int j = 1; j <= N; j++) {
            cout << visited[j] << " ";
        }
        cout << endl;
        reset();
    }

    return 0;
}