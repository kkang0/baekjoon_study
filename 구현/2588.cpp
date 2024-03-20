// 2588: 곱셈
#include <iostream>
using namespace std;
int A, B;

void init() {
    cin >> A;
    cin >> B;
}

int main() {
    init();

    cout << A * (B % 10) << endl;
    cout << A * ((B % 100) / 10) << endl;
    cout << A * (B / 100) << endl;
    cout << A * B << endl;
}