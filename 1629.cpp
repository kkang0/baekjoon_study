#include <iostream>
using namespace std;

long long f(long long a, long long b, long long c) {
    if (b == 0)
        return 1;
    if (b % 2 == 0) {
        long long res = f(a, b/2, c);
        return res * res % c;
    }
    else {
        return f(a, b -1, c) * a % c;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b, c;
    cin >> a >> b >> c;

    cout << f(a, b, c);
}