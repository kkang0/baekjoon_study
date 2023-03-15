#include <iostream>
using namespace std;

int P[9], N;
bool chk[9];
void f(int index) {
    if (index == N) {
        for (int i = 0; i < N; i++) {cout << P[i] << ' '; } {
            cout << '\n';
            return;
        }
    }
    for (int x = 1; x <= N; x++) {
        if (chk[x]) { continue; }
        chk[x] = 1; P[index] = x;
        f(index+1);
        chk[x] = 0; P[index] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    f(0);
    return 0;
}