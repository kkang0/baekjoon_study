// 2630: 색종이 만들기
#include <iostream>
using namespace std;
int N, arr[128][128];
int white, blue = 0;

void f(int y1, int y2, int x1, int x2) {
    bool w = true, b = true;
    for(int y = y1; y <= y2; y++) {
        for(int x = x1; x <= x2; x++) {
            if(arr[y][x] != 0) w = false;
            if(arr[y][x] != 1) b = false;
        }
    }

    if (w) {
        white += 1;
        return;
    }
    if (b) {
        blue += 1;
        return;
    }

    int ym = (y1 + y2) / 2, xm = (x1 + x2) / 2;
    f(y1, ym, x1, xm);
    f(y1, ym, xm + 1, x2);
    f(ym + 1, y2, x1, xm);
    f(ym + 1, y2, xm + 1, x2);
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    f(0, N - 1, 0, N - 1);

    cout << white << '\n';
    cout << blue << '\n';

    return 0;
}