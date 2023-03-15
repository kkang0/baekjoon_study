// 색종이 만들기
#include <iostream>
using namespace std;

int a[130][130];

int ans0 = 0, ans1 = 0;
void f(int y1, int y2, int x1, int x2) {
    bool c0 = true, c1 = true;
    for(int y = y1; y <= y2; y++) {
        for(int x = x1; x <= x2; x++) {
            if (a[y][x] != 0)
                c0 = false;
            if (a[y][x] != 1)
                c1 = false;
        }
    }
    
    if (c0) {
        ans0 += 1;
        return;
    }
    if (c1) {
        ans1 += 1;
        return;
    }
    int ym = (y1 + y2)/2, xm = (x1 + x2)/2;
    f(y1, ym, x1, xm);
    f(y1, ym, xm+1, x2);
    f(ym+1, y2, x1, xm);
    f(ym+1, y2, xm+1, x2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    f(0, n-1, 0, n-1);

    cout << ans0 << '\n';
    cout << ans1 << '\n';

    return 0;
}