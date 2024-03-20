// 11021: A + B - 7
#include <iostream>
using namespace std;
int T, A, B;
int result[10000];

void init() {
    cin >> T;

    for(int i = 0; i < T; i++) {
        cin >> A >> B;
        result[i] = A + B;
    }
}

int main() {
    init();

    for(int i = 0; i < T; i++) {
        cout << "Case #" << (i + 1) << ": " << result[i] << "\n";
    }
    
    return 0;
}