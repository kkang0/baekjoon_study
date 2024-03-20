// 2869: 달팽이는 올라가고 싶다
#include <iostream>
using namespace std;

int main() {
    int A, B, V, length;
    cin >> A >> B >> V;

    length = ((V - A) / (A - B)) + 1;
    if((V - A) % (A - B) == 0) cout << length << endl;
    else cout << length + 1 << endl;

    return 0;
} 