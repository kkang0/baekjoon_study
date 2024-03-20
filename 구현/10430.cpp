// 10430: 나머지
#include <iostream>
using namespace std;

int A, B, C;

void init() {
    cin >> A >> B >> C;
}

int main() {
    init();

    cout << (A + B) % C << endl;
    cout << ((A % C) + (B % C)) % C << endl;
    cout << (A * B) % C << endl;
    cout << ((A % C) * (B % C)) % C << endl;

    return 0;
}