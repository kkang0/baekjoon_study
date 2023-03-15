#include <iostream>
using namespace std;

int result[3];
int a[2200][2200];
int index0 = 0, index1 = 0, index2  =0;

void f(int x, int y, int size) {
    bool flag = true;

    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (a[x][y] != a[i][j]) {
                flag = false;
                break;
            }
        }
    }

    if (flag) {
        result[a[x][y] + 1]++;
    }
    else {
        for(int i = x; i < x + size; i += size/3) {
            for(int j = y; j < y + size; j += size/3) {
                f(i, j, size/3);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;

    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }

    f(0, 0, N);

    for(int i = 0; i < 3; i++) {
        cout << result[i] << '\n';
    }

    return 0;
}