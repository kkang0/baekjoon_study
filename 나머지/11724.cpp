#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
int N, M;
vector<int> edges[1001];
int matrix[1001][1001];
bool visited[1001];

void init(){
    cin >> N >> M;

    for(int i = 1; i <= M; i++){
        int u, v;
        cin >> u >> v;
        
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
}

void dfs(int cur){
    for (int next : edges[cur]) {
        if (visited[next]) continue;
        visited[next] = true;
        dfs(next);
    }
}
void printvisit() {
    for (int i = 1; i <= N; i++) {
        cout << visited[i] << ' ';
    }
    cout << endl;
}

int main(void){
    init();

    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        // cout << "i: " << i << endl;
        count++;
        dfs(i);
        // printvisit();
    }

    cout << count << endl;

    return 0;
}